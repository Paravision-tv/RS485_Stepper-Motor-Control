#include <Stepper.h>

//Slave code (Arduino Leonardo)
//Serial Communication Between Two Arduinos using RS-485

#define step_pin 10  // Pin 10 connected to Steps pin on EasyDriver
#define dir_pin 9   // Pin 9 connected to Direction pin
#define MS1 8       // Pin 8 connected to MS1 pin
#define MS2 7       // Pin 7 connected to MS2 pin
#define SLEEP 6     // Pin 6 connected to SLEEP pin


#define Limit01 2  // Pin 2 connected to Limit switch out
#define Limit02 3  // Pin 3 connected to Limit switch out

int step_speed = 10;  // Speed of Stepper motor (higher = slower)

void setup() {
   pinMode(MS1, OUTPUT);
   pinMode(MS2, OUTPUT);
   pinMode(dir_pin, OUTPUT);
   pinMode(step_pin, OUTPUT);
   pinMode(SLEEP, OUTPUT);
   
   pinMode(Limit01, INPUT);
   pinMode(Limit01, INPUT);
   
   digitalWrite(SLEEP, HIGH);  // Wake up EasyDriver
   delay(5);  // Wait for EasyDriver wake up

   Serial.begin(9600); 
  
   
/* Configure type of Steps on EasyDriver:
// MS1 MS2
//
// LOW LOW = Full Step //
// HIGH LOW = Half Step //
// LOW HIGH = A quarter of Step //
// HIGH HIGH = An eighth of Step //
*/

   digitalWrite(MS1, LOW);      // Configures to Full Steps
   digitalWrite(MS2, LOW);    // Configures to Full Steps
}

void loop() {

 if (Serial.available()) {
    int step_speed = Serial.read();  
  
  
    }
    
    
   
   
  
    int data = Serial.read(); 
   if (data=>712) {  //  If joystick is moved Left
   
    if (!digitalRead(Limit01)) {}  // check if limit switch is activated
    
      else {  //  if limit switch is not activated, move motor clockwise
      
        digitalWrite(dir_pin, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
        digitalWrite(step_pin, HIGH);
        delay(step_speed);
        digitalWrite(step_pin, LOW);
        delay(step_speed);
    }      
  }
   int data = Serial.read();  
   if (data<312) {  //  If joystick is moved Left
   
    if (!digitalRead(Limit02)) {}  // check if limit switch is activated
    
      else {  //  if limit switch is not activated, move motor clockwise
      
        digitalWrite(dir_pin, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
        digitalWrite(step_pin, HIGH);
        delay(step_speed);
        digitalWrite(step_pin, LOW);
        delay(step_speed);
    }      
  }
}
