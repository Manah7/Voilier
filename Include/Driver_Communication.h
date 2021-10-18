#ifndef COM_H
#define COM_H

#include "stm32f10x.h"
#include "driver_Timer.h"

//Configure l'UART
void Config_UART(USART_TypeDef * UART_Par);

//Configure l'envoi de messages
//void Init_Message_Sending(int delay);

//Envoi de message
void Send_Message(const char * message[]);

//Configure la reception des messages (prend en argument la fonction appel�e � la r�ception avec en param�tre le caract�re re�u)
void Init_Message_Receiving(void (* ptrFonction) (char));


#endif