#ifndef  _UART_CONFIG_H_
#define  _UART_CONFIG_H_


/************UCSRA********/
#define  MPCM    0
#define  U2X     1
#define  PE      2
#define  DOR     3
#define  FE      4
#define  UDRE    5
#define  TXC     6
#define  RXC     7
/************UCSRB********/
#define  TXB8    0
#define  RXB8    1
#define  UCSZ2   2
#define  TXEN    3
#define  RXEN    4
#define  UDRIE   5
#define  TXCIE   6
#define  RXCIE   7
/************UCSRC********/
#define  UCPOL    0
#define  UCSZ0    1
#define  UCSZ1    2
#define  USBS     3
#define  UPM0     4
#define  UPM1     5
#define  UMSEL    6
#define  URSEL    7
/*************************/

/******************************************************************************/
/***************************MOODS OF DATA************************************/
/******************************************************************************/
#define  Bit_5                     0
#define  Bit_6                     1
#define  Bit_7                     2
#define  Bit_8                     3
#define  Bit_9                     4
/******************************************************/
#define Data_Size          Bit_8
/******************************************************/




/******************************************************************************/
/***************************MOODS OF PARITY************************************/
/******************************************************************************/
#define  EVEN_PARITY                    0
#define  ODD_PARITY                     1
#define  DISABLED                       2
/******************************************************/
#define PARITY_MOOD          EVEN_PARITY      
/******************************************************/


/******************************************************************************/
/***************************SYNCHORINZATION OF UART************************************/
/******************************************************************************/
#define  SYNCHORONOUS                    0
#define  ASYNCHORONOUS                   1
/******************************************************/
#define SYNCHORINZATION_MOOD          ASYNCHORONOUS     
/******************************************************/






#endif
