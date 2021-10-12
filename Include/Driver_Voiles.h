#ifndef VOILES_H
#define VOILES_H

#include "stm32f10x.h"

/*
Driver pour le r�glage des voiles
	PINs utilis�s :
		- PA6
		Timer utilis� :
		- TIM3
		- TIM4 ?
*/

/* R�glage des voiles, de 0 � 255, 255 �tant le plus bord� */
void Regler_Voiles(short r);

#endif 