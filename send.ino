#define Joy_switch 4  // Pin 4 connected to joystick switch
#define X_pin A0    // Pin A0 connected to joystick x axis

int step_speed = 10;  // Speed of Stepper motor (higher = slower)

void setup() 
{ 
  pinMode(Joy_switch, INPUT_PULLUP);
  Serial.begin(9600);
} 
 
void loop() {
  if (!digitalRead(Joy_switch)) {  //  If Joystick switch is clicked
    delay(500);  // delay for deboucing
    switch (step_speed) {  // check current value of step_speed and change it
      case 1:
        step_speed=10;  // slow speed
        break;
      case 3:
        step_speed=1;  // fast speed
        break;
      case 10:
        step_speed=3;  // medium speed
        break;
   
   Serial.write(step_speed);
   
    }
  }    

  
  int data= analogRead(0); 
  Serial.write(data); 
  delay(50);                           
} 
