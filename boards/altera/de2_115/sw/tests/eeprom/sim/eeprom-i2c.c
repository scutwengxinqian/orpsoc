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

int main(int argc, char *argv[])
{
	unsigned char buf[80];

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
	i2c_master_slave_init_core(0, 399, 0);

	printf("writing 0x58 to address 0 ...\n");
//	printf("S1\n");
	// Control byte
	i2c_master_slave_master_start(0, 0x50, 0);// addr, read?
	// Address High byte
	i2c_master_slave_master_write(0, 0x00, 0, 0);
	// Address Low byte
	i2c_master_slave_master_write(0, 0x00, 0, 0);
	// Data
	i2c_master_slave_master_write(0, 0x58, 0, 1);
	// Stop
//	i2c_master_slave_master_stop(0);

	printf("reading from current address ... ");
//	printf("S2 ");
	// Control byte
	i2c_master_slave_master_start(0, 0x50, 1);// addr, read?
	// Read data
	i2c_master_slave_master_read(0, 0, 1, buf);
	printf("return [%02x]\n", buf[0]);

	printf("reading from address 0 ... ");
	// Control byte
	i2c_master_slave_master_start(0, 0x50, 0);// addr, read?
	// Address High byte
	i2c_master_slave_master_write(0, 0x00, 0, 0);
	// Address Low byte
	i2c_master_slave_master_write(0, 0x00, 0, 0);

	printf("Address sent ... ");
	// Control byte
	i2c_master_slave_master_start(0, 0x50, 1);// addr, read?
	// Read data
	i2c_master_slave_master_read(0, 0, 1, buf);
	// Stop
//	i2c_master_slave_master_stop(0);
	printf("return [%02x]\n", buf[0]);


	i2c_master_slave_deact_core(0);

	printf("EEPROM write/read test END.\n");
	return 0;
}

