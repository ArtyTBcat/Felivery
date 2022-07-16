/*
MIT License
Copyright (c) 2022 ArtyTBcat
Author: Nontakorn Bunluesriruang
*/

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//define Ultrasonic pins
#define gpsRX 3
#define gpsTX 4
#define trig_r 5
#define echo_r 6
#define trig_c 7
#define echo_c 8
#define trig_l 9
#define echo_l 10

int slave_address = 0x53;
int inputPins[3] = {echo_r, echo_c, echo_l};
int outputPins[3] = {trig_r, trig_c, trig_l};

TinyGPSPlus gps;
SoftwareSerial ss(gpsRX, gpsTX);

void setup(){
    ss.begin(GPSBaud);
    for (int i = 0; i <= 3; i++) {
        pinMode(inputPins[i], INPUT);
        pinMode(outputPins[i], OUTPUT);
    }
}

void loop()
{
    while (ss.available() > 0) {
        gps.encode(ss.read());
        if (gps.location.isUpdated()) {
            // Latitude in degrees (double)
            Serial.print("Latitude= ");
            Serial.print(gps.location.lat(), 6);
            // Longitude in degrees (double)
            Serial.print(" Longitude= ");
            Serial.println(gps.location.lng(), 6);
            // speed km/hr
            Serial.print("Speed in km/h = ");
            Serial.println(gps.speed.kmph());
            // Course in degrees (double)
            Serial.print("Course in degrees = ");
            Serial.println(gps.course.deg());
            // Altitude in meters (double)
            Serial.print("Altitude in meters = ");
            Serial.println(gps.altitude.meters());
        }
    }
}

float range(){
    //send pulse
    for (int i = 0; i<= 3; i++){
        digitalWrite(outputPins[i], HIGH);
    }
    delayMicroseconds(10);
    for (int i = 0; i<= 3; i++){
        digitalWrite(outputPins[i], LOW);
    }
    // end sending pulse

    // find distance between pulse
    float rangeCM[];
    for (int i = 0; i<= 3; i++){
        duration = pulseIn(echoPin[i], HIGH);
        distance = duration * 0.034 / 2;
        rangeCM[i] = distance;
    }
    // end find
    return rangeCM;
}
