#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(57600);
}

void loop() {
  Wire.requestFrom(8, 6);

  while (Wire.available()) {
    char byte = Wire.read();
    Serial.print(byte);
  }
  Serial.println();

}
