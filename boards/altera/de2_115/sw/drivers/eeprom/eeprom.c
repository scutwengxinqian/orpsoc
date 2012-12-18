#include "eeprom.h"

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

