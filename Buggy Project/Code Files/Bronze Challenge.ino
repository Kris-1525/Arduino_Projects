#include<NewPing.h>
NewPing sonar(13,12,200);
int a=0;
int b=0;
int c=0;
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
}

void loop() {

  //int a=0;
  int d=sonar.ping_cm();
  int ir1=digitalRead(A0);
  int ir2=digitalRead(A1);
  Serial.print(b,DEC);
  Serial.println();
  //delay(1000);
 // if(d<=20)
  //{
    //stopp();
 //}
   while(c==0 && ir1==0 && ir2==0)
  {
    a++;
    b=b+a;
    a=0;
    c=1;
    //forward();
  }

    if(ir1==1 && ir2==1)
  {
    forward();
    c=0;
    
    }
  else if(ir1==1 && ir2==0)
  {
    left();
    c=0;
  }
  else if(ir1==0 && ir2==1)
  {
    right();
    c=0;
  }

    else if(c==1 && ir1==0 && ir2==0)
  {
    forward();
  }
  while(b==8){
  if(ir1==0 && ir2==0)         //if this does not work then do this keep the elseif dtatement as it is and change the inner loop body by removing a and uncomenting the comented section                         
  {
    
    right();
   
    //break;                   
  }
  break;
  }
  
//  else if(a==4 && ir2==1 && ir1==0)
  //{
    //++a;
    //forward();
  //}
//   else if(a>=400 && a<=500 && ir1==0 && ir2==0)
//   {
//    ++a;
//    right();
//   }
   while(b==9 && ir1==0 && ir2==0)
   {
    stopp();
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
void stopp()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  
}

