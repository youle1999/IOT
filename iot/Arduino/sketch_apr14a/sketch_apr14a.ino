const int ledPin = 16; // IO16 番ピンに LED 接続
 
void setup() {
  pinMode(ledPin, OUTPUT); // LED ピンを出力モードに設定
}
 
void loop() {
  // S（・・・）
  for (int i = 0; i < 3; i++) {
    dot();
  }
 
  delay(600); // 文字間隔（短点3つ分）
 
  // O（－－－）
  for (int i = 0; i < 3; i++) {
    dash();
  }
 
  delay(600); // 文字間隔（短点3つ分）
 
  // S（・・・）
  for (int i = 0; i < 3; i++) {
    dot();
  }
 
  delay(1000); // SOS の繰り返し間隔
}
 
// 短点（・）200ms点灯＋200ms消灯
void dot() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}
 
// 長点（－）600ms点灯＋200ms消灯
void dash() {
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
  delay(200);
}