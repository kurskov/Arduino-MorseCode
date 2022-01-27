/*
    See Morse.h for all information.

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
*/

#include "Morse.h"


// Constructor

Morse::Morse(uint8_t pin, int clock_cycle, bool basic_level) {
    // set basic parameter
    setPin(pin);
    setCC(clock_cycle);
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
        delay(_clock_cycle);
        digitalWrite(_pin, _basic_level);
        delay(_clock_cycle);
    }
}

void Morse::dash(int repeat) {
    for (int i = 0; i < repeat; i ++) {
        digitalWrite(_pin, !_basic_level);
        delay(_clock_cycle * 3);
        digitalWrite(_pin, _basic_level);
        delay(_clock_cycle);
    }
}

void Morse::ls() {
    delay(_clock_cycle * (_letter_space - 1));
}

void Morse::ws() {
    delay(_clock_cycle * (_word_space - 1));
}


// Set functions

void Morse::setPin(uint8_t pin) {
    _pin = pin;
}

void Morse::setCC(int clock_cycle) {
    _clock_cycle = clock_cycle;
}

void Morse::setLS(uint8_t letter_space) {
    if (letter_space > 0) 
        _letter_space = letter_space;
    else 
        _letter_space = DEF_MORSE_LS;
}

void Morse::setWS(uint8_t word_space) {
    if (word_space > 0) 
        _word_space = word_space;
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