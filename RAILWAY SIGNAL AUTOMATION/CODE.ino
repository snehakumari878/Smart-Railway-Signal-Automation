int irSensor = 2;      // IR sensor pin
int redLED = 8;        // Red signal
int yellowLED = 9;     // Orange signal
int greenLED = 10;     // Green signal

void setup() {
  pinMode(irSensor, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Default signal is green
  digitalWrite(greenLED, HIGH);
}

void loop() {

  int sensorValue = digitalRead(irSensor);

  if (sensorValue == LOW) {   // Train detected
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    delay(3000);              // Train passing time

    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(2000);              // Warning time

    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH); // Track clear
  }
}