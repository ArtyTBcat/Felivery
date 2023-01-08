#include <Wire.h>
// pcb Hall sensor name n$1 n$4 n$5 n$7 
// D3 D5 D7 D9

int hall_pins[4] = {3, 5, 7, 9};
int sensorVal[4];

void setup() {
  Serial.begin(115200);
  Wire.begin(0);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  pinMode(9, INPUT);

}

void loop() {
  Wire.beginTransmission(0); //address is queued for checking if the slave is present
  for (int i=0; i<4; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    int value = digitalRead(hall_pins[i]);
    Wire.write(value);
    sensorVal[i] = value;
    Serial.print(value); Serial.print("  ");
  }
  Wire.endTransmission();

  Serial.println();
  digitalWrite(LED_BUILTIN, LOW);

  delay(50);

}

