
void motor::init_motor()
{
  init_val = 0;
  mission = 0;
  Kp = 60.0;
  Ki = 0;
  Kd = 0;
  outputlimits=60;
  pot.SetPID(&pos, &pwm_pid, &pos_t, Kp, Ki, Kd, DIRECT);
  
  pot.SetTunings(Kp, Ki, Kd);
  pot.SetOutputLimits(-outputlimits, outputlimits);
  pot.SetMode(AUTOMATIC);
  
  for( int i = 0; i< AVERAGING_FACTOR  ; i++)
  {
    init_val+=analogRead(POT);
  }
  init_val /= AVERAGING_FACTOR;
  Serial.print("Initial Voltage Value : ");
  Serial.println(init_val/102.4);
}

void motor::setmotor()
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



void motor::getpos()
{
  for( int i = 0; i< AVERAGING_FACTOR  ; i++)
  {
    val+=analogRead(POT);
  }
  val/=AVERAGING_FACTOR;
  t=millis()-temp_t;
  temp_t=millis();
  //  pos_l= (val/1024)*2*PI*WHEEL_RADIUS;
  pos= (val-init_val)*10.0/1024;
}
void motor::getvel()
{
  vel=(pos-prev_pos)/t;
}


void motor::stopmotor()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  analogWrite(lmp, 255);
  

}

