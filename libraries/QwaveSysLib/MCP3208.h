#ifndef _MCP3208_H
#define _MCP3208_H

#if (ARDUINO >= 100) 
# include <Arduino.h>
#else
# include <WProgram.h>
#endif

#include <SPI.h>

class MCP3208 {
    private:
        // Private functions and variables here.  They can only be accessed
        // by functions within the class.
        uint8_t _cs;
        uint8_t spiTransfer(uint8_t);

    public:
        // Public functions and variables.  These can be accessed from
        // outside the class.
		MCP3208(uint8_t cs);
    
        void begin();
        uint16_t analogRead(uint8_t pin);
        int16_t analogReadDif(uint8_t pin);
};

extern MCP3208 * mcp3208[5];

#endif
