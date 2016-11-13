// by subhajit sinha and mathew kurian



#include<Servo.h>
#include<SoftwareSerial.h>
char C;
int in1 = 4;
int in2 = 5;
String blue;
Servo s;
SoftwareSerial bt(10,11);
void setup() 
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  s.attach(8);
  Serial.begin(9600);
  bt.begin(9600);
}
void loop() 
{
  delay(100);
  while(bt.available()>0 )
  {
    C=char(bt.read());
    blue+=C;
  }     
    if(blue.length() >0)  
    {
      
      if(blue == "60")
      {
        Serial.println(blue);
        Serial.println("STRAIGHT");
        s.write(60);
        blue = "";
      }
      else if (blue == "90")
      {
        Serial.println(blue);
        Serial.println("");
        s.write(90);
        blue = "";  
      }
      else if (blue == "30")
      {
         Serial.println(blue);      
         Serial.println("");
         s.write(30);
         blue = ""; 
      }
      else if (blue == "15")
      {
         Serial.println(blue);
         Serial.println("");      
         s.write(15);
         blue = ""; 
      }
      else if (blue == "fwd")
      {
        Serial.println("Forward");
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        delay(1000);
        blue = "";
      }
      else if (blue == "bkwd")
      {
        Serial.println("Backward");
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        delay(1000);
        blue = "";
      }
      else if( blue == "STOP")
      {
        Serial.println("STOP");
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        delay(1000);
        blue = "";
      }
      else
      {
        Serial.println("NOT READ");
        blue= "";
      }
    }
}
