#include <stdint.h>
#include "MKL05Z4.h"
//c4->b10
//c3->b11
//c2->A5
//c1->A7

#define C4 10
#define C3 11
#define C2 9
#define C1 8
#define C4_Mask (1 << 10)
#define C3_Mask (1 << 11)
#define C2_Mask (1 << 9)
#define C1_Mask (1 << 8)


void portInit(void);
void irqInit(void);