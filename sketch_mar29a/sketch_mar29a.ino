const int buttonPin1 = 10;
const int buttonPin2 = 9;
const int buttonPin = 8;
const int xAxisPin = A1;
const int yAxisPin = A0;
const int potentiometerPin = A2;
const int buzzerPin = 7;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int xAxisValue = analogRead(xAxisPin);
  int yAxisValue = analogRead(yAxisPin);
  int potentiometerValue = analogRead(potentiometerPin);
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState = digitalRead(buttonPin);

  //Serial.print(" X: ");
  Serial.print(xAxisValue);
  Serial.print(",");
  Serial.print(yAxisValue);
  Serial.print(",");
  Serial.print(potentiometerValue);
  Serial.print(",");
  Serial.print(buttonState1);
  Serial.print(",");
  Serial.print(buttonState2);
  Serial.print(",");
  Serial.println(buttonState);
  //Serial.print("\n");

  
  if (buttonState == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    delay(1000); // Espera 1 segundo
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}
