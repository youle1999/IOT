#define LEDC_CHANNEL_0     0
#define LEDC_TIMER_13_BIT  13
#define LEDC_BASE_FREQ     5000

const int buzPin = 23;
const int btnPin = 17;
const int ledRedPin = 16;
int noteDuration = 1000 / 8;
bool alreadyPlayed = false;

void setup() {
  Serial.begin(115200);
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(buzPin, LEDC_CHANNEL_0);
  pinMode(btnPin, INPUT);
  pinMode(ledRedPin, OUTPUT);
}

void loop() {
  if (digitalRead(btnPin) == HIGH && !alreadyPlayed) {
    digitalWrite(ledRedPin, HIGH);

    for (int i = 500; i <= 2380; i += 20) {
      ledcWriteTone(LEDC_CHANNEL_0, i);
      Serial.print(i);
      Serial.print(" ");
      delay(noteDuration);
    }

    Serial.println();

    for (int i = 2400; i >= 500; i -= 20) {
      ledcWriteTone(LEDC_CHANNEL_0, i);
      Serial.print(i);
      Serial.print(" ");
      delay(noteDuration);
    }

    Serial.println();
    ledcWriteTone(LEDC_CHANNEL_0, 0);
    digitalWrite(ledRedPin, LOW);
    alreadyPlayed = true;
  }

  if (digitalRead(btnPin) == LOW) {
    alreadyPlayed = false;
  }
}
