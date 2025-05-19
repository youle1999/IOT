const int analogPin = A17;  
const int blueLED = 4;     

void setup() {
  pinMode(blueLED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int a = analogRead(analogPin);        
  int pwm = map(a, 0, 4095, 255, 0);    

  analogWrite(blueLED, pwm);            
  Serial.printf("%d, %d\n", a, pwm);    

  delay(100); 
}
