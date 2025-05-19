void setup() {
  Serial.begin(115200);
  pinMode(17, INPUT);
}

void loop() {
  int b = digitalRead(17);
  if (b == 1) {
    Serial.println("押された");
  } else {
    Serial.println();
  }
  delay(10);
}
