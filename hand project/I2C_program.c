#include <avr/io.h>

//lib
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"
//MCAL
#include "I2C_config.h"
#include "I2C_private.h"
#include "I2C_register.h"
#include "I2C_interface.h"

void I2C_Init(void) {
	// Set SCL frequency to 100kHz (assuming 16MHz CPU clock)
	TWSR = 0x00;  // Prescaler = 1
	TWBR = 0x48;  // SCL frequency = F_CPU / (16 + 2 * TWBR * Prescaler)
}

// Start I2C communication
u8 I2C_Start(void) {
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);  // Send START condition
    while (!(TWCR & (1 << TWINT)));  // Wait for start to complete
    
    // Check if start condition was transmitted successfully
    if ((TWSR & 0xF8) != 0x08) {
        return NOK;  // Return error state if start fails
    }
    return OK;
}


// Stop I2C communication
void I2C_Stop(void) {
	TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);  // Send STOP condition
}

// Write byte to I2C device
u8 I2C_Write(u8 data) {
	TWDR = data;  // Load data into data register
	TWCR = (1 << TWEN) | (1 << TWINT);  // Start transmission
	while (!(TWCR & (1 << TWINT)));  // Wait for transmission to complete
	
	// Check if data was acknowledged
	if ((TWSR & 0xF8) != 0x28) {  // 0x28 means data transmitted, ACK received
		return NOK;  // Return error if not acknowledged
	}
	return OK;
}


// Read byte with ACK
u8 I2C_ReadACK(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);  // Enable ACK
	while (!(TWCR & (1 << TWINT)));  // Wait for reception to complete
	
	// Check for data reception ACK
	if ((TWSR & 0xF8) != 0x50) {  // 0x50 means data received, ACK returned
		return NOK;  // Return error if ACK not received
	}
	return TWDR;
}

// Read byte with NACK (used for the last byte)
u8 I2C_ReadNACK(void) {
	TWCR = (1 << TWEN) | (1 << TWINT);  // No ACK
	while (!(TWCR & (1 << TWINT)));  // Wait for reception to complete
	
	// Check for data reception without ACK
	if ((TWSR & 0xF8) != 0x58) {  // 0x58 means data received, NACK returned
		return NOK;  // Return error if NACK not received
	}
	return TWDR;
}
