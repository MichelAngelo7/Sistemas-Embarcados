#include <Servo.h>

Servo servoMotor1;
Servo servoMotor2;


const int botao = 2, pinoServo1=3, pinoServo2=4, acionador=5 ;
int estado = 0, angulo=0, angulo2=0;


void setup()
{
  pinMode(acionador, INPUT);
  servoMotor1.attach(pinoServo1);
  servoMotor2.attach(pinoServo2);
  servoMotor1.write(0);
  servoMotor2.write(0);
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(botao), imprime, RISING);

}

void loop()
{
  if(digitalRead(acionador)==1)
  {
   while(estado==0 && angulo <= 180)
   {
    servoMotor1.write(angulo);
    angulo +=18;
    delay(500);
   }
   while(estado==0 && angulo >= 0)
   {
    servoMotor1.write(angulo);
    angulo -=18;
    delay(500);
   }
   delay(100);/////mudar
   while(estado==0 && angulo2 <= 180)
   {
  	servoMotor2.write(angulo2);
    angulo2 +=18;  
   }
   while(estado==0 && angulo <= 180)
   {
    servoMotor1.write(angulo);
    angulo +=18;
    delay(250);
   }
   while(estado==0 && angulo >= 0)
   {
    servoMotor1.write(angulo);
    angulo -=18;
    delay(250);
   }
   while(estado==0 && angulo2 >= 0)
   {
  	servoMotor2.write(angulo2);
    angulo2 -=18;  
   }
  } 
  else 
    Serial.println("Acionador desligado");  
}

void imprime()
{
  if(estado == estado)
  {
    estado = !estado;
  }
  Serial.print("Estado do botão de emegencia ");
  Serial.print(estado);

}