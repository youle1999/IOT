const int pwmPin   = A10;
const int swPin    = 17;
const uint8_t dutyVals[] = {0,63, 127, 191, 255};
uint8_t idx       = 0;
int flag          = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  ledcSetup(0, 12800, 8);
  ledcAttachPin(pwmPin, 0);
  ledcWrite(0, dutyVals[idx]);
}

void loop() {
  int b = digitalRead(swPin);

  if (b == HIGH && flag == 0) {
    idx = (idx + 1) % 5;
    ledcWrite(0, dutyVals[idx]);
    Serial.printf("duty=%d\n", dutyVals[idx]);
    flag = 1;
  }

  if (b == LOW) {
    flag = 0;
  }

  delay(10);
}
