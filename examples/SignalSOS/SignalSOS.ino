#include <Morse.h>
 
Morse morse();
 
void setup()
{
}
 
void loop()
{
    // used default settings
    morse.dot(); morse.dot(); morse.dot(); morse.ls();
    morse.dash(); morse.dash(); morse.dash(); morse.ls();
    morse.dot(); morse.dot(); morse.dot(); morse.ws();

    // new pin number and clock cycle
    morse.setPin(12);
    morse.setCC(500);
    morse.dot(); morse.dot(); morse.dot(); morse.ls();
    morse.dash(); morse.dash(); morse.dash(); morse.ls();
    morse.dot(); morse.dot(); morse.dot(); morse.ws();
}