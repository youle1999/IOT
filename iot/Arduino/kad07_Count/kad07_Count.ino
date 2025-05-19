const int analogPin = A17; // GPIO IO27pin にCdSセンサー接続

void setup() {
  Serial.begin(115200); // シリアル通信開始（115200bps）
}

void loop() {
  int a = analogRead(analogPin); // CdSセンサーの値を読み取る
  Serial.println(a);             // シリアルモニターに出力
  delay(10);                     // 少し待つ（10ミリ秒）
}
