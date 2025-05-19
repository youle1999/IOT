const int switchPin = 17;
const int ledPin = 16;

bool hasSentSOS = false;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(switchPin);

  if (buttonState == HIGH && !hasSentSOS) {
    sendSOS();
    hasSentSOS = true; 
  }


  if (buttonState == LOW) {
    hasSentSOS = false;
  }
}

void shortBlink() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void longBlink() {
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void sendSOS() {
  // S: ・・・
  shortBlink();
  shortBlink();
  shortBlink();


  delay(600);

  // O: －－－
  longBlink();
  longBlink();
  longBlink();


  delay(600);


  shortBlink();
  shortBlink();
  shortBlink();


  delay(1000);
}
