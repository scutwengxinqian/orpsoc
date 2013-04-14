#include "board.h"
#include "uart.h"
#include "printf.h"

int main(int argc, char* argv[])
{
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

