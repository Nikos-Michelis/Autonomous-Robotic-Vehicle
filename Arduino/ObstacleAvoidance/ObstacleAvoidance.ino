#include <AFMotor.h>
#include <Servo.h>

#define trig_Pin A0
#define echo_Pin A1
#define RIGHT A3
#define LEFT A2
#define MAX_SPEED 100 
#define MAX_SPEED_OFFSET 20

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo myservo;

boolean goesForward = false;
int distance = 100;
int speedSet = 0;
int Time = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(50);
  pinMode(trig_Pin, OUTPUT);
  pinMode(echo_Pin, INPUT);
  delay(2000);
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
}

void loop()
{
  myservo.write(70);
  distance = obstacle();
  Serial.println(distance);
  int distanceR = 0;
  int distanceL = 0;
  delay(40);
  
  int Right_Value = digitalRead(RIGHT);
  int Left_Value = digitalRead(LEFT);
  
  Serial.print("RIGHT");
  Serial.println(Right_Value);
  Serial.print("LEFT");
  Serial.println(Left_Value);
  
   if((Right_Value==1)&&(Left_Value==1)){      
    moveForward();
  }else if ((Right_Value==0) && (Left_Value==1)){
    
       moveBackward();
       delay(300);
       moveStop();
       delay(100);
       turnRight();
       delay(600);
       
  }else if((Right_Value==1) && (Left_Value==0)){
        moveBackward();
        delay(300);
        moveStop();
        delay(100);
        turnLeft();
        delay(600);
  }else if((Right_Value==0)&&(Left_Value==0)){
     if (distance <= 15){
       moveStop();
       delay(100);
       moveBackward();
       delay(600);
       moveStop();
       delay(200);
       distanceR = lookRight();
       delay(200);
       distanceL = lookLeft();
       delay(200);
        if (distanceR >= distanceL){
                turnRight();
                moveStop();
              } else{
                turnLeft();
                moveStop();
              }
     }else{
       moveForward();
     }
  }
  if (distance <= 15){
    moveStop();
    delay(100);
    moveBackward();
    delay(600);
    moveStop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);
    if (distanceR >= distanceL){
      turnRight();
      moveStop();
    }else{ 
      turnLeft();
      moveStop();
    }
  }else{
    moveForward();
  }
}
int obstacle(){
  digitalWrite(trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_Pin, LOW);
  Time = pulseIn(echo_Pin, HIGH);
  distance = (Time / 29.1) / 2;
  if (distance < 0)
    distance = 0;
  if (distance > 200)
    distance = 200;
  return distance;
}
int lookRight(){
  myservo.write(-170);
  delay(500);
  distance = obstacle();
  delay(200);
  myservo.write(70);
  return distance;
}
int lookLeft(){
  myservo.write(150);
  delay(500);
  distance = obstacle();
  delay(200);
  myservo.write(70);
  return distance;
}
void moveStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void moveForward() {
  if (!goesForward)
  {
    goesForward = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 10)
    {
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      motor3.setSpeed(speedSet);
      motor4.setSpeed(speedSet);
      delay(5);
    }
  }
}
void moveBackward() {
  goesForward = false;
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 10)
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}
void turnRight() {  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(1000);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1000);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
