/**
 * Faça um programa para Arduino que apresentena comunicação serial a posição 
 * do carro acoplado ao  eixo  de um motor  de  passo. 
 * 
 * Ao  iniciar  o  funcionamento,  deve-se apresentara  mensagem “Buscandofim 
 * de curso” e girar o motor de passo no sentido anti-horário até que o fim de 
 * curso seja acionado. 
 * 
 * Em outras palavras, o motor girará no sentido 
 * anti-horário até que um botão que representa o fim de curso seja pressionado.
 * 
 * Após atingir o fim de curso, sabe-se que o carro está na posição 0cm. 
 * Portanto, deve-se exibir a mensagem “O carro está na posição 0 cm”.
 * 
 * A partir daí, o usuário pode enviar os caracteres (‘1’, ‘5’, ‘8’) 
 * pela comunicação serial. 

 * Recebero caractere ‘1’significa que o motor de passo deve dar 1 (uma) volta 
 * no sentido horário e a posição incrementada em 5 cm.

 * Recebero caractere ‘5’significa que o motor de passo deve dar 5(cinco) voltas
 * no sentido horário e a posição incrementada em 25 cm.

 * Recebero caractere ‘8’significa que o motor de passo deve dar 8(oito) voltas 
 * no sentido horário e a posição incrementada em 40cm. 

 * A mensagem deve ser atualizada a cada nova entrada com valor atual da posição.
 * Outro botão é o responsável pelo retorno do carro, ou seja, deve girar o 
 * motor de passo no sentidoinverso (anti-horário) o número de voltas já 
 * realizadas.
 * BotãoFimDeCurso-8
 * BotãoRetorno-9
 * Motor de passo p1-2
 * Motor de passo p2-3
 * Motor de passo p3-4
 * Motor de passo p4-5
 * 
 **/
//incluir a biblioteca de controle do motor
#include <Stepper.h>
//definições das variaveis
const int passos = 200, BotaoFimDeCurso = 8, BotaoRetorno = 9;
volatile int voltas = 0 , estado = 0, dadosSerial = 0, retorno = 0 ;

//iniciar o motor utilizando a biblioteca nos pinos 2 a 5
Stepper motor(passos, 2, 3, 4, 5);

void setup()
{

	pinMode(BotaoFimDeCurso, INPUT);
	pinMode(BotaoRetorno, INPUT);

	motor.setSpeed(60);

	Serial.begin(9600);
}
void loop()
{
	while (digitalRead(BotaoFimDeCurso) == 0 && estado == 0)
	{
		Serial.println("Buscando fim de curso....");
		motor.step(-passos);
	}

	estado =1;
	Serial.println("O carro está na posição 0 cm");

	while(digitalRead(BotaoRetorno) != 1){
		delay(5000);
		if(Serial.available() > 0){
			dadosSerial = Serial.parseInt();
			if(dadosSerial == 1 && digitalRead(BotaoRetorno)==0){
				motor.step(passos);
				voltas = voltas + 1;
				dadosSerial = 0;
				Serial.print("O carro está na posição ");
				Serial.print(voltas);
				Serial.println(" cm");
				delay(1000);
			} else if(dadosSerial == 5 && digitalRead(BotaoRetorno)==0){
				for(int i = 0; i < 5; i++){
					motor.step(passos);
				}
				voltas = voltas + 25;
				dadosSerial = 0;
				Serial.print("O carro está na posição ");
				Serial.print(voltas);
				Serial.println(" cm");
				delay(1000);
			}else if(dadosSerial == 8 && digitalRead(BotaoRetorno)==0){
				for(int i = 0; i < 8; i++){
					motor.step(passos);
				}
				voltas = voltas + 40;
				dadosSerial = 0;
				Serial.print("O carro está na posição ");
				Serial.print(voltas);
				Serial.println(" cm");
				delay(1000);
			}else {
				dadosSerial = Serial.parseInt();
				delay(1000);
			}
		} 
	}

	retorno = (voltas/5);
	for (int i=0; i <= retorno; i++ ){
		motor.step(-passos);
		voltas= 0;
		estado = 0;
		delay(1000);
	}
}
