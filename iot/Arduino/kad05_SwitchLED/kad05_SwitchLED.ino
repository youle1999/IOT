// Project: kad05_SwitchLED

const int switchPin = 17;  // タクトスイッチ入力ピン
const int ledPin    = 16;  // LED出力ピン

void setup() {
  pinMode(switchPin, INPUT);   
  pinMode(ledPin, OUTPUT);     
  digitalWrite(ledPin, LOW);   
}

void loop() {
  int state = digitalRead(switchPin);
  
  if (state == HIGH) {
    digitalWrite(ledPin, HIGH);  
  } else {
    digitalWrite(ledPin, LOW);   
  }
  
  delay(10);  
}
