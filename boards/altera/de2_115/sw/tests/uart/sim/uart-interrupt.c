/*
 * UART interrupt test
 *
 * Tests UART and interrupt routines servicing them.
 *
 * Relies on UART 0 receiving external stimulus.
 *
 * Julius Baxter, julius.baxter@orsoc.se
 *
*/


#include "cpu-utils.h"
#include "spr-defs.h"
#include "board.h"
#include "uart.h"
#include "printf.h"
#include "int.h"
#include "orpsoc-defines.h"

#ifndef UART0
# error
# error UART0 missing and is required for UART interrupt (loopback) test
# error
#endif


void uart_int_handler(void* corenum)
{

  int core = *((int*)corenum);

  if (core)report(core);
  
  unsigned char iir = uart_get_iir(core);

  if (iir & UART_IIR_NO_INT) return;

  if ( (iir & UART_IIR_ID)  == UART_IIR_RLSI)
    uart_get_lsr(core); // Should clear this interrupt
  else if ( (iir & UART_IIR_ID) == UART_IIR_RDI || (iir & UART_IIR_ID) == UART_IIR_TOI)// cover RDA and TOI cases
    {
      // Data received. Pull from the fifo and echo back.
      char rxchar;
      while (uart_check_for_char(core))
	{
	  rxchar = uart_getc(core);
	  uart_putc_noblock(core, rxchar);

	  if (rxchar == 0x2a) // Exit simulation when RX char is '*'
	    {
	      report(0x8000000d);
	      exit(0);
	    }
	}
    }
  else if ( (iir & UART_IIR_ID) ==  UART_IIR_THRI)
    {
    }
  else if ( (iir & UART_IIR_ID) == UART_IIR_MSI )
    {
      // Just read the modem status register to clear this
      uart_get_msr(core);
    }
}

int main()
{
  int uart0_core = 0;
  
  /* Set up interrupt handler */
  int_init();

  /* Install UART core 0 interrupt handler */
  int_add(UART0_IRQ, uart_int_handler,(void*) &uart0_core);
  
  /* Enable interrupts in supervisor register */
  mtspr (SPR_SR, mfspr (SPR_SR) | SPR_SR_IEE);
  
  uart_init(uart0_core);
//  printf("\n\tUART interrupt test.\n");
//  printf("\n\tType to see characters echoed\n");
  printf("main\n");

  uart_rxint_enable(uart0_core);

  while(1); // will exit in the rx interrupt routine
}

