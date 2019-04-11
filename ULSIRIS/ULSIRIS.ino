#include <Servo.h>
#include "SparkFun_AS7265X.h"
#include "Adafruit_VL53L0X.h"

//Distance sensor
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
//Triad Spectral sensor
AS7265X sensor;

//horizontal and vertical control servos
Servo h_servo;
Servo v_servo;
//horizontal and vertical sweep positions
int h_pos = 0;
int v_pos = 0;

void setup() {
  // put your setup code here, to run once:
  h_servo.attach(9);
  v_servo.attach(8);
  Serial.begin(9600);

  //launch spectral sensor
   if(sensor.begin() == false)
  {
    Serial.println("Sensor does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }
  //launch distance sensor  
   if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
    }
  
  Serial.println("A,B,C,D,E,F,G,H,I,J,K,L,R,S,T,U,V,W");
}

void loop() {
  //reset servo positions to 0
  h_pos = 0;
  v_pos = 0;
  v_servo.write(0);
  h_servo.write(0);
  // put your main code here, to run repeatedly:
  // ----Loop 1 from v_rotation 0 to 45
  while(v_pos < 45){

    // ----Loop 2 from h_rotation 0 to 180
    for(h_pos = 0; h_pos < 180; h_pos += 18){
      //rotate (starts at 0) right(+) 10 degrees
      h_servo.write(h_pos);
      delay(15);
      // ----Get distance
      VL53L0X_RangingMeasurementData_t measure;
      Serial.print("Reading a measurement... ");
      lox.rangingTest(&measure, false);
      if (measure.RangeStatus != 4) {  // phase failures have incorrect data
        Serial.print("Distance (mm): "); 
        Serial.println(measure.RangeMilliMeter);
      } else {
        Serial.println(" out of range ");
      } 
      // ----Get spectral data
      sensor.takeMeasurements();
      Serial.print(sensor.getCalibratedA());
      Serial.print(",");
      Serial.print(sensor.getCalibratedB());
      Serial.print(",");
      Serial.print(sensor.getCalibratedC());
      Serial.print(",");
      Serial.print(sensor.getCalibratedD());
      Serial.print(",");
      Serial.print(sensor.getCalibratedE());
      Serial.print(",");
      Serial.print(sensor.getCalibratedF());
      Serial.print(",");
    
      Serial.print(sensor.getCalibratedG());
      Serial.print(",");
      Serial.print(sensor.getCalibratedH());
      Serial.print(",");
      Serial.print(sensor.getCalibratedI());
      Serial.print(",");
      Serial.print(sensor.getCalibratedJ());
      Serial.print(",");
      Serial.print(sensor.getCalibratedK());
      Serial.print(",");
      Serial.print(sensor.getCalibratedL());
      Serial.print(",");
    
      Serial.print(sensor.getCalibratedR());
      Serial.print(",");
      Serial.print(sensor.getCalibratedS());
      Serial.print(",");
      Serial.print(sensor.getCalibratedT());
      Serial.print(",");
      Serial.print(sensor.getCalibratedU());
      Serial.print(",");
      Serial.print(sensor.getCalibratedV());
      Serial.print(",");
      Serial.print(sensor.getCalibratedW());
      Serial.print(",");
    
      Serial.println();
      
    }
    // ----Loop 2 END
    
    // ----tilt up 5 degrees
    v_pos += 9;
    v_servo.write(v_pos);
    delay(15); 

   // ----Loop 2 from h_rotation 180 to 0
    for(h_pos = 180; h_pos > 0; h_pos -= 18){
      // ----rotate (starting from 180) left(-) 10 degrees
      h_servo.write(h_pos);
      delay(15);
      
      // ----Get distance
      VL53L0X_RangingMeasurementData_t measure;
      Serial.print("Reading a measurement... ");
      lox.rangingTest(&measure, false);
      if (measure.RangeStatus != 4) {  // phase failures have incorrect data
        Serial.print("Distance (mm): "); 
        Serial.println(measure.RangeMilliMeter);
      } else {
        Serial.println(" out of range ");
      } 
      // ----Get spectral data
      sensor.takeMeasurements(); 
      Serial.print(sensor.getCalibratedA());
      Serial.print(",");
      Serial.print(sensor.getCalibratedB());
      Serial.print(",");
      Serial.print(sensor.getCalibratedC());
      Serial.print(",");
      Serial.print(sensor.getCalibratedD());
      Serial.print(",");
      Serial.print(sensor.getCalibratedE());
      Serial.print(",");
      Serial.print(sensor.getCalibratedF());
      Serial.print(",");
    
      Serial.print(sensor.getCalibratedG());
      Serial.print(",");
      Serial.print(sensor.getCalibratedH());
      Serial.print(",");
      Serial.print(sensor.getCalibratedI());
      Serial.print(",");
      Serial.print(sensor.getCalibratedJ());
      Serial.print(",");
      Serial.print(sensor.getCalibratedK());
      Serial.print(",");
      Serial.print(sensor.getCalibratedL());
      Serial.print(",");
    
      Serial.print(sensor.getCalibratedR());
      Serial.print(",");
      Serial.print(sensor.getCalibratedS());
      Serial.print(",");
      Serial.print(sensor.getCalibratedT());
      Serial.print(",");
      Serial.print(sensor.getCalibratedU());
      Serial.print(",");
      Serial.print(sensor.getCalibratedV());
      Serial.print(",");
      Serial.print(sensor.getCalibratedW());
      Serial.print(",");
    
      Serial.println();
    }
    // ----Loop 2 END
    
    // ----tilt up 10 degrees
    v_pos += 9;
    v_servo.write(v_pos);
    delay(15); 
  }
  // ----Loop 1 END
}
