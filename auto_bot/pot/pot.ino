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

double pos_l=0;
float pos_r=0;
float prev_pos_l=0;
float prev_pos_r=0;

float vel_l=0;

int rev_l=0;
int rev_r=0;

double pos_lt=10;
float pos_rt;
float val=0;
float init_val=0;

int t=1;
int temp_t=0;

int mission=0;

char c;
double pwmv = 0;
double pwm_pid = 0;

double Kp = 60.0;
double Ki = 0;
double Kd = 0;

PID potl(&pos_l, &pwm_pid, &pos_lt, Kp, Ki, Kd, DIRECT);


void setup() {

  Serial.begin(115200);
  pinMode( lm1 , OUTPUT);
  pinMode( lm2 , OUTPUT);

  pinMode( rm1 , OUTPUT);
  pinMode( rm2 , OUTPUT);
  potl.SetOutputLimits(-60, 60);
  potl.SetMode(AUTOMATIC);

  init_pot();
}


void loop() {

  if(!mission)
  {
    ask_mission();   
  }

  else
  {
    getposleft();
    getvelleft();
    perform_mission();   
    display_params();
    prev_pos_l=pos_l;
  }
  delay(LOOP_DELAY);  

  mission_control();

}

