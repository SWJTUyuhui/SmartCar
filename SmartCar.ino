/*
buletooth car 
This sketch is written for buletooth car.The version 1.0 was created on 28 October 2015.

Components:
arduino UNO board
motor driver shield
bluetooth shield

 Circuit:
 * motor1/2 speed attached to digital pin 5
 * motor1/2 direction attached to digital pin 4
 * motor3/4 speed attached to digital pin 6
 * motor3/4 direction attached to digital pin 7
 * bluetooth shield  attached to pins 0(RX), 1(TX)
 
 created 28 October 2015
 by Yu Hui
*/
String command;
char charreceive;
int mark,flag,len;
//小电机请将数值调小
int speed1=50;//小车速度控制0~255，数值越大，速度越快
int pwm1 = 5;
int pwm2 = 6;
int dir1 = 4;
int dir2 = 7;

void goforward();
void goleft();
void goright();
void goback();
void stopcommand();
void moto31();//motor3 rotation
void moto32();//motor3 rollback
void moto41();//motor4 rotation
void moto42();//motor4 rollback
void moto51();//motor4 rotation
void moto52();//motor4 rollback
void moto6();//motor5 

void setup() {
  // put your setup code here, to run once: 
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
   digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
   digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
   //闪三次灯，表示程序开始运行
  Serial.begin(9600);
  Serial.println("Xmaker_Car begin...");
  delay(500);

 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(Serial.available())
   {
     charreceive=char(Serial.read());
     command+=charreceive;
    delay(2);
    mark=1;
   }

    if (mark == 1) {
      Serial.println("get:"+command);
      len=command.length();
      delayMicroseconds(10);
      if(charreceive=='8')goforward();
      if(charreceive=='4')goleft();
      if(charreceive=='6')goright();
      if(charreceive=='2')goback();
      if(charreceive=='5')stopcommand();
      charreceive=' ';
      command="";
    }

}
void goforward(){
 digitalWrite(dir1,0);
 digitalWrite(dir2,0);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goback(){
 digitalWrite(dir1,1);
 digitalWrite(dir2,1);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goleft(){
 digitalWrite(dir1,0);
 digitalWrite(dir2,1);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goright(){
 digitalWrite(dir1,1);
 digitalWrite(dir2,0);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}

void stopcommand(){
 analogWrite(pwm1,0);
 analogWrite(pwm2,0);
}


