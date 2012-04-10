#include "keyboard.h"

int DN         = 10; // Negativ
int D1         = 12; // D1
int D2         = 9;  // D2
int D3         = 8;  // D3

int diod      = 4;  // Diod positiv
int gnd       = 7;  // Diod negativ

int UT1        = 13; // UT1 Relä
int UT2        = 11; // UT2 Relä

void setup() {                
  pinMode(DN, OUTPUT);    
  pinMode(D1, OUTPUT); 
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT); 
  digitalWrite(DN, LOW); 

  pinMode(diod, OUTPUT);  
  pinMode(gnd, OUTPUT); 

  pinMode(UT1, OUTPUT);  
  pinMode(UT2, OUTPUT);

  setupKeyboard();

  digitalWrite(gnd, LOW);
  digitalWrite(diod, LOW);
}

void loop() {
  Keyboard kb = readKeyboard();
  
  // act!
  digitalWrite(diod, kb.on_1 ? HIGH : LOW);
  digitalWrite(UT2, kb.on_2 ? HIGH : LOW);
  
  digitalWrite(D1, kb.on_4 ? HIGH : LOW); 
  digitalWrite(D2, kb.off_4 ? HIGH : LOW); 
  digitalWrite(D3, kb.off_2 ? HIGH : LOW); 
}




