#include "board.h"
#include "cpu-utils.h"

#define GPIO_0_DATA GPIO_0_BASE
#define GPIO_0_DIR  (GPIO_0_BASE+1)

int main(int argc, char * argv[])
{
	REG8(GPIO_0_DIR) = 0xFF;// Output
	while (1)
	{
		REG8(GPIO_0_DATA) = 0xFF;
		REG8(GPIO_0_DATA) = 0x00;
	}
}

