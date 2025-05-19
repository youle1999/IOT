const int analogPin = A17;

void setup() {
  Serial.begin(115200); ）
}

void loop() {
  int a = analogRead(analogPin);       // アナログ値 (0〜4095)
  float voltage = a * 3.3 / 4095.0;     


  Serial.printf("%4d=%.2f[V]\n", a, voltage);

  delay(100); 
}
