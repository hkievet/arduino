const int sensorPin = A0;
const float baselineTemp = 20.0;
const int coldLight = 3;
const int comfLight = 4;
const int warmLight = 5;
const int hotLight = 6;



void setup(){
  for (int i=3;i<7;i++){
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop(){
  int tempRead = analogRead(sensorPin);
  float voltage = getVoltage(tempRead);
  float celsius = getCelsius(voltage);
  float farenheit = getFarenheit(celsius);

  for (int i=3;i<7;i++){
    digitalWrite(i, LOW);
  }

  if (tempRead <= 149) {
    digitalWrite(coldLight, HIGH);
  }
  else if (tempRead <= 153) {
    digitalWrite(comfLight, HIGH);
  }
  else if (tempRead <= 156) {
    digitalWrite(warmLight, HIGH);
  }
  else if (tempRead <= 160) {
    digitalWrite(hotLight, HIGH);
  }

  Serial.print("\n\nSensor Value: ");
  Serial.print(tempRead);
  Serial.print("\nVoltage: ");
  Serial.print(voltage);
  Serial.print("\nCelsius: ");
  Serial.print(celsius);
  Serial.print("\nFarenheit: ");
  Serial.print(farenheit);
  delay(1000);
}

float getVoltage(int tempRead){
  return (tempRead/1024.0) * 5.0;
}

float getCelsius(float voltage){
  return (voltage - .5) * 100;
}

float getFarenheit(float celsius){
  return (celsius * 1.8) + 32;
}


