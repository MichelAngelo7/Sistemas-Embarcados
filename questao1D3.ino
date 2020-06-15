/**
 * Faça um programa para Arduino que controle um motor de passo.
 * O acionamentodo motor de passo é  feito  por  um comandobimanual.  
 * Ou  seja,  após  os  botões  1  e  2  serem  pressionadosao  mesmo tempo 
 * o motor de passo devedar 10 voltas completas no sentido horário. 
 * No próximo acionamento bimanual o motor de passo deve retornar as 10 voltas, 
 * ou seja, girar 10 voltas no sentido anti-horário. 
 * Utilizeas portas abaixo: 
 * Botão1-8
 * Botão2-9
 * Motor de passo p1-2
 * Motor de passo p2-3
 * Motor de passo p3-4
 * Motor de passo p4-5
 * 
 * */

//incluir a biblioteca de controle do motor
#include <Stepper.h>
//definições das variaveis
const int passos = 200, botao1 = 8, botao2 = 9;
volatile int estado = 0;

//iniciar o motor utilizando a biblioteca nos pinos 2 a 5
Stepper motor(passos, 2, 3, 4, 5);

void setup()
{

  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);

  motor.setSpeed(60);
}

void loop()
{

  if (digitalRead(botao1) == 1 && digitalRead(botao2) == 1 && estado == 0)
  {
    for (int i = 0; i < 10; i++)
    {
      motor.step(passos);
    }
    estado = 1;
  }

  if (digitalRead(botao1) == 1 && digitalRead(botao2) == 1 && estado == 1)
  {
    for (int i = 0; i < 10; i++)
    {
      motor.step(-passos);
    }
    estado = 0;
  }
}