

#ifndef TIMERS_REGISTER_H_
#define TIMERS_REGISTER_H_

// Timer/Counter 0 Registers
#define TCCR0A       (*((volatile u8 *)0x44))
#define TCCR0B       (*((volatile u8 *)0x45))
#define TCNT0        (*((volatile u8 *)0x46))
#define OCR0A        (*((volatile u8 *)0x47))
#define OCR0B        (*((volatile u8 *)0x48))
#define TIMSK0       (*((volatile u8 *)0x6E))
#define TIFR0        (*((volatile u8 *)0x35))

// Timer/Counter 1 Registers
#define TCCR1A       (*((volatile u8 *)0x80))  // Timer Counter Control Register A Configures mode and output compare pins
#define TCCR1B       (*((volatile u8 *)0x81))  // Timer Counter Control Register B Controls clock source and mode selection
#define TCNT1L       (*((volatile u8 *)0x84))  // Timer Counter Register Low
#define TCNT1H       (*((volatile u8 *)0x85))  // Timer Counter Register High
#define TCNT1        _SFR_MEM16(0x84)
#define OCR1AL       (*((volatile u8 *)0x88))  // Output Compare Register 1A Low byte of compare match value 
#define OCR1AH       (*((volatile u8 *)0x89))  // Output Compare Register 1A High byte of compare match value 
#define OCR1A        _SFR_MEM16(0x88)
#define OCR1BL       (*((volatile u8 *)0x8A))  // Output Compare Register 1B Low byte of compare match value 
#define OCR1BH       (*((volatile u8 *)0x8B))  // Output Compare Register 1B High byte of compare match value 
#define OCR1B        _SFR_MEM16(0x8A)
#define ICR1L        (*((volatile u8 *)0x86))  // Input Capture Register 1 Low byte of input capture value
#define ICR1H        (*((volatile u8 *)0x87))  // Input Capture Register 1 High byte of input capture value
#define ICR1          _SFR_MEM16(0x86)
#define TIMSK1       (*((volatile u8 *)0x6F))  // Timer Counter Interrupt Mask Register Enables/disables interrupts for Timer/Counter 1
#define TIFR1        (*((volatile u8 *)0x36))  // Timer Counter Interrupt Flag Register Indicates which interrupts have occurred


// Timer/Counter 2 Registers
#define TCCR2A       (*((volatile u8 *)0xB0))
#define TCCR2B       (*((volatile u8 *)0xB1))
#define TCNT2        (*((volatile u8 *)0xB2))
#define OCR2A        (*((volatile u8 *)0xB3))
#define OCR2B        (*((volatile u8 *)0xB4))
#define TIMSK2       (*((volatile u8 *)0x70))
#define TIFR2        (*((volatile u8 *)0x37))

// General Timer/Counter Control Registers
#define GTCCR        (*((volatile u8 *)0x43))


#endif