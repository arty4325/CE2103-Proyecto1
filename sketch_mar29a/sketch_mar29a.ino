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
  int buttonState = digitalRead(buttonPin);
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int potentiometerValue = analogRead(potentiometerPin);

  Serial.print(" X: ");
  Serial.print(xAxisValue);
  Serial.print(", Y: ");
  Serial.print(yAxisValue);
  Serial.print(", Potentiometer: ");
  Serial.print(potentiometerValue);
  Serial.print(", Button: ");
  Serial.println(buttonState);
  Serial.print(", Button1: ");
  Serial.print(buttonState1);
  Serial.print(", Button2: ");
  Serial.print(buttonState2);

  if (buttonState == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    delay(1000); // Espera 1 segundo
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}
