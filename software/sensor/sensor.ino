#include <Wire.h>
#include <SoftwareSerial.h>
// int SDA = 4;
// int SCL = 5;
float ultra_sonic[3]= {0,0,0};
int hall_sensor[4];

// pins
#define tx_GPS 3
#define rx_GPS 4
int ultrasonic_trig[3] = { 7, 9, 11 };
int ultrasonic_echo[3] = { 8, 10, 12 };

SoftwareSerial ss(rx_GPS, tx_GPS);

void setup() {
  Wire.begin(0);
  Serial.begin(115200);
  ss.begin(115200);
  Wire.onReceive(receiveEvent);
  for (int i = 0; i < 3; i++) {
    Serial.print(i);
    pinMode(ultrasonic_trig[i], OUTPUT);
    pinMode(ultrasonic_echo[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ultrasonic_trig[i], LOW);
    delayMicroseconds(2);
    float duration;
    digitalWrite(ultrasonic_trig[i], HIGH);
    delayMicroseconds(5);
    digitalWrite(ultrasonic_trig[i], LOW);
    duration = pulseIn(ultrasonic_echo[i], HIGH);
    ultra_sonic[i] = microsecondsToCentimeters(duration);
    Serial.print(ultra_sonic[i]); Serial.print("  ");
  }
  while (ss.available() > 0){
    // get the byte data from the GPS
    byte gpsData = ss.read();
    Serial.println(gpsData);
    Serial.println("---GPSData---");
  }

  Serial.println();
}



long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void receiveEvent(){
  for(int i = 0; i < 4; i++){
    hall_sensor[i] = Wire.read();
    // Serial.print(hall_sensor[i]);
  }
  // Serial.println();
}