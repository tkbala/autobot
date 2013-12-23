void display_params()
{

  Serial.print("\tLeft Position is : ");
  Serial.print(pos_l, 5);

  Serial.print("\tLeft velocity is : ");

  Serial.println(vel_l, 5);
}

void ask_mission()
{
  Serial.println("Enter target for the left motor position : ");
  while(!Serial.available());
  pos_lt=Serial.parseFloat();
  mission=1; 
}

void perform_mission()
{
  potl.Compute();
  if( ERROR>(pos_lt-pos_l) && (pos_lt-pos_l)>(-ERROR))
  {
    stopmotor();
    mission=0;
    Serial.println("Left Motor Mission Completed...");
  }

  else{
    setmotorleft();
  }

}

void mission_control()
{

  if(Serial.available())
  {
    c = Serial.read();
    Serial.println(c);
    if(c=='q')
    {
      Serial.println("Emergency Stop");
      stopmotor();
      mission=0;       

    }

    else if(c=='a')
    {
      pwmv/=2;
    }
    else if(c=='s')
    {
      pwmv*=2;
    }
  }

}

