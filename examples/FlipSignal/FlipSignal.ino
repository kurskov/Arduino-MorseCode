#include <Morse.h>
 
Morse morse;
 
void setup()
{
}
 
void loop()
{
    // slow
    morse.setLS(10);
    morse.setWS(50);

    // Default basic level is LOW.
    // Send HELLO
    // _-_-_-_-___-___-_---_-_-___-_---_-_-___---_---_---________
    getH(); getE(); getL(); getL(); getO(); morse.ws();

    // Change the base level.
    morse.setBasicLevel(HIGH);

    // Send WORLD
    // -_-___-___---___-___-___---_-___-_---_-___-_-_---___-_-_---
    getW(); getO(); getR(); getL(); getD();
    
    // Change the base level.
    morse.setBasicLevel(LOW);
}

// letter D
void getD() {
    morse.dash();
    morse.dot(2);
    morse.ls();
}

// letter E
void getE() {
    morse.dot();
    morse.ls();
}

// letter H
void getH() {
    morse.dot(4);
    morse.ls();
}

// letter L
void getL() {
    morse.dot();
    morse.dash();
    morse.dot(2);
    morse.ls();
}

// letter O
void getO() {
    morse.dot(3);
    morse.ls();
}

// letter R
void getR() {
    morse.dot();
    morse.dash();
    morse.dot();
    morse.ls();
}

// letter W
void getW() {
    morse.dot();
    morse.dash(2);
    morse.ls();
}
