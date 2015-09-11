const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redLEDPin = 11;

const int greenSensorPin = A1;
const int blueSensorPin = A2;
const int redSensorPin = A0;

int greenValue = 0;
int blueValue = 0;
int redValue = 0;

int greenSensorValue = 0;
int blueSensorValue = 0;
int redSensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.println(redSensorValue);
  Serial.print("\t Green: ");
  Serial.println(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);
  
  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.println(redValue);
  Serial.print("\t Green: ");
  Serial.println(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);
  

  analogWrite(greenLEDPin, greenValue);
  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);
}
