#define Ep 22
#define Lm 23
#define Er 24
#define Li 25
#define Ei 26 
#define La 27
#define Ea 28 
#define Sum 29
#define Res 30
#define Mult 31
#define Divi 32
#define Eu 33
#define Lb 34
#define Lo 35
#define Eb 47
#define LDA 36
#define ADD 37
#define SUB 38
#define MUL 39
#define DIV 40
#define GOTO 41
#define CALL 42
#define RETURN 43
#define OPC1 44
#define OUT 45
#define HLT 46
byte pc = -1;
int i = 0;
byte temp;
byte divisor;
int reloj = 500;
int relojp = 100;
void setup() {
  // put your setup code here, to run once:
  DDRF = 0B11111111;
  DDRK = 0B00000000;
  pinMode(Ep, OUTPUT);
  pinMode(Lm, OUTPUT);
  pinMode(Er, OUTPUT);
  pinMode(Li, OUTPUT);
  pinMode(Ei, OUTPUT);
  pinMode(La, OUTPUT);
  pinMode(Ea, OUTPUT);
  pinMode(Sum, OUTPUT);
  pinMode(Res, OUTPUT);
  pinMode(Mult, OUTPUT);
  pinMode(Divi, OUTPUT);
  pinMode(Eu, OUTPUT);
  pinMode(Lb, OUTPUT);
  pinMode(Lo, OUTPUT);
  pinMode(Eb, OUTPUT);

  pinMode(LDA, INPUT);
  pinMode(ADD, INPUT);
  pinMode(SUB, INPUT);
  pinMode(MUL, INPUT);
  pinMode(DIV, INPUT);
  pinMode(GOTO, INPUT);
  pinMode(CALL, INPUT);
  pinMode(RETURN, INPUT);
  pinMode(OPC1, INPUT);
  pinMode(OUT, INPUT);
  pinMode(HLT, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  pc++;
  PORTF = pc;
  delay(reloj);
  digitalWrite(Ep, 1);
  digitalWrite(Lm, 1);
  delay(reloj);
  digitalWrite(Lm, 0);
  digitalWrite(Ep, 0);
  delay(relojp);
  digitalWrite(Er, 1);
  digitalWrite(Li, 1);
  delay(reloj);
  digitalWrite(Li, 0);
  digitalWrite(Er, 0);
  delay(relojp);
  
  if(digitalRead(LDA) == 1){
    digitalWrite(Ei, 1);
    digitalWrite(Lm, 1);
    delay(reloj);
    digitalWrite(Lm, 0);
    digitalWrite(Ei, 0);
    delay(relojp);
    digitalWrite(Er, 1);
    digitalWrite(La, 1);
    delay(reloj);
    digitalWrite(La, 0);
    digitalWrite(Er, 0);
    delay(relojp);
    }
    
  if(digitalRead(ADD) == 1){
    digitalWrite(Ei, 1);
    digitalWrite(Lm, 1);
    delay(reloj);
    digitalWrite(Lm, 0);
    digitalWrite(Ei, 0);
    delay(relojp);
    digitalWrite(Er, 1);
    digitalWrite(Lb, 1);
    delay(reloj);
    digitalWrite(Lb, 0);
    digitalWrite(Er, 0);
    delay(relojp);
    digitalWrite(Sum, 1);
    digitalWrite(Eu, 1);
    delay(reloj);
    digitalWrite(Sum, 0);
    digitalWrite(La, 1);
    delay(reloj);
    digitalWrite(La, 0);
    digitalWrite(Eu, 0);
    delay(relojp);
    }
    
  if(digitalRead(SUB) == 1){
    digitalWrite(Ei, 1);
    digitalWrite(Lm, 1);
    delay(reloj);
    digitalWrite(Lm, 0);
    digitalWrite(Ei, 0);
    delay(relojp);
    digitalWrite(Er, 1);
    digitalWrite(Lb, 1);
    delay(reloj);
    digitalWrite(Lb, 0);
    digitalWrite(Er, 0);
    delay(relojp);
    digitalWrite(Res, 1);
    digitalWrite(Eu, 1);
    delay(reloj);
    digitalWrite(Res, 0);
    digitalWrite(La, 1);
    delay(reloj);
    digitalWrite(La, 0);
    digitalWrite(Eu, 0);
    delay(relojp);
    }

  if(digitalRead(MUL) == 1){
    digitalWrite(Ei, 1);
    digitalWrite(Lm, 1);
    delay(reloj);
    digitalWrite(Lm, 0);
    digitalWrite(Ei, 0);
    delay(relojp);
    digitalWrite(Er, 1);
    digitalWrite(Lb, 1);
    delay(reloj);
    digitalWrite(Lb, 0);
    digitalWrite(Er, 0);
    delay(relojp);
    digitalWrite(Mult, 1);
    digitalWrite(Eu, 1);
    delay(reloj);
    digitalWrite(Mult, 0);
    digitalWrite(La, 1);
    delay(reloj);
    digitalWrite(La, 0);
    digitalWrite(Eu, 0);
    delay(relojp);
    }

  if(digitalRead(DIV) == 1){
    digitalWrite(Ei, 1);
    digitalWrite(Lm, 1);
    delay(reloj);
    digitalWrite(Lm, 0);
    digitalWrite(Ei, 0);
    delay(relojp);
    digitalWrite(Er, 1);
    digitalWrite(Lb, 1);
    delay(reloj);
    divisor = PINK;
    delay(relojp);
    if(divisor == 0){
      digitalWrite(Er, 0);
      delay(relojp);
      PORTF = 0B11101101;
      delay(reloj);
      digitalWrite(Ep, 1);
      digitalWrite(Lo, 1);
      delay(relojp);
      digitalWrite(Lo, 0);
      digitalWrite(Ep, 0);
      while(true){}
      }
    digitalWrite(Lb, 0);
    digitalWrite(Er, 0);
    delay(relojp);
    digitalWrite(Divi, 1);
    digitalWrite(Eu, 1);
    delay(reloj);
    digitalWrite(Divi, 0);
    digitalWrite(La, 1);
    delay(reloj);
    digitalWrite(La, 0);
    digitalWrite(Eu, 0);
    delay(relojp);
    }

  if(digitalRead(GOTO) == HIGH){
    digitalWrite(Ei, 1);
    pc = PINK - 1;
    delay(reloj);
    digitalWrite(Ei, 0);
    delay(relojp);
    }
    
  if(digitalRead(CALL) == HIGH){
    digitalWrite(Ei, 1);
    temp = pc;
    pc = PINK - 1;
    delay(reloj);
    digitalWrite(Ei, 0);
    delay(relojp);
    }

  if(digitalRead(RETURN) == HIGH){
    pc = temp;
    }

  if(digitalRead(OPC1) == 1){
    digitalWrite(Ei, 1);
    i = PINK-1;
    delay(reloj);
    digitalWrite(Ei, 0);
    delay(relojp);
    }

  if(i>0 and digitalRead(OPC1) == 0){
    pc--;
    i--;
    }
    
  if(digitalRead(OUT) == 1){
    digitalWrite(Ea, 1);
    digitalWrite(Lo, 1);
    delay(reloj);
    digitalWrite(Lo,0);
    digitalWrite(Ea,0);
    delay(relojp);
    }
  if(digitalRead(HLT) == 1){
    while(true){}
    }  
}
