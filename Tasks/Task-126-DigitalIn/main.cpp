#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //Button A
DigitalIn ButtonC(PG_2, PinMode::PullDown); //Button C
DigitalIn ButtonD(PG_3, PinMode::PullDown); //Button D

DigitalOut redLED(PC_2); //Red Traffic 1
DigitalOut yellowLED(PC_3); //Red Traffic 1
DigitalOut greenLED(PC_6); //Red Traffic 1
DigitalOut whiteLED(PF_10); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    int btnA;
    // Turn OFF the red LED
    redLED = 0;

    while (true) {
    
        // Wait for the button to be pressed
        do {
            btnA = ButtonA; //Read button A
        } while (btnA == 0);


        //Toggle the red LED
        redLED = !redLED;

        //Wait for noise to settle
        wait_us(10000);

        // Wait for the button to be released
        do {
            btnA = ButtonA; //Read button A
        } while (btnA == 1);

        //Wait for noise to settle
        wait_us(10000);
    }
}

