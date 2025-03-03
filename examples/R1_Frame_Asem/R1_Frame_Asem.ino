// define l298n pin
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define SPEED 10
#define DELAYTIME 500

void config_L298_pin();
void motor_A_quaythuan(int speed);
void motor_A_quaynghich(int speed);
void motor_B_quaythuan(int speed);
void motor_B_quaynghich(int speed);
void chaytoi(int speed);
void chaylui(int speed);
void xoaytrai(int speed);
void xoayphai(int speed);
void dunglai();

void setup() {
  // put your setup code here, to run once:
  config_L298_pin();
  chaytoi(SPEED);
  delay(DELAYTIME);
  dunglai();
  delay(DELAYTIME);
  chaylui(SPEED);
  delay(DELAYTIME);
  dunglai();
  delay(DELAYTIME);
  xoaytrai(SPEED);
  delay(DELAYTIME);
  dunglai();
  delay(DELAYTIME);
  xoayphai(SPEED);
  delay(DELAYTIME);
  dunglai();
} 

void loop() {
  // put your main code here, to run repeatedly:
}

void config_L298_pin() {
  for (int i = 0; i < 4; i++)
    pinMode(i + 4, OUTPUT);
}

void motor_A_quaythuan(int speed) {
  analogWrite(IN1, speed * 255);
  digitalWrite(IN2, LOW);
}

void motor_A_quaynghich(int speed) {
  analogWrite(IN2, speed * 255);
  digitalWrite(IN1, LOW);
}

void motor_B_quaythuan(int speed) {
  analogWrite(IN3, speed * 255);
  digitalWrite(IN4, LOW);
}

void motor_B_quaynghich(int speed) {
  analogWrite(IN4, speed * 255);
  digitalWrite(IN3, LOW);
}

void chaytoi(int speed) {
  motor_A_quaythuan(speed);
  motor_B_quaythuan(speed);
}

void chaylui(int speed) {
  motor_A_quaynghich(speed);
  motor_B_quaynghich(speed);
}

void xoaytrai(int speed) {
  motor_A_quaynghich(speed);
  motor_B_quaythuan(speed);
}

void xoayphai(int speed) {
  motor_A_quaythuan(speed);
  motor_B_quaynghich(speed);
}
void dunglai()
{
  for (int i = 0; i < 4; i++)
    digitalWrite(i + 4, LOW);
}