/*
MIT License
Copyright (c) 2022 ArtyTBcat
Author: Nontakorn Bunluesriruang
*/

//define Ultrasonic pins
#define trig_r 3
#define echo_r 4
#define trig_c 5
#define echo_c 6
#define trig_l 7
#define echo_l 8

int slave_address = 0x53;
int inputPins[3] = {echo_r, echo_c, echo_l};
int outputPins[3] = {trig_r, trig_c, trig_l};

void setup(){    
    for (int i = 0; i <= 3; i++) {
        pinMode(inputPins[i], INPUT);
        pinMode(outputPins[i], OUTPUT);
    }
}

void loop(){

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
