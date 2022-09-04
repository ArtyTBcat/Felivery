/*
MIT License
Copyright (c) 2022 ArtyTBcat
Author: Nontakorn Bunluesriruang
*/

#include "SoftPWM.h"
#include <Wire.h>

// MY_I2C_ADDRESS = 0x42
int slave_address = 0x42;
int x;

// please define Motors pwm pins
#define upRi_r 5
#define upRi_l 6
#define upLt_r 7
#define upLt_l 8
#define dnRi_r 9
#define dnRi_l 10
#define dnLt_r 11
#define dnLt_l 12

int myArray[8] = {upRi_r, upRi_l, upLt_r, upLt_l, dnRi_r, dnRi_l, dnLt_r, dnLt_l};
int incomingByte = 0;

void setup()
{
  SoftPWMBegin();
  Wire.begin(slave_address); // join i2c bus (address optional for master)
  Serial.begin(115200);
  Serial.setTimeout(1);
}

void loop()
{
  while (Serial.available()){
    int commands[5] = {0, 1, 2, 3, 4};
    x = Serial.readString().toInt();
    if (x == 0){stop();}
    else if (x == 1){motorControl(100, 0, 100, 100, 0, 100, 0, 100);Serial.println("fw");}
    else if (x == 2){motorControl(100, 0, 100, 100, 0, 100, 0, 100);Serial.println("bk");}
    else if (x == 3){motorControl(100, 0, 100, 100, 0, 100, 0, 100);Serial.println("lf");}
    else if (x == 4){motorControl(100, 0, 100, 100, 0, 100, 0, 100);Serial.println("rt");}
  }
}

void motorControl(int URR, int URL, int ULR, int ULL, int DRR, int DRL, int DLR, int DLL)
{
  int define[8] = {URR, URL, ULR, ULL, DRR, DRL, DLR, DLL};
  for (int i = 0; i < 8; i++)
  {
    SoftPWMSetPercent(myArray[i], define[i]);
  }
}
void stop()
{
  for (int i = 0; i < 8; i++)
  {
    SoftPWMSetPercent(myArray[i], 0);
  }
}

void hardStop()
{
  for (int i = 0; i < 8; i++)
  {
    SoftPWMSetPercent(myArray[i], 100);
  }
}

float read_from_main()
{
  float temp;
  String dataStr = "";
  while (Wire.available())
  {
    char c = Wire.read();
    dataStr = dataStr + c;
    temp = dataStr.toFloat();
  }
  return temp;
}
