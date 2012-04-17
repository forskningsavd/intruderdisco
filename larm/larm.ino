#include "pins.h"
#include "keyboard.h"

void setup() {
  pinMode(PIN_TRAFICLIGHT_GROUND, OUTPUT);
  pinMode(PIN_TRAFICLIGHT_RED, OUTPUT);
  pinMode(PIN_TRAFICLIGHT_AMBER, OUTPUT);
  pinMode(PIN_TRAFICLIGHT_GREEN, OUTPUT);
  digitalWrite(PIN_TRAFICLIGHT_GROUND, LOW);

  pinMode(PIN_GROUND, OUTPUT);
  digitalWrite(PIN_GROUND, LOW);

  pinMode(PIN_KEYBOARD_DIOD, OUTPUT);
  digitalWrite(PIN_KEYBOARD_DIOD, LOW);

  pinMode(PIN_BLUELIGHT, OUTPUT);
  pinMode(PIN_DISCOLIGHT, OUTPUT);

  setupKeyboard();
}

void loop() {
  pollKeyboard();
  Keyboard kb = getStableKeyboard();

  // act!
  digitalWrite(PIN_KEYBOARD_DIOD, kb.key.on_1 ? HIGH : LOW);
  digitalWrite(PIN_BLUELIGHT, kb.key.on_2 ? HIGH : LOW);

  digitalWrite(PIN_TRAFICLIGHT_RED, kb.key.on_4 ? HIGH : LOW);
  digitalWrite(PIN_TRAFICLIGHT_AMBER, kb.key.off_4 ? HIGH : LOW);
  digitalWrite(PIN_TRAFICLIGHT_GREEN, kb.key.off_2 ? HIGH : LOW);

  delay(5);
}
