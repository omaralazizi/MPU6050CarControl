#ifndef VECTOR_NUM_H 
#define VECTOR_NUM_H


#define ISR(__vector_num)    void __vector_num(void)__attribute__((signal)) ;\
                              void __vector_num(void)
	
	
// Interrupt Vectors for ATmega328P
#define RESET_vect          __vector_0
#define INT0_vect           __vector_1
#define INT1_vect           __vector_2
#define PCINT0_vect         __vector_3
#define PCINT1_vect         __vector_4
#define PCINT2_vect         __vector_5
#define WDT_vect            __vector_6
#define TIMER2_COMPA_vect    __vector_7
#define TIMER2_COMPB_vect    __vector_8
#define TIMER2_OVF_vect      __vector_9
#define TIMER1_CAPT_vect     __vector_10
#define TIMER1_COMPA_vect    __vector_11
#define TIMER1_COMPB_vect    __vector_12
#define TIMER1_OVF_vect      __vector_13
#define TIMER0_COMPA_vect    __vector_14
#define TIMER0_COMPB_vect    __vector_15
#define TIMER0_OVF_vect      __vector_16
#define SPI_STC_vect         __vector_17
#define USART_RX_vect        __vector_18
#define USART_UDRE_vect      __vector_19
#define USART_TX_vect        __vector_20
#define ADC_vect             __vector_21
#define EE_READY_vect        __vector_22
#define ANALOG_COMP_vect     __vector_23
#define TWI_vect             __vector_24
#define SPM_READY_vect       __vector_25


#endif 