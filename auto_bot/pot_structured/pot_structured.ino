#include <PID_v1.h>

#define lm1 29
#define rm1 37
#define lm2 28
#define rm2 15
#define lmp 12
#define WHEEL_RADIUS 1.0
#define pi 3.14159265359
#define ERROR 0.01
#define LOOP_DELAY 15
#define AVERAGING_FACTOR 100.0
#define POT A0
#define PWM_MIN 30

class motor{

  
  public :
  
  double pwm_pid;
  double pos;
  double pos_t;
  double prev_pos;
  double vel;
  float init_val;
  float val;
  int t;
  int temp_t;
  boolean mission;
  double Kp ;
  double Ki ;
  double Kd ;
  double outputlimits;
  
  PID pot;
    
  void getpos();
  void getvel();
  void setmotor();
  void init_motor();
  void ask_mission();
  void perform_mission();
  void stopmotor();
  void display_params();
};

motor left;


char c;




void setup() {

  Serial.begin(115200);
  pinMode( lm1 , OUTPUT);
  pinMode( lm2 , OUTPUT);

  pinMode( rm1 , OUTPUT);
  pinMode( rm2 , OUTPUT);
 

  left.init_motor();
}


void loop() {

  if(!left.mission)
  {
    left.ask_mission();   
  }

  else
  {
    left.getpos();
    left.getvel();
    left.perform_mission();   
    left.display_params();
   
  }
  delay(LOOP_DELAY);  

  mission_control();

}

