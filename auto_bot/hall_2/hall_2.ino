#define hall_high A0
#define hall_low  A1
#define hall_input A2
#define m1 A3
#define m2 A4
#define mp 3

#define SAMPLE 5

// 50 & 80
// 
#define HPERIOD 60
#define LPERIOD 70

long long prevtime, halltimemin, halltimemax;
int hcurrread, hprevread;
int flag_min, flag_max;
boolean flag;

void setup() {

  Serial.begin(57600);
  pinMode(hall_high, OUTPUT);
  pinMode(hall_low, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);

  digitalWrite(hall_high, HIGH);
  digitalWrite(hall_low, LOW);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(mp, 255);

  hprevread = 0;
  hcurrread = 0;
  flag_min = 1;
  flag_max = 0;
  prevtime=0;

}
void loop()
{
  hcurrread = 0;
  for ( int i = 0; i < SAMPLE; i++ )
    hcurrread += analogRead(hall_input);
  hcurrread = hcurrread / SAMPLE *10.0* 5.0 / 1024.0;

  if (hcurrread > hprevread && flag_min == 0 && flag_max == 1) {
    halltimemin = millis();
    flag_min = 1;
    flag_max = 0;
//    Serial.print(" Min attained at : ");
    Serial.println(int(halltimemin-halltimemax));
  } else if (hcurrread < hprevread && flag_max == 0 && flag_min == 1) {
    halltimemax = millis();
    flag_min = 0;
    flag_max = 1;
//    Serial.print(" Max attained at : ");
    Serial.println(int(halltimemax-halltimemin));
  }
  hprevread = hcurrread;




  // The code to switch on.off magnet
  if (millis() - prevtime > LPERIOD && flag==0)
  {
    digitalWrite(m1, HIGH);
    flag=1;
    prevtime=millis();
    
  }
  else if (millis() - prevtime > HPERIOD && flag==1)
  {
    digitalWrite(m1, LOW);
    flag=0;
    prevtime = millis();
  }

}
