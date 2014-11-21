#include "board.h"
#include "portb.h"
#include "Tick.h"

void externInt_init(void);	
void RB0INT_ISR(void);
void RB1INT_ISR(void);	
extern UINT16 DBCount_B0;
extern UINT16 DBCount_B1;

