#include <Keypad.h>

const byte ROWS = 3; //kolm rida
const byte COLS = 1; //uks tulp
boolean FLAG = 1;
boolean START = 1;
char vastus;
char keys[ROWS][COLS] = {
  {'P'},
  {'V'},
  {'E'}
};

byte rowPins[ROWS] = {9, 10, 11}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5}; //connect to the column pinouts of the keypad
int ledPin = 2;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
}

void loop() {

  digitalWrite(ledPin, HIGH); // Roheline led pin D2, punane led D3
  //delay(500);
  //digitalWrite(ledPin, LOW);
  //delay(500);

  char key = keypad.getKey(); // Saab valiku kätte

  while (key && FLAG == 1) // Hakkab tööle ainult kui voti ja FLAG on olemas {
    if (key == 'P') {
      Serial.println("Poolt");
      FLAG = 0;
      digitalWrite(ledPin, LOW);
      ledPin = 3;
      vastus = key;

    } else if (key == 'V') {
      Serial.println("Vastu");
      FLAG = 0;
      digitalWrite(ledPin, LOW);
      ledPin = 3;
      vastus = key;

    } else if (key == 'E') {
      Serial.println("Erapooletu");
      FLAG = 0;
      digitalWrite(ledPin, LOW);
      ledPin = 3;
      vastus = key;

    } else {
      FLAG = 0;
      digitalWrite(ledPin, LOW);
      ledPin = 3;
      vastus = key;

    }
    break;
  }

}
