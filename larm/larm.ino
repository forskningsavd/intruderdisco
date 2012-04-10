
int DN         = 10; // Negativ
int D1         = 12; // D1
int D2         = 9;  // D2
int D3         = 8;  // D3

int diod      = 4;  // Diod positiv
int gnd       = 7;  // Diod negativ

int matning34  = 0;  // Matning 3,4
int on13       = 1;  // 1:ON,    3:ON
int on24       = 2;  // 2:ON,    4:ON
int off13      = 3;  // 1:OFF,   3:OFF
int off24      = 5;  // 2:OFF,   4:OFF
int matning12  = 6;  // Matning 1,2

int UT1        = 13; // UT1 Relä
int UT2        = 11; // UT2 Relä

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

  pinMode(on13, INPUT);
  pinMode(off13, INPUT);
  pinMode(on24, INPUT);
  pinMode(off24, INPUT);

  pinMode(matning12, OUTPUT);
  pinMode(matning34, OUTPUT);

  digitalWrite(gnd, LOW);
  digitalWrite(diod, LOW);
}

void loop() {
  // read keyboard
  Keyboard kb;
  digitalWrite(matning12, HIGH);
  digitalWrite(matning34, LOW);
  delay(1);
  kb.on_1 = (digitalRead(on13) == HIGH);
  kb.off_1 = (digitalRead(off13) == HIGH);
  kb.on_2 = (digitalRead(on24) == HIGH);
  kb.off_2 = (digitalRead(off24) == HIGH);

  digitalWrite(matning12, LOW);
  digitalWrite(matning34, HIGH);
  kb.on_3 = (digitalRead(on13) == HIGH);
  kb.off_3 = (digitalRead(off13) == HIGH);
  kb.on_4 = (digitalRead(on24) == HIGH);
  kb.off_4 = (digitalRead(off24) == HIGH);
  
  // act!
  digitalWrite(diod, kb.on_1 ? HIGH : LOW);
  digitalWrite(UT2, kb.on_2 ? HIGH : LOW);
  
  digitalWrite(D1, kb.on_4 ? HIGH : LOW); 
  digitalWrite(D2, kb.off_4 ? HIGH : LOW); 
  digitalWrite(D3, kb.off_2 ? HIGH : LOW); 
}




