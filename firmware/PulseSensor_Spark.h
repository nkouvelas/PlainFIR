#ifndef PULSE_INTERRUPT_H
#define PULSE_INTERRUPT_H

#include "application.h"
#include "SparkIntervalTimer.h"

extern volatile int rate[10];                    // array to hold last ten IBI values
extern volatile unsigned long sampleCounter = 0;          // used to determine pulse timing
extern volatile unsigned long lastBeatTime = 0;           // used to find IBI
extern volatile int P =2048;                      // used to find peak in pulse wave, seeded
extern volatile int T = 2048;                     // used to find trough in pulse wave, seeded
extern volatile int thresh = 2048;                // used to find instant moment of heart beat, seeded
extern volatile int amp = 410;                   // used to hold amplitude of pulse waveform, seeded
extern volatile boolean firstBeat = true;        // used to seed rate array so we startup with reasonable BPM
extern volatile boolean secondBeat = false;      // used to seed rate array so we startup with reasonable BPM

// these variables are volatile because they are used during the interrupt service routine!
extern volatile int BPM;                   // used to hold the pulse rate
extern volatile int Signal;                // holds the incoming raw data
extern volatile int IBI = 600;             // holds the time between beats, must be seeded! 
extern volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
extern volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// SparkIntervalTimer uses hardware timers that are otherwise allocated for PIN functions (ADC/PWM)
// The first allocated timer is TIMR2 on Core and TIMR3 on Photon which is assigned to A0 & A1 ADC/PWM channels
// So use A2 (though A0 & A1 ADC should still work on Core and not affected on Photon) for pulse input,
// D7 (onboard LED) for blink LED and D6 for fancy LED
//  VARIABLES
extern int pulsePin = A2;				// Pulse Sensor purple wire connected to analog pin 0
extern int blinkPin = D7;				// pin to blink led at each beat
extern int fadePin = D6;				// pin to do fancy classy fading blink at each beat
extern int fadeRate = 0;				// used to fade LED on with PWM on fadePin

void interruptSetup();
void pulseISR(void);

// Setup a 2ms h/w timer
IntervalTimer pulseTimer;

#endif

