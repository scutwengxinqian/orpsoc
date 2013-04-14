#include "cpu-utils.h"
#include "lib-utils.h"
#include "board.h"
#include "uart.h"
#include "printf.h"

//unsigned int array[15*1024*1024];
unsigned int array[15*1024*1024];

int main(int argc, char* argv[])
{
	uart_init(0);

	printf("write to memory\n");
	unsigned checksum_golden;
	int i;
	for (i = 0, checksum_golden = 0; i<sizeof(array)/sizeof(array[0]); i++)
	{
		int v = rand();
		array[i] = v;
		checksum_golden ^= v;
	}

	printf("Verifying data\n");
	int checksum;
	for (i = 0, checksum = 0; i<sizeof(array)/sizeof(array[0]); i++)
	{
		checksum ^= array[i];
	}
	if(checksum==checksum_golden) printf("Match\n");
	else printf("misMatch\n");

	return 0;
}

