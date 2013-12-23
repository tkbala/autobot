/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
int i=0;
int sensorValue=0;
int initsensorValue=0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  initsensorValue = analogRead(A0);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  

   sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float turns = (sensorValue-initsensorValue) / 102.3;
  
    if(Serial.available())
  {
      Serial.read();
      Serial.println(turns);      
  }  
  // print out the value you read:

  delay(100);
}
