/*
    See Morse.h for all information.

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
*/

#include "Morse.h"


// Constructor

Morse::Morse(uint8_t pin; int cc) {
    // set basic parameter
    setPin(pin);
    setCC(cc);
    setLS(DEF_MORSE_LS);
    setWS(DEF_MORSE_WS);
    // output's configuration
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}


// Transmit functions

void Morse::dot(int repeat) {
    for (int i = 1; i < repeat; i ++) {
        digitalWrite(_pin, HIGH);
        delay(_cc);
        digitalWrite(_pin, LOW);
        delay(_cc);
    }
}

void Morse::dash(int repeat) {
    for (int i = 1; i < repeat; i ++) {
        digitalWrite(_pin, HIGH);
        delay(_cc * 3);
        digitalWrite(_pin, LOW);
        delay(_cc);
    }
}

void Morse::ls() {
    delay(_cc * (_letter_space - 1));
}

void Morse::ws() {
    delay(_cc * (_word_space - 1));
}


// Set functions

void Morse::setPin(uint8_t pin) {
    _pin = pin;
}

void Morse::setCC(int cc) {
    _cc = cc;
}

void Morse::setLS(uint8_t ls) {
    if (ls > 0) 
        _letter_space = ls;
    else 
        _letter_space = DEF_MORSE_LS;
}

void Morse::setWS(uint8_t ws) {
    if (ws > 0) 
        _word_space = ws;
    else 
        _word_space = DEF_MORSE_WS;
}

void Morse::reset() {
    // set basic parameter
    setPin(DEF_MORSE_PIN);
    setCC(DEF_MORSE_CC);
    setLS(DEF_MORSE_LS);
    setWS(DEF_MORSE_WS);
}