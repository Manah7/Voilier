#ifndef BATTERIE_H
#define BATTERIE_H

#include "Driver_ADC.h"

/*
	Driver pour la gestion de la batterie
	Utilise les memes PINs que le driver de l'ADC
*/

/* Initialise le driver */
void Init_Batterie();

/* Retourne le pourcentage de batterie restant */
void Get_Valeur_Batterie();

/* Retourne si la tension de la batterie est trop faible */
int Is_Batterie_Faible(int valeur);

#endif