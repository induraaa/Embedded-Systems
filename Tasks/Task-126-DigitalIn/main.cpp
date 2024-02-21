#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //Button A
DigitalOut redLED(PC_2); //Red Traffic 1
DigitalOut yellowLED(PC_3); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    int btnA, btnB;
    // Turn OFF the red LED
    redLED = 0;

    while (true) {
        // Wait for the button to be pressed
        do {
            btnA = ButtonA; 
            btnB = ButtonB; //Read button A
        } while (btnA == 0 || btnB == 0);


        //Toggle the red LED
        redLED = !redLED;

        // Wait for the button to be released
        do {
            btnA = ButtonA;
            btnB = ButtonB; //Read button A
        } while (btnA == 1 && btnB == 1);
    }
}