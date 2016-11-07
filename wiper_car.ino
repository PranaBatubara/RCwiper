#include <SoftwareSerial.h>
#include <Servo.h>


const int pwm = 2 ;  //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;
SoftwareSerial hc(12,13);// initializing the communication
//For providing logic to L298 IC to choose the direction of the DC motor 
int parameter;
Servo myservo;

void setup()
{
  hc.begin(57600);
myservo.attach(9);
pinMode(pwm,OUTPUT) ;   //we have to set PWM pin as output
pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
pinMode(in_2,OUTPUT) ;

}

void loop()
{
  if(hc.available())
  parameter = hc.read();
switch(parameter)
{
case 1:
  left();
  break;
case 2:
  right();
  break;
case 3:
  forward();
  break;
case 4:
  brake();
  break;
case 5:
  wipe();
  break;
default :
  break;
}
}

//For Clock wise motion , in_1 = High , in_2 = Low


void right()
{digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm,255) ;

/*setting pwm of the motor to 255
we can change the speed of rotaion
by chaning pwm input but we are only
using arduino so we are using higest
value to driver the motor  */

//Clockwise for 3 secs
delay(3000) ;     
}

//For brake
void brake()
{digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(1000) ;
}


void forward()
{digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
analogWrite(pwm,255) ;
delay(1000) ;
}


//For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH

void left()
{digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;
delay(3000) ;
}

void wipe()
{
  myservo.write(135);              // tell servo to go to position in variable 'pos'
    delay(15);
}

