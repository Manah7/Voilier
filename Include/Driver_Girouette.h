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

MyTimer_Struct_TypeDef * myTimerGirouette;

/* Initialisation de la girouette et de l'interruption li�e � la d�tection du z�ro,
les entr�es A et B d�pendent du Timer pass� en param�tre, la pin correspond � I (zero)*/
void Init_Girouette(MyTimer_Struct_TypeDef * myTimer, char GPIO_pin);

/* Lancement du timer et de la prise des mesures */
void Start_Mesure_Girouette(MyTimer_Struct_TypeDef * myTimer);

/* Arr�t du timer et de la prise de mesures */
void Stop_Mesure_Girouette(MyTimer_Struct_TypeDef * myTimer);

/* Retourne la valeur de l'angle de la girouette */
int Get_Angle(MyTimer_Struct_TypeDef * myTimer);

/* handler d'interruption de remise � z�ro */
void EXTI2_IRQHandler(void);

#endif
