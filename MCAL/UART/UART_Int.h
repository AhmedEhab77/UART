#ifndef  _UART_INT_H_
#define  _UART_INT_H_


void UART_VidInit(void);
void UART_VidTransmitEnable(void);
void UART_VidRecieveEnable(void);
void UART_VidRXCompleteInterruptEnable(void);
void UART_VidUDREmptyInterruptEnable(void);
void UART_VidWaitTransmitRegToBeEmpty(void);
void UART_VidWaitRecieveRegToBeFull(void);
void UART_VidSend(u8 LOC_u8Data);
u8 UART_VidReceieve(u8 LOC_u8Data);
void UART_VidSetCallBackForUDREmpty(void (*Lpfunc)(void));
void UART_VidSetCallBackForRxComplete(void (*Lpfunc)(void));








#endif