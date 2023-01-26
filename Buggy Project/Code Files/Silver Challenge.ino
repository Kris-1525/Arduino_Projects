int counter=0;
int check;
#include<NewPing.h>
NewPing sonar(13,12,200);
int pulse_check=A2;
void setup() {
        Serial.begin(9600);
        int i;
        for(i=5;i<=8;i++)
        {
          pinMode(i,OUTPUT);
        }
       pinMode(13,OUTPUT);
       pinMode(12,INPUT);
       pinMode(A0,INPUT);
       pinMode(A1,INPUT);
       pinMode(pulse_check,INPUT);
    }
void loop() {
if(digitalRead(pulse_check)) {
    counter++;
    stop();      
  if (counter == 3) {
    Serial.write(1);
    while (Serial.read() != 2);}
    delay(2000);
    forward();
    delay(100);
}
normal();
}        
void normal()
{
int d=sonar.ping_cm();
int ir1=digitalRead(A0);
int ir2=digitalRead(A1);
if(ir1 && ir2)
forward();
else if(ir1 && !ir2)
left();
else if(!ir1 && ir2)
right();
else if(!ir1 && !ir2){
   if (counter==0)
       {right();
         delay(160);
         forward();}
   else if(counter<5)
         forward();
   else if(counter==5)
      {forward();
         right();
         delay(235);
         forward();
         delay(80);
         counter=6;}
   else if (counter==6)
      {counter=7;
         forward();}
   else if (counter==7)
      {stop();
       while(true);}
   }
}
void left()
       {
          digitalWrite(5,HIGH);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
       }
   void right()
       {
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,HIGH);
       }
   void forward()
       {
          digitalWrite(5,HIGH);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,HIGH);
       }
   void stop()
      {
         digitalWrite(5,LOW);
         digitalWrite(6,LOW);
         digitalWrite(7,LOW);
         digitalWrite(8,LOW);
        
      }

