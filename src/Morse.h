/*
    Morse code

    The duration of one point is taken as a unit of time. 
    The duration of a dash is three dots. 
    A pause between elements of the same character - one dot, 
    between characters in a word - 3 dots (may by changed), 
    between words - 7 dots (may by changed).

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
    GitHub: https://github.com/kurskov/Arduino-MorseCode
    Version: 1.0
*/

// Include guard
#ifndef _H_056E5B47_88DD_4CDD_83F5_175F7A63871E
#define _H_056E5B47_88DD_4CDD_83F5_175F7A63871E

#if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

//Default settings
#define DEF_MORSE_PIN 13    // Signal pin of Arduino module.
#define DEF_MORSE_CC 250    // Clock cycle in ms (CC).
#define DEF_MORSE_LS 3      // A space between letters in a word (in quantity CC).
#define DEF_MORSE_WS 7      // A space between words in a phrase (in quantity CC).

class Morse {
    public:
        Morse(uint8_t pin=DEF_MORSE_PIN; int cc=DEF_MORSE_CC);
        void dot();                 // dot + 1 cycle (1H + 1L)
        void dash();                // dash + 1 cycle (3H + 1L)
        void ls();                  // _letter_space - 1 cycle (Def: 2L)
        void ws();                  // _word_space - 1 cycle (Def: 6L)
        void setPin(uint8_t pin);   // set _pin (signal pin)
        void setCC(int cc);         // set _cc (clock cycle)
        void setLS(uint8_t ls);     // set _letter_space 
        void setWS(uint8_t ws);     // set _word_space
        void reset();               // set default settings
    private:
        uint8_t _pin;               // signal pin
        int _cc;                    // clock cycle
        uint8_t _letter_space;      // space between letters in a word
        uint8_t _word_space;        // space between words in a phrase
};

#endif // _H_056E5B47_88DD_4CDD_83F5_175F7A63871E
