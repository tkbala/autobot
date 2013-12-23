#define m1 28
#define m2 29
char a;
void setup() {
  pinMode(m1, OUTPUT); 
  pinMode(m2, OUTPUT); 
  pinMode(12, OUTPUT); 
  Serial.begin(115200);
  analogWrite(12,30);
}

void loop() {

  if(Serial.available())
  {
    a= Serial.read();

    if(a=='A')

    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,LOW);
      Serial.println("a"); 

    } 

    else if (a=='S'){

      digitalWrite(m1,LOW);
      digitalWrite(m2,HIGH); 
      Serial.println("s");
    } 
    else if (a=='D'){
      
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW); 
      Serial.println("d");
    } 
    else {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,HIGH); 
    } 

  }

}


