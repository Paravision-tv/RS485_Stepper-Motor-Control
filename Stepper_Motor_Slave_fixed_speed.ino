//Slave code (Arduino Uno)
//Serial Communication Between Two Arduinos using RS-485

#define step_pin 10   // Pin 10 connected to Steps pin on EasyDriver
#define dir_pin   9   // Pin 9 connected to Direction pin
#define MS1       8   // Pin 8 connected to MS1 pin
#define MS2       7   // Pin 7 connected to MS2 pin
#define SLEEP     6   // Pin 6 connected to SLEEP pin
#define LED      13   // Board LED pin
#define Green     11  // Test LED Green
#define Red       12  // Test LED Red
#define enablePin 4   // Connected to RS485 Enable pin
#define Limit01   2   // Pin 2 connected to Limit switch out
#define Limit02   3   // Pin 3 connected to Limit switch out


int step_speed = 10;  // Speed of Stepper motor (higher = slower)


void setup() {
   pinMode(LED, OUTPUT);            // Declare LED pin as output
   pinMode(MS1, OUTPUT);
   pinMode(MS2, OUTPUT);
   pinMode(dir_pin, OUTPUT);
   pinMode(step_pin, OUTPUT);
   pinMode(SLEEP, OUTPUT);
   pinMode(enablePin, OUTPUT);
   pinMode(Limit01, INPUT);
   pinMode(Limit01, INPUT);
   digitalWrite(enablePin, LOW);
   digitalWrite(SLEEP, HIGH);  // Wake up EasyDriver
   delay(5);  // Wait for EasyDriver wake up

   
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

   Serial.begin(9600); 
}

void loop()
{
  int step_speed = 1;
{
    if (Serial.available() > 0)
   
       right();

       
       left();
    }
    }


void right()
         {
          if (Serial.parseInt() > 712)         //  If joystick is moved Left
    if (!digitalRead(Limit02)) {}  // check if limit switch is activated
        

      else {  //  if limit switch is not activated, move motor clockwise
      
        digitalWrite(dir_pin, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
        digitalWrite(step_pin, HIGH);
        delay(step_speed);
        digitalWrite(step_pin, LOW);
        delay(step_speed);
        digitalWrite(Red, HIGH);
        digitalWrite(Green, LOW);
        
      }
         } 
         
void left()
        {
        if (Serial.parseInt() < 312)         //  If joystick is moved Left
    if (!digitalRead(Limit01)) {}  // check if limit switch is activated
        

      else {  //  if limit switch is not activated, move motor clockwise
      
        digitalWrite(dir_pin, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
        digitalWrite(step_pin, HIGH);
        delay(step_speed);
        digitalWrite(step_pin, LOW);
        delay(step_speed);
        digitalWrite(Red, LOW);
        digitalWrite(Green, HIGH);
        
      }      }
   
   
    
    
          

      
