#include "uop_msb.h"
#include <chrono>
#include <cstdint>
#include <cstdio>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;


int main()
{
    unsigned short samples[100];

    for (unsigned int m=0; m<100; m++) {
        printf("%X ", samples[m]);
    }
    
    float sum = 0.0;
    float avg = 0.0;
    // Automatic headlamp 
    while (true) {

        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            sum = sum + ldrVal;
            samples[m] = ldrVal;
            wait_us(10000);          // 10ms
        }
        avg = sum / 100;
        printf("Average is: %0.1f\n", avg);

        if (avg > 15000.0) {
            greenLED = 1;
        }
        else {
        greenLED = 0;
        }

        sum = 0.0;
        avg = 0.0;
        // TASK a. Calculate the average value in samples

        // TASK b. Display to 1dp

        // TASK c. Switch green LED on when dark;

    }  
}


