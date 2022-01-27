#include <Morse.h>
 
Morse morse;
 
void setup()
{
}
 
void loop()
{
    morse.dot(3);   // lettar 'S' (***)
    morse.ls();     // space between letters in a word
    morse.dash(3);  // letter 'O' (---)
    morse.ls();     // space between letters in a word
    morse.dot(3);   // letter 'S' (***)
    morse.ws();     // space between words in a phrase
}