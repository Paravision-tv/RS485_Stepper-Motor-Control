
//Joystick and Speed Master (Arduino Leonardo)

//Serial Communication Between Arduino using RS-485

#define Joy_switch 5  // Pin 5 connected to joystick switch
#define enablePin  4  // Connected to RS485 Enable pin
#define joy       A0  // Joystick pin Value
#define Green     11  // Test LED Green
#define Red       12  // Test LED Red
#define LED       13  // Board LED pin 13

int step_speed = 10;  // Speed of Stepper motor (higher = slower)
int pushval = 512;

void setup() 
{ 
  pinMode(Joy_switch, INPUT_PULLUP);  
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(pushval,INPUT);
   
  digitalWrite(enablePin, HIGH);  //  (always high as Master Writes data to Slave)
  
  Serial1.begin(9600);            // initialize serial at baudrate 9600:
  
  } 
 
void loop() {   
    //pushval = 512;
    pushval = analogRead(joy);  // read the input pin A0
    
    Serial1.println(pushval);
   
  }
  
 



  
