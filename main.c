////////////////////////////////////////////////////////////////////////
//	I2C	SLAVE
////////////////////////////////////////////////////////////////////////

/*

I2C Slave MCU implementaiton:

(1) Master Transmitting to Slave:

	A- Specify the Slave Address (Slave_Address)

	=> receive the data on rxbuffer[i]

		i is the index defined by the master transmitter
		i range is 0-254


(2) Master Reading from slave

	A- Specify the Slave Address (Slave_Address)
	
	B- Specify the data you want to transmit in txbuffer[i]
	
		i is chosen by the master
		i range is 0-254


*/














#ifndef F_CPU
#define F_CPU 16000000UL
#endif



#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "I2C_slave.h"

// buffer used to convert integer to string
char buffer[3];



#define Slave_Address	0x02



int main(void)
{
	
	I2C_init(Slave_Address); // initalize as slave with address Slave_Address
	
	txbuffer[0] = 0x55;

	// allow interrupts
	sei();
	
	DDRB=0xFF;
	
	while(1)
	{
		
		PORTB=0xFF;
		_delay_ms(rxbuffer[0]);
		PORTB=0x00;
		_delay_ms(rxbuffer[1]);
		
		txbuffer[1] = rxbuffer[1];
		
		
	}
	
	return 0;
}
