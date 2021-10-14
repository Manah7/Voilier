#ifndef PLATEAU_H
#define PLATEAU_H

#include "stm32f10x.h"

/*
Driver pour la rotation du plateau
	PINs utilis�s :
		- PA7
		- PA8
		- PB6 ?
		Timer utilis� :
		- TIM3
		- TIM4 ?
*/

enum sens {
	HORAIRE, 
	ANTI_HORAIRE
};

/* D�fini le sens de rotation */
void Set_Rotation_Direction(enum sens s);

/* D�fini la vitesse de rotation, de 0 � 255 */
void Set_Rotation_Speed(short speed);

/* Commence la rotation */
void Start_Rotation();

/* Arr�te la rotation */
void Stop_Rotation();

#endif 