#include "board.h"
#include "cpu-utils.h"

#define LED_BASE 0xb8000000
int main()
{
	int i, j;
	REG8(LED_BASE) = 0X01010101;
	while (1)
	{
		for(i=0;i<8;i++)
		{
			for(j=0;j<IN_CLK/16;j++);// delay
			REG8(LED_BASE) = 1<<i;
		}
	}
}

