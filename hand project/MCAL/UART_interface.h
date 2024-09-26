

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_init(u32 ubrr);
void UART_u8TransmitData(u8 copy_u8Data);
u8 UART_u8RecieveData(void);


#endif