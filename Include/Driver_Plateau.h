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

/* [[deprecated]] Initialise le module plateau */
void Init_Plateau(void);

/* [[deprecated]] D�fini le sens de rotation */
void Set_Rotation_Direction(enum sens s);

/* [[deprecated]] D�fini la vitesse de rotation, de 0 � 100 */
void Set_Rotation_Speed(short speed);

/* [[deprecated]] Commence la rotation */
void Start_Rotation(void);

/* [[deprecated]] Arr�te la rotation */
void Stop_Rotation(void);

#endif 