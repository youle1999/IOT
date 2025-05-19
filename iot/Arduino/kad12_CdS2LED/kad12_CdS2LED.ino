const int analogPin = A17;     
const int redLED = 16;         
const int blueLED = 4;         
const int darkLevel = 1000;    

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(analogPin);
  Serial.println(value);  

  if (value < darkLevel) {
    
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, HIGH);
  } else {
    
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
  }

  delay(100); 
}
