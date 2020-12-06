const int ledPin13 = 13;
const int ledPin12 = 12;
const int ledPin11 = 11;
const int ledPin10 = 10;
const int ledPin9 = 9;
const int buttonInterruptPin = 3;
const int buttonOpenClosePin = 2;

int animationSpeed = 0;
int buttonOpenCloseState = 0;
int buttonInterruptState = 0;


void setup() {
  pinMode(ledPin13, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin9, OUTPUT);

  pinMode(buttonInterruptPin, INPUT); // interrupting 
  pinMode(buttonOpenClosePin, INPUT); // opening and closing the gate
}

void loop() {
  animationSpeed = 400;
  
  // read the state of the pushbutton value:
  buttonOpenCloseState = digitalRead(2);
  buttonInterruptState = digitalRead(3);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonOpenCloseState == HIGH) {
    // turn LED on:
    digitalWrite(13, HIGH);
    delay(animationSpeed);
    digitalWrite(12, HIGH);
    delay(animationSpeed);
    digitalWrite(11, HIGH);
    delay(animationSpeed);
    digitalWrite(10, HIGH);
    delay(animationSpeed);
    digitalWrite(9, HIGH);
    delay(animationSpeed);

  } else {
    // turn LED off:
    digitalWrite(13, LOW);
    delay(animationSpeed);
    digitalWrite(12, LOW);
    delay(animationSpeed);
    digitalWrite(11, LOW);
    delay(animationSpeed);
    digitalWrite(10, LOW);
    delay(animationSpeed);
    digitalWrite(9, LOW);
    delay(animationSpeed);
  }
  delay(10);
}
