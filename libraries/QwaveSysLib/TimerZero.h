#ifndef TimerZero_h_
#define TimerZero_h_

#include <Arduino.h>

class TimerZero
{


#if defined(ESP8266)
  public:
	void initialize(unsigned long microseconds=1000000) __attribute__((always_inline)) {
		timer0_microseconds =  clockCyclesPerMicrosecond() * microseconds;
		timer0_write(ESP.getCycleCount() + timer0_microseconds);
    }
	void attachInterrupt(void (*isr)()) __attribute__((always_inline)) {
		isrCallback = isr;
		timer0_isr_init();
		timer0_attachInterrupt(isr);

    }
	void attachInterrupt(void (*isr)(), unsigned long microseconds) __attribute__((always_inline)) {
		if(microseconds > 0) {
			timer0_microseconds = clockCyclesPerMicrosecond() * microseconds;
			timer0_write(ESP.getCycleCount() + timer0_microseconds);
		}
		attachInterrupt(isr);
	}
	void detachInterrupt() __attribute__((always_inline)) {
		timer0_detachInterrupt();
    }
	void ResetInterrupt() {
		timer0_write(ESP.getCycleCount() + timer0_microseconds);
	}
	static void (*isrCallback)();
	
  private:
    // properties
	static unsigned long timer0_microseconds;
#endif
};

extern TimerZero Timer0;

#endif

