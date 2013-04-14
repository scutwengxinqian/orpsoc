#include "cpu-utils.h"
#include "board.h"
#include "uart.h"
#include "printf.h"
/*
int memsize()
{
	// doesn't work
	int i;
	for(i=20; i<28; i++)// 1M ~ 
	{
		int probe = 1<<i;
		int * int_ptr = (int*) probe;
		*int_ptr = probe;
		if(*(int*)0 == probe)
			return probe;
	}
	return 0;
}
*/
int main(int argc, char* argv[])
{
	uart_init(0);

//	printf("MEMSIZE= 0x%08x B\n", memsize());

	printf("write to memory\n");
	printf("*(int *)0x00100000 = 0x00100000; //   1 M\n");
	*(int *)0x00100000 = 0x00100000;

	printf("*(int *)0x00200000 = 0x00200000; //   2 M\n");
	*(int *)0x00200000 = 0x00200000;

	printf("*(int *)0x00400000 = 0x00400000; //   4 M\n");
	*(int *)0x00400000 = 0x00400000;

	printf("*(int *)0x00800000 = 0x00800000; //   8 M\n");
	*(int *)0x00800000 = 0x00800000;

	printf("*(int *)0x01000000 = 0x01000000; //  16 M\n");
	*(int *)0x01000000 = 0x01000000;

	printf("*(int *)0x02000000 = 0x02000000; //  32 M\n");
	*(int *)0x02000000 = 0x02000000;

	printf("*(int *)0x04000000 = 0x04000000; //  64 M\n");
	*(int *)0x04000000 = 0x04000000;

	printf("read from memory\n");
	printf("[0x00100000]\t%08x\n", *(int*)0x00100000);
	printf("[0x00200000]\t%08x\n", *(int*)0x00200000);
	printf("[0x00400000]\t%08x\n", *(int*)0x00400000);
	printf("[0x00800000]\t%08x\n", *(int*)0x00800000);
	printf("[0x01000000]\t%08x\n", *(int*)0x01000000);
	printf("[0x02000000]\t%08x\n", *(int*)0x02000000);
	printf("[0x04000000]\t%08x\n", *(int*)0x04000000);

	return 0;
}

