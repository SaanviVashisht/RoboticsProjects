#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT); // Right motor IN1
  pinMode(12, OUTPUT); // Right motor IN2
  pinMode(11, OUTPUT); // Left motor IN3
  pinMode(10, OUTPUT); // Left motor IN4
}

void moveRobot(String motion) {

  if (motion == "Forward") {
    digitalWrite(10, HIGH);   // L motor forward
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);   // R motor forward
    digitalWrite(12, LOW);
  }

  else if (motion == "Backward") {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
  }

  else if (motion == "Left") {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
  }

  else if (motion == "Right") {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }

  else if (motion == "Stop") {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

  Serial.println(motion);
}

void loop() {

  char customKey = keypad.getKey();

  if (customKey) {
    Serial.println(customKey);

    if (customKey == '2') moveRobot("Forward");
    else if (customKey == '8') moveRobot("Backward");
    else if (customKey == '4') moveRobot("Left");
    else if (customKey == '6') moveRobot("Right");
    else if (customKey == '5') moveRobot("Stop");
  }
}