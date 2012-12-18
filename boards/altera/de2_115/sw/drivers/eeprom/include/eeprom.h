#ifndef _EEPROM_
#define _EEPROM_
/**
  Access EEPROM 24LC32 via I2C interface

Author: Xinqian Weng, 10212020048@fudan.edu.cn
  */

#include "i2c_master_slave.h"

// Note: A physical page is 32 bytes.  If  a Page  Write  command 
// attempts  to  write across  a  physical  page  boundary,  the
// result is that the data wraps around to the beginning of the 
// current page (overwriting data  previously  stored  there), 
// instead  of being written to the next page as might be expected.
void eeprom_write(unsigned int addr, unsigned char *data, int length);

// Current address read
unsigned char eeprom_read_current();

// start read from a specific address
// The entire memory content can be read continuously.
unsigned char *eeprom_read(unsigned int addr, unsigned char *buf, int length);

#endif

