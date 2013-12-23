void motor::display_params()
{

  Serial.print("\tLeft Position is : ");
  Serial.print(pos, 5);

  Serial.print("\tLeft velocity is : ");

  Serial.println(vel, 5);
}

void motor::ask_mission()
{
  Serial.println("Enter target for the left motor position : ");
  while(!Serial.available());
  pos_t=Serial.parseFloat();
  mission=1; 
}

void motor::perform_mission()
{
  pot.Compute();
  if( ERROR>(pos_t-pos) && (pos_t-pos)>(-ERROR))
  {
    stopmotor();
    mission=0;
    Serial.println("Left Motor Mission Completed...");
  }

  else{
    setmotor();
  }
  
  prev_pos=pos;

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
      left.stopmotor();
      left.mission=0;       
    }
  }
}

