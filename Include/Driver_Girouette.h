#ifndef GIROUETTE_H
#define GIROUETTE_H

#include "stm32f10x.h"
#include "Driver_Timer.h"
#include <stdlib.h>

/*
	Driver pour la gestion de la girouette
	PINs utilis�es:
		- 2 PINs sur un Timer (pour A et B)
			- TIM2_CH1 : PA0 (A)
			- TIM2_CH2 : PA1 (B)
		- 1 PIN quelconque (pour I, le zero)
*/

/* TO DO
	interruption pour mise � zero de l'angle lorsque signal de I re�u ?
*/

/* Initialisation de la girouette et des pins correspondant aux entr�es A, B et I */
void Init_Girouette(MyTimer_Struct_TypeDef * myTimer);

/* Lancement du timer et de la prise des mesures */
void Start_Mesure_Girouette(MyTimer_Struct_TypeDef * myTimer);

/* Arr�t du timer et de la prise de mesures */
void Stop_Mesure_Girouette(MyTimer_Struct_TypeDef * myTimer);

/* Retourne la valeur de l'angle de la girouette */
int Get_Angle(MyTimer_Struct_TypeDef * myTimer);

#endif