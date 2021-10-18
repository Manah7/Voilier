#ifndef PLATEAU_H
#define PLATEAU_H

#include "stm32f10x.h"

#include "Driver_Timer.h"
#include "Driver_GPIO.h"

/*
Driver pour la rotation du plateau
	PINs utilis�s :
		- PA7 -> Pour la direction
		- PA8 -> Pour la PWM
	
		Timer utilis� :
		- TIM1, canal 1 (correspond � PA8)
*/

enum sens {
	HORAIRE, 
	ANTI_HORAIRE
};

/* Initialise le module plateau */
void Init_Plateau(void);

/* D�fini le sens de rotation */
void Set_Rotation_Direction(enum sens csens);

/* D�fini la vitesse de rotation, de 0 � 100 */
void Set_Rotation_Speed(short cspeed);

/* Commence la rotation */
void Start_Rotation(void);

/* Arr�te la rotation */
void Stop_Rotation(void);

#endif
