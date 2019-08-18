#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#include <avr/eeprom.h>
#include "datatypes.h"
#include "constants.h"

extern bool buttonStatesPrev [];
extern bool buttonStates [];

extern long counter;
extern unsigned long millsDelta;
extern unsigned long prevMills;
extern unsigned long currentMills;
extern unsigned long longPressMills;
extern unsigned long longPress2Mills;
extern unsigned long timeoutMills;
extern bool blinkPhase;

// Working variables
extern uint8_t digit;

// Date calculation workings
extern tmElements_t tm;
extern tmElements_t tm2;

extern SDate currentDate;
extern SDate birthDate;

extern uint16_t currentMinute;
extern uint16_t currentHour;
extern uint16_t currentSecond;

extern uint8_t stateSet;
extern uint8_t stateCounter;

bool validDate(SDate date);
void numberToDisplay(long number);
void timeToDsplay(uint16_t h, uint16_t m, uint16_t s, uint8_t blinkWhich);
void dateToDisplay(uint16_t d, uint16_t m, uint16_t y, uint8_t blinkWhich);
uint16_t daysInMonth(uint16_t month, uint16_t year);
void setDigit(uint8_t which, uint8_t number);
void setBlank(uint8_t which);
void writeBlankToBus();
void writeDigitToBus(uint8_t d);
bool anyButtonRelease();
bool buttonRelease(uint8_t btn);
bool buttonPress(uint8_t btn);
bool userModifyVariable(uint16_t &var, uint16_t min, uint16_t max);
void setupBlink();
void getTime();
long getSecondsTillDeath();
void printTime();
void setTime();
void print2digits(int number);

#endif