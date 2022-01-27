/*
    Morse code

    The duration of one point is taken as a unit of time. 
    The duration of a dash is three dots. 
    A pause between elements of the same character - one dot, 
    between characters in a word - 3 dots (may by changed), 
    between words - 7 dots (may by changed).

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
    GitHub: https://github.com/kurskov/Arduino-MorseCode
    Version: 1.1.0
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
        Morse(uint8_t pin = DEF_MORSE_PIN, int clock_cycle = DEF_MORSE_CC, bool basic_level = LOW);
        
        // The return a dot and pause (1H + 1L) at one repeat.
        // Takes 2 cycles (every repeat).
        // For autorepeat you need specify the number of repetitions, f.e.: dot(3).
        void dot(int repeat = 1);
        
        // The return a dash and pause (3H + 1L) at one repeat.
        // Takes 4 cycles (every repeat).
        // For autorepeat you need specify the number of repetitions, f.e.: dash(2).
        void dash(int repeat = 1);
        
        // The return a space between letters in a word.
        // Default takes 2 cycles (DEF_MORSE_LS - 1).
        // This function takes into account a pause of end a dot or a dash.
        void ls();
        
        // The return a space between words in a phrase.
        // Default takes 6 cycles (DEF_MORSE_WS - 1).
        // This function takes into account a pause of end a dot or a dash.
        void ws();
        
        // Set functions
        void setPin(uint8_t pin);
        void setCC(int clock_cycle);
        void setLS(uint8_t letter_space);
        void setWS(uint8_t word_space);
        void setBasicLevel(bool basic_level);

        void reset();                   // set default settings
    
    private:
        uint8_t _pin;                   // signal pin
        int _clock_cycle;               // clock cycle
        uint8_t _letter_space;          // space between letters in a word
        uint8_t _word_space;            // space between words in a phrase
        bool _basic_level;              // basic lever of transmit (Def: LOW: L-H-L) 
};

#endif // _H_056E5B47_88DD_4CDD_83F5_175F7A63871E
