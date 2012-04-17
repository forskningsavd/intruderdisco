#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

#include <Arduino.h>
#include "pins.h"

union Keyboard {
  struct {
    boolean on_1 :  1;
    boolean off_1 : 1;
    boolean on_2 :  1;
    boolean off_2 : 1;
    boolean on_3 :  1;
    boolean off_3 : 1;
    boolean on_4 :  1;
    boolean off_4 : 1;
  } key;
  char all;
};

const int KEYBOARD_HISTORY_SIZE = 40;
Keyboard keyboardHistory[KEYBOARD_HISTORY_SIZE];
int keyboardCounter = 0;

void setupKeyboard() {
  pinMode(PIN_ON_13, INPUT);
  pinMode(PIN_OFF_13, INPUT);
  pinMode(PIN_ON_24, INPUT);
  pinMode(PIN_OFF_24, INPUT);

  pinMode(PIN_FEED_12, OUTPUT);
  pinMode(PIN_FEED_34, OUTPUT);

  memset(keyboardHistory, 0, sizeof(keyboardHistory));
}

Keyboard pollKeyboard() {
  // read keyboard
  Keyboard kb;
  digitalWrite(PIN_FEED_12, HIGH);
  digitalWrite(PIN_FEED_34, LOW);
  kb.key.on_1 = (digitalRead(PIN_ON_13) == HIGH);
  kb.key.off_1 = (digitalRead(PIN_OFF_13) == HIGH);
  kb.key.on_2 = (digitalRead(PIN_ON_24) == HIGH);
  kb.key.off_2 = (digitalRead(PIN_OFF_24) == HIGH);

  digitalWrite(PIN_FEED_12, LOW);
  digitalWrite(PIN_FEED_34, HIGH);
  kb.key.on_3 = (digitalRead(PIN_ON_13) == HIGH);
  kb.key.off_3 = (digitalRead(PIN_OFF_13) == HIGH);
  kb.key.on_4 = (digitalRead(PIN_ON_24) == HIGH);
  kb.key.off_4 = (digitalRead(PIN_OFF_24) == HIGH);

  keyboardHistory[keyboardCounter++ % KEYBOARD_HISTORY_SIZE] = kb;

  return kb;
}

Keyboard getStableKeyboard() {
  Keyboard kb;
  for (int i = 0; i < KEYBOARD_HISTORY_SIZE; i++) {
    kb.all |= keyboardHistory[i].all;
  }
  return kb;
}

#endif // KEYBOARD_H_INCLUDED
