#define LEDC_CHANNEL_0     0
#define LEDC_TIMER_13_BIT  13
#define LEDC_BASE_FREQ     5000

const int buzPin = 23;
const int btnPin = 17;
const int ledRedPin = 16;
int noteDuration = 1000 / 8;

void setup() {
  Serial.begin(115200);
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(buzPin, LEDC_CHANNEL_0);
  pinMode(btnPin, INPUT);
  pinMode(ledRedPin, OUTPUT);
}

void loop() {
  if (digitalRead(btnPin) == HIGH) {
    digitalWrite(ledRedPin, HIGH);
    timeSignal();
    digitalWrite(ledRedPin, LOW);
    while (digitalRead(btnPin) == HIGH); // wait until button is released
  }
}

void timeSignal(void) {
  double note_half = noteDuration * 4;
  double note_whole = noteDuration * 8;
  double note_16th = noteDuration / 2;

  ledcWriteTone(LEDC_CHANNEL_0, 440); delay(note_half);
  ledcWriteTone(LEDC_CHANNEL_0, 0);   delay(note_16th);

  ledcWriteTone(LEDC_CHANNEL_0, 440); delay(note_half);
  ledcWriteTone(LEDC_CHANNEL_0, 0);   delay(note_16th);

  ledcWriteTone(LEDC_CHANNEL_0, 440); delay(note_half);
  ledcWriteTone(LEDC_CHANNEL_0, 0);   delay(note_16th);

  ledcWriteTone(LEDC_CHANNEL_0, 880); delay(note_whole);
  ledcWriteTone(LEDC_CHANNEL_0, 0);
}
