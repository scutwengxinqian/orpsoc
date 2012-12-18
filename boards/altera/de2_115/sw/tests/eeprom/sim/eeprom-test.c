/**
  Access EEPROM 24LC32 via I2C interface

Author: Xinqian Weng, 10212020048@fudan.edu.cn
  */
#include "board.h"
#include "cpu-utils.h"
#include "orpsoc-defines.h"
#include "uart.h"
#include "printf.h"

#include "eeprom.h"

int main(int argc, char *argv[])
{
	uart_init(DEFAULT_UART);
	printf("EEPROM write/read test BEGIN:\n");
	
	// Stop
	// Clear the 'EN' bit only when no transfer is in progress, i.e. 
	// after a STOP command, or when the command register has the STO 
	// bit set. When halted during a transfer, the core can hang the 
	// I2C bus. 
	i2c_master_slave_master_stop(0);
	// Change the value of the prescale register only when the 'EN' 
	// bit is cleared.
	i2c_master_slave_deact_core(0);
	i2c_master_slave_init_core(0, 199, 0);

	unsigned char ch;
	printf("writing 0x58 to address 9 ...\n");
	ch = 0x58;
	eeprom_write(0x0009, &ch, 1);

	printf("reading from current address ... ");
	ch = eeprom_read_current();
	printf("return [%02x]\n", ch);

	printf("reading from address 9 ... ");
	eeprom_read(0x0009, &ch, 1);
	printf("return [%02x]\n", ch);

	printf("write random data ... ");
	unsigned char randbyte[4096]={
#include "rand4096byte"
	};

	int i, j;
	for (i = 0; i < 128; i++)// 128 pages
		eeprom_write(32*i, randbyte + 32*i, 32);
	printf("Done.\n");

	printf("read entire memory ... \n");
	unsigned char buf[4096];
	eeprom_read(0, buf, 4096);
	for (i = 0; i < 512; i++)//line
	{
		printf("\t");
		for (j = 0; j < 8; j++) // 8 byte each line
			printf("0x%02X, ", buf[i*8+j]);
		printf("\n");
	}

	i2c_master_slave_deact_core(0);

	printf("EEPROM write/read test END.\n");
	printf("\n");
	return 0;
}

