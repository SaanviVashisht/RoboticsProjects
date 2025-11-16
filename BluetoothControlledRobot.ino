#include <SoftwareSerial.h>

SoftwareSerial BT(7, 8);  // RX, TX

int MA_p = 3;
int MA_n = 4;
int MB_p = 5;
int MB_n = 9;

char val = 's'; // start in STOP mode

void forward() {
  digitalWrite(MA_p, HIGH);
  digitalWrite(MA_n, LOW);
  digitalWrite(MB_p, HIGH);
  digitalWrite(MB_n, LOW);
}

void backward() {
  digitalWrite(MA_p, LOW);
  digitalWrite(MA_n, HIGH);
  digitalWrite(MB_p, LOW);
  digitalWrite(MB_n, HIGH);
}

void left() {
  digitalWrite(MA_p, LOW);
  digitalWrite(MA_n, HIGH);
  digitalWrite(MB_p, HIGH);
  digitalWrite(MB_n, LOW);
}

void right() {
  digitalWrite(MA_p, HIGH);
  digitalWrite(MA_n, LOW);
  digitalWrite(MB_p, LOW);
  digitalWrite(MB_n, HIGH);
}

void STOP() {
  digitalWrite(MA_p, LOW);
  digitalWrite(MA_n, LOW);
  digitalWrite(MB_p, LOW);
  digitalWrite(MB_n, LOW);
}

void setup() {
  pinMode(MA_p, OUTPUT);
  pinMode(MA_n, OUTPUT);
  pinMode(MB_p, OUTPUT);
  pinMode(MB_n, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {

  if (BT.available()) {
    val = BT.read();
    Serial.println(val);
  }

  if (val == 'F') {
    forward();
  }
  else if (val == 'B') {
    backward();
  }
  else if (val == 'L') {
    left();
  }
  else if (val == 'R') {
    right();
  }
  else if (val == 'S') {
    STOP();
  }
}
