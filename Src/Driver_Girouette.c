#include "Driver_Girouette.h"

void Init_Girouette(MyTimer_Struct_TypeDef * myTimer)
{
	myTimer->Timer = TIM2; // On utilise le Timer 2
	myTimer->ARR = 359;
	myTimer->PSC = TIM_PSC_PSC; // valeur par d�faut du prescaler (� verifier)
	
	MyTimer_Base_Init(myTimer);
	
	// on selectionne les deux entrees
	// entr�e 1
	myTimer->Timer->CCMR1 &= (~TIM_CCMR1_CC1S_1);
	myTimer->Timer->CCMR1 |= TIM_CCMR1_CC1S_0;
	
	// entr�e
	myTimer->Timer->CCMR1 &= (~TIM_CCMR1_CC2S_1);
	myTimer->Timer->CCMR1 |= TIM_CCMR1_CC2S_0;
	
	// On veut compter les fronts sur deux entr�es, donc SMS = 011
	myTimer->Timer->SMCR &= (~TIM_SMCR_SMS_2);
	myTimer->Timer->SMCR |= TIM_SMCR_SMS_1;
	myTimer->Timer->SMCR |= TIM_SMCR_SMS_0;
	
	// polarit� et "input capture" par d�faut pour les deux entr�es
	// entr�e 1
	myTimer->Timer->CCER &= (~TIM_CCER_CC1P);
	myTimer->Timer->CCER &= (~TIM_CCER_CC1NP);
	myTimer->Timer->CCMR1 &= (~TIM_CCMR1_IC1F);
	
	// entr�e 2
	myTimer->Timer->CCER &= (~TIM_CCER_CC2P);
	myTimer->Timer->CCER &= (~TIM_CCER_CC2NP);
	myTimer->Timer->CCMR1 &= (~TIM_CCMR1_IC2F);
}

void Start_Mesure_Girouette(MyTimer_Struct_TypeDef * myTimer)
{
	// activation du compteur
	myTimer->Timer->CR1 |= TIM_CR1_CEN;
	MyTimer_Base_Start(myTimer->Timer);
}

void Stop_Mesure_Girouette(MyTimer_Struct_TypeDef * myTimer)
{
	myTimer->Timer->CR1 &= (~TIM_CR1_CEN);
	MyTimer_Base_Stop(myTimer->Timer);
}

int Get_Angle(MyTimer_Struct_TypeDef * myTimer)
{
	return (int) myTimer->Timer->CNT;
}