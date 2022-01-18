#include <Morse.h>

// PN=12, CC=1000, LS=3, WS=7
Morse morse(12, 1000);

void setup() 
{
}
 
void loop() 
{
    // change pin number
    morse.setPin(9);
    // PN=9, CC=1000, LS=3, WS=7

    // change clock cicle
    morse.setCC(500);
    // PN=9, CC=500, LS=3, WS=7 

    // change letter space
    morse.setLS(5);
    // PN=9, CC=500, LS=5, WS=7 

    // change word space
    morse.setWS(15);
    // PN=9, CC=500, LS=5, WS=15 

    // back to default settings
    morse.reset();
    // PN=13, CC=250, LS=3, WS=7 
}