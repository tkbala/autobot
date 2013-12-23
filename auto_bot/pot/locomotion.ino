
void init_pot()
{
  init_val = 0;
  for( int i = 0; i< AVERAGING_FACTOR  ; i++)
  {
    init_val+=analogRead(POT);
  }
  init_val /= AVERAGING_FACTOR;
  Serial.print("Initial Voltage Value : ");
  Serial.println(init_val/102.4);
}

void setmotorleft()
{
  if(pwm_pid>0)
  {
    if(pwm_pid<PWM_MIN)
    {
        pwm_pid=PWM_MIN;
    }
    digitalWrite(lm1,HIGH);

    digitalWrite(lm2,LOW);
    analogWrite(lmp,pwm_pid);  
    Serial.print("Going left with pwm ");      
    Serial.print(pwm_pid);
    Serial.print("\t");        
  }
  else if (pwm_pid<0)
  {
    if(pwm_pid>-PWM_MIN)
    {
        pwm_pid=-PWM_MIN;
    }
    
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);

    analogWrite(lmp,-pwm_pid);
    Serial.print(" Going right with pwm ");
    Serial.print(-pwm_pid);      
    Serial.print("\t");    
  }
  else {
    stopmotor();
  }
}


void setmotorright()
{

}

void getposleft()
{
  for( int i = 0; i< AVERAGING_FACTOR  ; i++)
  {
    val+=analogRead(POT);
  }
  val/=AVERAGING_FACTOR;
  t=millis()-temp_t;
  temp_t=millis();
  //  pos_l= (val/1024)*2*PI*WHEEL_RADIUS;
  pos_l= (val-init_val)*10.0/1024;
  Serial.print(" Val : "
}
void getvelleft()
{
  vel_l=(pos_l-prev_pos_l)/t;
}


void stopmotor()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  analogWrite(lmp, 255);

}

