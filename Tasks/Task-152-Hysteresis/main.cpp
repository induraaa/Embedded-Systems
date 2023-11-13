#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
Buzzer buzz;

int main()
{

    while (true) {
        //Read Analog to Digital Converter values (16 bit)
        unsigned short potVal   = pot.read_u16();
        printf("Potentiometer: %X\n", potVal);
        
        if (potVal > 0x9000) {
            redLED = 1;
            buzz.playTone("D");
        } else if (potVal < 0x7000) {
            redLED = 0;
            buzz.rest();
        }

        //Wait 0.25 seconds
        wait_us(500000);

    }  
}

