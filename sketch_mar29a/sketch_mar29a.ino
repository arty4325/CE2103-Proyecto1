const int buttonPin1 = 5;
const int buttonPin2 = 4;
const int buttonPin = 3;
const int xAxisPin = A1;
const int yAxisPin = A0;
const int potentiometerPin = A2;
const int buzzerPin = 2;
const int pinA = 6;
const int pinB = 7;
const int pinC = 8;
const int pinD = 9;
const int pinE = 10;
const int pinF = 11;
const int pinG = 12;
const int pinDP = 13;
char valorSerial;




void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);

  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, HIGH);
  
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
  
  if (Serial.available() > 0) {
     valorSerial = Serial.read();
    if (valorSerial == '0') {
      // Enciende el segmento A
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);

      
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP, LOW);
      //delay(1000);
    
      // Apaga el segmento A
      /*
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);
      delay(100);
      */
    }
    if (valorSerial == '1') {

      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);

      
      digitalWrite(pinC, LOW);
      digitalWrite(pinDP, LOW);
      //delay(1000);

      /*
      digitalWrite(pinC, HIGH);
      digitalWrite(pinDP, HIGH);
      delay(100);
      */
    }
    if (valorSerial == '2') {
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);


      
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      //delay(1000);

      /*
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      delay(100);
      */
      
    }
    if (valorSerial == '3'){
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);



      
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinB, LOW);
      //delay(1000);

      /*
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinB, HIGH);
      */
    }
    if (valorSerial == '4'){
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);

      
      
      digitalWrite(pinF, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinDP, LOW);
      digitalWrite(pinC, LOW);
      //delay(1000);

      /*
      digitalWrite(pinF, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinDP, HIGH);
      digitalWrite(pinC, HIGH);
      */
    }
    if (valorSerial == '5'){
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);


      
      digitalWrite(pinG, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinB, LOW);
      //delay(1000);

      /*
      digitalWrite(pinG, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinB, HIGH);
      */
    }
    if (valorSerial == '6') {
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
    }
    if (valorSerial == '7') {
      delay(5000);
    }
  }

  
  if (buttonState == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}
