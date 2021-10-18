#include "Driver_Communication.h"
USART_TypeDef * UART;
//� mettre dans le .c
void (* pFncUART) (char);

void SendChar(char character){
	//Tant que le transmission pr�c�dente n'est pas finit (tant que le bit CT de SR est � 0)
	while(((UART->SR>>6)&0x1)==0x0);
	UART->DR = character;
}

void Config_UART(USART_TypeDef * UART_par){
	// On met � 0 le bit M (12) de CR1 pour d�finir la taille des mots � 8
	UART = UART_par;
	UART->CR1 &= ~(0x1 << 12); 
	
	// On met � 1  le bit UE (13) de CR1 pour activer l'UART
	UART->CR1 |= (0x1 <<13);
	
	// On configure un stop bit : cf https://www.sparkfun.com/datasheets/Wireless/Zigbee/XBee-Datasheet.pdf page 10
	// -> on met � 0 les bits STOP (12 et 13) de CR2
	UART->CR2 &= ~((0x1<< 12) | (0x1 << 13));
	
	//UART BaudRate 9600 (cf prof)
	// -> Comme la clock du USART3 est � 36 MHz il faut la valeur 234,375 dans le registre de baudRate
	//-> cf p.804
	UART->BRR |= (234 <<4);
	UART->BRR |= 6;
	
	//On mets � 1 le bit TE de CR1 pour envoyer une frame de premi�re transmission
	UART->CR1 |= (0x1 << 3);
}
void Send_Message(const char* message[]){
	int i = 0;
	do{
		SendChar((char)message[i]);
	}while( message[i]!='\0');
}

/*
void Init_Message_Sending(int delay){
	MyTimer_Struct_TypeDef Timer;
	
}*/
void Init_Message_Receiving(void (* ptrFonction) (char)){
	//On setup la fonction de callback
	pFncUART = ptrFonction;
	
	//On lance la r�ception en mettant le bit RE de CR1 � 1: 
	UART->CR1 |= (0x1 <<2);
	
	//On active les interruption � la reception en mettant le bit RXNEIE de CR1 � 1 
	UART->CR1 |= (0x1<<5);
	
}

void USART2_IRQHandler(){
	//Si le bit RXNE de SR est � 1 (on a bien re�u une donn�e) on appelle la fonction
	if((UART->SR>>6)&0x1){
		//On remet le bit � 0
		UART->SR &= ~(0x1<<6);
		//On r�cup�re le carat�re dans DR
		pFncUART(UART->DR);
	}
}
void USART3_IRQHandler(){
	//Si le bit RXNE de SR est � 1 (on a bien re�u une donn�e) on appelle la fonction
	if((UART->SR>>6)&0x1){
		//On remet le bit � 0
		UART->SR &= ~(0x1<<6);
		//On r�cup�re le carat�re dans DR
		pFncUART(UART->DR);
	}
}
void USART4_IRQHandler(){
	//Si le bit RXNE de SR est � 1 (on a bien re�u une donn�e) on appelle la fonction
	if((UART->SR>>6)&0x1){
		//On remet le bit � 0
		UART->SR &= ~(0x1<<6);
		//On r�cup�re le carat�re dans DR
		pFncUART(UART->DR);
	}
}

