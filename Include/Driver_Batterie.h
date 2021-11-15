#ifndef BATTERIE_H
#define BATTERIE_H

#include "Driver_ADC.h"
#include "Driver_GPIO.h"

#define V_BAT 12
#define VALEUR_MAX_ADC 4095

/*
	Driver pour la gestion de la batterie
	Utilise les memes PINs que le driver de l'ADC
*/

/* Initialise le driver */
void Init_Batterie(void);

/* Retourne le pourcentage de batterie restant */
int Get_Valeur_Batterie(void);

/* Retourne si la tension de la batterie est trop faible */
int Is_Batterie_Faible(void);

#endif
