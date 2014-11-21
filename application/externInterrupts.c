#include "externInterrupts.h"
#include "portb.h"


#pragma idata EXINT_DATA
UINT8 RB0hasData = 0;
UINT8 RB1hasData = 0;
#pragma idata

void externInt_init(void)
{   
	OpenRB0INT( PORTB_PULLUPS_ON & FALLING_EDGE_INT & PORTB_INT_PRIO_HIGH );
  
    OpenRB1INT( PORTB_PULLUPS_ON & FALLING_EDGE_INT &PORTB_INT_PRIO_HIGH );

	INTCONbits.INT0IF = 0;	
	INTCON3bits.INT1IF = 0;
}

#pragma code
#pragma interrupt RB0INT_ISR
void RB0INT_ISR(void)
{

  	INTCONbits.INT0IF =0;	//cleat interrupt flag	

	if(DBCount_B0 < DBCOUNT)
		return;
	else
		DBCount_B0 = 0;
	RB0hasData = 1;	//set interrupt indication

}
	
#pragma code
#pragma interrupt RB1INT_ISR
void RB1INT_ISR(void)
{
 	INTCON3bits.INT1IF = 0;

	if(DBCount_B1 < DBCOUNT)
		return;
	else
		DBCount_B1 = 0;

  	RB1hasData = 1;	//set interrupt indication

}	



