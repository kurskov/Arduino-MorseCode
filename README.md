[![GitHub](https://img.shields.io/github/license/kurskov/Arduino-MorseCode)](https://github.com/kurskov/Arduino-MorseCode/blob/main/LICENSE)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/kurskov/Arduino-MorseCode)](https://github.com/kurskov/Arduino-MorseCode/releases/latest)

# Morse code

The library implements the transfer of Morse code signals (dots and dashes) to the controller output, and also formalizes the intervals between the signals.

The duration of one point is taken as a unit of time.  
The duration of a dash is three dots.  
A pause between elements of the same character - one dot,  
between characters in a word - 3 dots (may by changed),  
between words - 7 dots (may by changed).  

---
## Default settings

* Controllers pin number (PN): 13
* Clock cycle (CC): 250 ms

---
## Basic functions

### Constructor

There are three options for creating an object:
* default settings (PN=13, CC=250)
  ```c++
  Morse morse();
  ```
* with select pin number (CC=250)
  ```c++
  Morse morse(13);
  ```
* with select all parametrs
  ```c++
  Morse morse(13, 250);
  ```

### Dot

The function to transmit one dot.  
1 clock cycle high level on the pin, 1 clock cycle low level on the pin.
```c++
void dot();
```

### Dash

The function to transmit one dash.  
3 clock cycle high level on the pin, 1 clock cycle low level on the pin.

```c++
void dash();
```

### Letter space

The transmit a pause between characters in a word.  
The default is 2 clock cycle low level (because 1 clock cycle added from a dot or a dash).
```c++
void ls();
```
In the settings this value set as 3. This function decrease set value on 1 point.

### Word space

The transmit a pause between words.  
The default is 6 clock cycle low level (because 1 clock cycle added from a dot or a dash).
```c++
void ws();
```
In the settings this value set as 7. This function decrease set value on 1 point.

---
## Change settings

You can change pin number, clock cycle, pause between characters in a word and pause between words.

### setPin()

Set Arduino pin number for transmitting morse code.
```c++
void setPin(uint8_t pin_number);
```
Parameter:  
**pin_number** - a number of Arduino pin *(unsigned char)*

### setCC()

Set clock cycle of transmitting morse code.  
This value determines the duration of the point and the interval between elements of the same character (in milliseconds).
```c++
void setCC(int clock_cycle);
```
Parameter:  
**clock_cycle** - clock cycle of trancmitting in milliseconds *(integer)*.

### setLS()

Set pause between characters in a word.  
The default is 3 clock cycles (as defined in Morse code), but can be changed for special settings.
```c++
void setSL(uint8_t letter_space);
```
Parameter:  
**letter_space** - pause between characters in quantity clock cycles *(unsigned char)*.

### setWS()

Set pause between words.
The default is 7 clock cycles (as defined in Morse code), but can be changed for special settings.
```c++
void setWS(uint8_t word_space);
```
Parameter:
**word_space** - pause between words in quantity clock cycles *(unsigned char)*.

### reset()

Return to default settings:
* Controllers pin number (PN): 13
* Clock cycle (CC): 250 ms
* Pause between characters: 3 CC
* Pause between words: 7 CC
```c++
void reset();
```

## License
Morse code by [Dmitrii Kurskov](https://kurskov.ru) is licensed under a MIT License.
