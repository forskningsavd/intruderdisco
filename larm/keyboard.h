#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

#include <Arduino.h>
#include "pins.h"

struct Keyboard {
  boolean on_1 :  1;
  boolean off_1 : 1;
  boolean on_2 :  1;
  boolean off_2 : 1;
  boolean on_3 :  1;
  boolean off_3 : 1;
  boolean on_4 :  1;
  boolean off_4 : 1;
};

void setupKeyboard() {
  pinMode(PIN_ON_13, INPUT);
  pinMode(PIN_OFF_13, INPUT);
  pinMode(PIN_ON_24, INPUT);
  pinMode(PIN_OFF_24, INPUT);

  pinMode(PIN_FEED_12, OUTPUT);
  pinMode(PIN_FEED_34, OUTPUT);
}

Keyboard readKeyboard() {
  // read keyboard
  Keyboard kb;
  digitalWrite(PIN_FEED_12, HIGH);
  digitalWrite(PIN_FEED_34, LOW);
  kb.on_1 = (digitalRead(PIN_ON_13) == HIGH);
  kb.off_1 = (digitalRead(PIN_OFF_13) == HIGH);
  kb.on_2 = (digitalRead(PIN_ON_24) == HIGH);
  kb.off_2 = (digitalRead(PIN_OFF_24) == HIGH);

  digitalWrite(PIN_FEED_12, LOW);
  digitalWrite(PIN_FEED_34, HIGH);
  kb.on_3 = (digitalRead(PIN_ON_13) == HIGH);
  kb.off_3 = (digitalRead(PIN_OFF_13) == HIGH);
  kb.on_4 = (digitalRead(PIN_ON_24) == HIGH);
  kb.off_4 = (digitalRead(PIN_OFF_24) == HIGH);

  return kb;
}

#endif // KEYBOARD_H_INCLUDED
