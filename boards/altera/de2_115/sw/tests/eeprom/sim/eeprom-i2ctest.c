/**
  Access EEPROM 24LC32 via I2C interface

Author: Xinqian Weng, 10212020048@fudan.edu.cn
  */
#include "board.h"
#include "cpu-utils.h"
#include "orpsoc-defines.h"
#include "uart.h"
#include "printf.h"

#include "i2c_master_slave.h"

// assume the EEPROM device is connect to I2C0 controller
// and its slave address is 0x50

// Note: A physical page is 32 bytes.  If  a Page  Write  command 
// attempts  to  write across  a  physical  page  boundary,  the
// result is that the data wraps around to the beginning of the 
// current page (overwriting data  previously  stored  there), 
// instead  of being written to the next page as might be expected.
void eeprom_write(unsigned int addr, unsigned char *data, int length)
{
	// Control byte
	i2c_master_slave_master_start(0, 0x50, 0);// addr, read?
	// Address High byte
	i2c_master_slave_master_write(0, addr >> 8 & 0xFF, 0, 0);
	// Address Low byte
	i2c_master_slave_master_write(0, addr & 0xFF, 0, 0);
	// Data
	int i;
	for (i = 0; i < length-1; i++)
	{
		i2c_master_slave_master_write(0, data[i], 0, 0);
	}
	i2c_master_slave_master_write(0, data[i], 0, 1);
}

// Current address read
unsigned char eeprom_read_current()
{
	unsigned char ch;
	// Control byte
	i2c_master_slave_master_start(0, 0x50, 1);// addr, read?
	// Read data
	i2c_master_slave_master_read(0, 0, 1, &ch);

	return ch;
}

// start read from a specific address
// The entire memory content can be read continuously.
unsigned char *eeprom_read(unsigned int addr, unsigned char *buf, int length)
{
	// Control byte
	i2c_master_slave_master_start(0, 0x50, 0);// addr, read?
	// Address High byte
	i2c_master_slave_master_write(0, addr >> 8 & 0xFF, 0, 0);
	// Address Low byte
	i2c_master_slave_master_write(0, addr & 0xFF, 0, 0);

//	printf("Address sent ... ");
	// Control byte
	i2c_master_slave_master_start(0, 0x50, 1);// addr, read?
	// Read data
	int i;
	for (i = 0; i < length-1; i++)
	{
		i2c_master_slave_master_read(0, 0, 0, &buf[i]);
	}
	i2c_master_slave_master_read(0, 0, 1, &buf[i]);

	return buf;
}


int main(int argc, char *argv[])
{
	uart_init(DEFAULT_UART);
	printf("EEPROM write/read test BEGIN:\n");
//	printf("S0\n");
	
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
	printf("writing 0x58 to address 5 ...\n");
	ch = 0x58;
	eeprom_write(0x0005, &ch, 1);

	printf("reading from current address ... ");
	ch = eeprom_read_current();
	printf("return [%02x]\n", ch);

	printf("reading from address 5 ... ");
	eeprom_read(0x0005, &ch, 1);
	printf("return [%02x]\n", ch);

	printf("write random data ... ");
	unsigned char randbyte[4096]={
#include "rand4096byte"
	};

	int i, j;
	for (i = 0; i < 128; i++)// 128 pages
//		for (j = 0; j < 32; j++)// 32 bytes per page
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

