#define ping_Pin 13
#define echo_Pin 12

#include <Servo.h> 


#define Servo_Pin 1
Servo s;
int done = 1;
void setup() {
 
    pinMode(echo_Pin, INPUT);
    pinMode(ping_Pin, OUTPUT);
    pinMode(led_Pin, OUTPUT);
    pinMode(Servo_Pin, OUTPUT); //Set servo pin to be an output
    s.attach(Servo_Pin);//attaches servo "s" to the correct pin
    s.write(0);
    delay(500);
}

void loop() {
  //---Will make this block of code one "Distance" function---
  long duration, distance;
  
   digitalWrite(ping_Pin, LOW);
   delay(500);
   digitalWrite(ping_Pin, HIGH);
   delay(500);
   digitalWrite(ping_Pin, LOW);
   
   duration = pulseIn(echo_Pin, HIGH);
   distance = .0184*(duration)-.0624;

//---------------------------------------------------------------

   Serial.println(distance);

   //---Will turn this block into "Lock" function----------------
   if(distance > 10)
    done = 0;
  
  if (done == 0)
  {
    if(distance < 10)
    {
      delay(5000);
      for(int pos = 0; pos <= 180;pos++) //vary variable "pos" from 0 to 120
      {
        s.write(pos); // write current value of pos to servo
        delay(15);
      }

      done = 1;
    }
  }
  if (done == 1)
    s.write(0);

//------------------------------------------------------------------

}

