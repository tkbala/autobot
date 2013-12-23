#define hall_high A0
#define hall_low  A1
#define hall_input A2
#define m1 A3
#define m2 A4
#define mp 3
#define DELAY 50
#define SAMPLE 100
float val=0;
int prev_time=0;
boolean flag;
void setup(){

  Serial.begin(57600);
  pinMode(hall_high,OUTPUT);
  pinMode(hall_low,OUTPUT);  
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);  

  digitalWrite(hall_high,HIGH);
  digitalWrite(hall_low,LOW);  
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);  
  analogWrite(mp,255);  
  prev_time=0;

}
void loop()
{


  
  
  val=0;
  for(int i=0;i<SAMPLE;i++)
  {
      val+=analogRead(hall_input);
  
  }
  val/=SAMPLE;
  
  Serial.print(val*5.0/1024.0);
    if(flag)
    {
      Serial.println("   < - HIGH  ");    
    }
    else{
    
  Serial.println("   < - LOW  ");      
    }
  
  if(millis()-prev_time > DELAY)
  {
    if(flag==1)
    {
       digitalWrite(m1,LOW);      
       flag=0;
    }
    else
    {
       digitalWrite(m1,HIGH);  
       flag=1;
    }  
      
   prev_time=millis();
  
  }
  
}
