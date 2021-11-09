#ifndef VOILES_H
#define VOILES_H

#include "stm32f10x.h"

#include "Driver_Timer.h"
#include "Driver_GPIO.h"

/*
Driver pour le r�glage des voiles
	PINs utilis�s :
		- PA6 (D12)
		Timer utilis� :
		- TIM3, channel 1 (correspond � PA6)
*/

/* Initialise le module voiles. Regle les voiles en position 0. */
void Init_Voiles(void);

/* R�glage des voiles, de 0 � 100 (inclus), 100 �tant le plus bord� */
void Regler_Voiles(short r);

#endif 
