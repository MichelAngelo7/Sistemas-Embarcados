/*
Sabe-se que o motor de passo possui um ângulo de passo de 0,72°, e que o passo 
do fuso de esferas é de 5mm, ou seja a cada volta completa que o fuso de esferas
dá, ele desloca a mesa 5 mm para direita ou para esquerda. A peça completa 
possui 3 furos conforme o desenho abaixo e a distância entre a posição inicial 
da mesa e o primeiro furo e de 30mm. Sabe-se que para dar uma volta completa 
o motor precisa de 500 pulsos.

*/

//inicia a variavel do motor de passo
#include <Stepper.h>
const int passos = 200, btn1 = 8, btn2 = 9 ;  //numero de passo que o motor vai dar

//inicia o motor utilizando a biblioteca no pino 8 a 11
Stepper myStepper(passos, 5, 4, 3, 2);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
	
	pinMode(btn1, INPUT);
	pinMode(btn2, INPUT);
	
	
	myStepper.setSpeed(60);
	
	Serial.begin(9600);
}

void loop() {
	
	if(digitalRead(btn1) == 1)
	{
		for(int i = 1; i<=6; i++ )
		{
			myStepper.step(passos);
		}
		delay(2000);
		for(int i = 1; i<=2; i++ )
		{
			myStepper.step(passos);
		}
		delay(3000);
		for(int i = 1; i<=3; i++ )
		{
			myStepper.step(passos);
		}
		myStepper.step((passos)/2);
		delay(3000);
	}
	if(digitalRead(btn2)==1)
	{
		for(int i = 1; i<=11; i++ )
		{
			myStepper.step(-passos);
		}
		myStepper.step((-passos)/2);
	}
	
	delay(1);
}