const int pwmPin = A10;

void setup() {
  Serial.begin(115200);
  ledcSetup(0, 12800, 8);
  ledcAttachPin(pwmPin, 0);
}

void loop() {
  static uint8_t duty = 0;
  static int diff = 1;

  Serial.printf("%3d\n", duty);
  ledcWrite(0, duty);

  duty += diff;

  if (duty == 255 || duty == 0) {
    diff = -diff;
  }

  delay(10);
}
