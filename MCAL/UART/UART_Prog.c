#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"UART_Priv.h"
#include"UART_Config.h"
#include"../Global Interrupt/GIE_Config.h"



/**GLOBAL POINTER TO FUNCTION**/
static void (*Gpfunc1)(void)=NULL;
static void (*Gpfunc2)(void)=NULL;
/********CALL BACK FUNCTION*****/
void UART_VidSetCallBackForRxComplete(void (*Lpfunc)(void))
{
	Gpfunc1=Lpfunc;
}
void UART_VidSetCallBackForUDREmpty(void (*Lpfunc)(void))
{
	Gpfunc2=Lpfunc;
}

/*************ISR FOR UART**********/
ISR(__vector_13)
{
	if(Gpfunc1 != NULL)
	{
		Gpfunc1();
	}
}

ISR(__vector_14)
{
	if(Gpfunc2 != NULL)
	{
		Gpfunc2();
	}
}





void UART_VidInit(void)
{
	u8 UCSRC_TEMP=0;//VAR TO ASSIGN UCSRC REG IN ONE TIME
	
	/*MUST BE ONE TO WRITE IN UCSRC*/
	SET_BIT(UCSRC_TEMP,URSEL);
	
	/***************************DATA_SIZE************************************/
	#if     Data_Size== Bit_5
    CLR_BIT(UCSRC_TEMP,UCSZ0);
    CLR_BIT(UCSRC_TEMP,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
    #elif   Data_Size== Bit_6
    SET_BIT(UCSRC_TEMP,UCSZ0);
    CLR_BIT(UCSRC_TEMP,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
    #elif   Data_Size== Bit_7
    CLR_BIT(UCSRC_TEMP,UCSZ0);
    SET_BIT(UCSRC_TEMP,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
    #elif  Data_Size== Bit_8
    SET_BIT(UCSRC_TEMP,UCSZ0);
    SET_BIT(UCSRC_TEMP,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
	#elif  Data_Size== Bit_9
    SET_BIT(UCSRC_TEMP,UCSZ0);
    SET_BIT(UCSRC_TEMP,UCSZ1);
	SET_BIT(UCSRB,UCSZ2);
    #endif
	
	/***************************PARITY_MOOD************************************/
	#if     PARITY_MOOD == DISABLED
    CLR_BIT(UCSRC_TEMP,UPM0);
    CLR_BIT(UCSRC_TEMP,UPM1);
    #elif   PARITY_MOOD == ODD_PARITY
    SET_BIT(UCSRC_TEMP,UPM0);
    SET_BIT(UCSRC_TEMP,UPM1);
    #elif   PARITY_MOOD == EVEN_PARITY
    CLR_BIT(UCSRC_TEMP,UPM0);
    SET_BIT(UCSRC_TEMP,UPM1);
    #endif
	
	/***************************STOP BIT************************************/
	CLR_BIT(UCSRC_TEMP,USBS);
	
	/***************************SYNCHORINZATION************************************/
	#if     SYNCHORINZATION_MOOD == SYNCHORONOUS
	SET_BIT(UCSRC_TEMP,UMSEL);
	#elif       SYNCHORINZATION_MOOD == ASYNCHORONOUS
	CLR_BIT(UCSRC_TEMP,UMSEL);
	#endif
	
	/*************************************************************************/
			UCSRC=UCSRC_TEMP;
	/*************************************************************************/
	
	/***************************BAUD RATE************************************/
	UBRRL=51;
	UBRRH=0;
		
}

void UART_VidTransmitEnable(void)
{
	SET_BIT(UCSRB,TXEN);
}
void UART_VidRecieveEnable(void) 
{
	SET_BIT(UCSRB,RXEN);
}

void UART_VidWaitTransmitRegToBeEmpty(void)
{
	while ( (GET_BIT(UCSRA,UDRE)) != 1){} //WAITING FOR FLAG
}

void UART_VidWaitRecieveRegToBeFull(void)
{
	while ( (GET_BIT(UCSRA,RXC)) != 1){} //WAITING FOR FLAG
}

void UART_VidSend(u8 LOC_u8Data)    
{
	UDR=LOC_u8Data;
}
u8 UART_VidReceieve(void)
{
	 u8 LOC_u8Data=UDR;
	 return LOC_u8Data;
}

void UART_VidRXCompleteInterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}
void UART_VidUDREmptyInterruptEnable(void)  
{
	SET_BIT(UCSRB,UDRIE);
}
