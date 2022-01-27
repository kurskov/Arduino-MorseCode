/*
    See Morse.h for all information.

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
*/

#include "Morse.h"


// Constructor

Morse::Morse(uint8_t pin, int cc, bool basic_level) {
    // set basic parameter
    setPin(pin);
    setCC(cc);
    setLS(DEF_MORSE_LS);
    setWS(DEF_MORSE_WS);
    setBasicLevel(basic_level);

    // output's configuration
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, _basic_level);
}


// Transmit functions

void Morse::dot(int repeat) {
    for (int i = 0; i < repeat; i ++) {
        digitalWrite(_pin, !_basic_level);
        delay(_cc);
        digitalWrite(_pin, _basic_level);
        delay(_cc);
    }
}

void Morse::dash(int repeat) {
    for (int i = 0; i < repeat; i ++) {
        digitalWrite(_pin, !_basic_level);
        delay(_cc * 3);
        digitalWrite(_pin, _basic_level);
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

void Morse::setBasicLevel(bool basic_level) {
    _basic_level = basic_level;
}

void Morse::reset() {
    // set basic parameter
    setPin(DEF_MORSE_PIN);
    setCC(DEF_MORSE_CC);
    setLS(DEF_MORSE_LS);
    setWS(DEF_MORSE_WS);
}