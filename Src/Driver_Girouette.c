#include "Driver_Girouette.h"

MyTimer_Struct_TypeDef * myTimerGirouette;

void Init_Girouette(void)
{
	// configuration du timer
	myTimerGirouette = malloc(sizeof(MyTimer_Struct_TypeDef));
	myTimerGirouette->Timer = TIM2; // On utilise le Timer 2
	myTimerGirouette->ARR = 359;
	myTimerGirouette->PSC = TIM_PSC_PSC; // valeur par d�faut du prescaler (� verifier)
	
	// initialisation du timer
	MyTimer_Base_Init(myTimerGirouette);
	
	// on selectionne les deux entrees
	// entr�e 1
	myTimerGirouette->Timer->CCMR1 &= ~TIM_CCMR1_CC1S_1;
	myTimerGirouette->Timer->CCMR1 |= TIM_CCMR1_CC1S_0;
	
	// entr�e
	myTimerGirouette->Timer->CCMR1 &= ~TIM_CCMR1_CC2S_1;
	myTimerGirouette->Timer->CCMR1 |= TIM_CCMR1_CC2S_0;
	
	// On veut compter les fronts sur deux entr�es, donc SMS = 011
	myTimerGirouette->Timer->SMCR &= ~TIM_SMCR_SMS_2;
	myTimerGirouette->Timer->SMCR |= TIM_SMCR_SMS_1;
	myTimerGirouette->Timer->SMCR |= TIM_SMCR_SMS_0;
	
	// polarit� et "input capture" par d�faut pour les deux entr�es
	// entr�e 1
	myTimerGirouette->Timer->CCER &= ~TIM_CCER_CC1P;
	myTimerGirouette->Timer->CCER &= ~TIM_CCER_CC1NP;
	myTimerGirouette->Timer->CCMR1 &= ~TIM_CCMR1_IC1F;
	
	// entr�e 2
	myTimerGirouette->Timer->CCER &= ~TIM_CCER_CC2P;
	myTimerGirouette->Timer->CCER &= ~TIM_CCER_CC2NP;
	myTimerGirouette->Timer->CCMR1 &= ~TIM_CCMR1_IC2F;
	
	// initialisation de l'interruption lors de la d�tection du zero
	// activation de la AFIO clock
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	// on configure la pin PA2 comme Alternate Function Input Output
	AFIO->EXTICR[0] &= AFIO_EXTICR1_EXTI2_PA;
	
	// interrupt mask register
	EXTI->IMR |= EXTI_IMR_MR2;
	
	// rising trigger selection register
	EXTI->RTSR |= EXTI_RTSR_TR2;
	EXTI->FTSR &= ~EXTI_FTSR_TR2;
	
	// configuration de l'interruption
	NVIC_SetPriority(EXTI2_IRQn, 1);
	NVIC_EnableIRQ(EXTI2_IRQn);
}

void Start_Mesure_Girouette(void)
{
	// activation du compteur
	myTimerGirouette->Timer->CR1 |= TIM_CR1_CEN;
	MyTimer_Base_Start(myTimerGirouette->Timer);
}

void Stop_Mesure_Girouette(void)
{
	// d�sactivation du compteur
	myTimerGirouette->Timer->CR1 &= (~TIM_CR1_CEN);
	MyTimer_Base_Stop(myTimerGirouette->Timer);
}

int Get_Angle(void)
{
	return (int) myTimerGirouette->Timer->CNT;
}

void EXTI2_IRQHandler(void)
{
	// reset du flag
	EXTI->PR |= 1;
	// handler
	myTimerGirouette->Timer->CNT = 0;
}
