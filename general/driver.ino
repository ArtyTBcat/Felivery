// coded by == Nontakorn
// project-- deliveryBot

#include "SoftPWM.h"
#include <Wire.h>

// MY_I2C_ADDRESS = 0x53
int slave_address = 0x53;

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

void setup()
{
  SoftPWMBegin();
  Wire.begin(slave_address); // join i2c bus (address optional for master)
  Serial.begin(20000);
}

void loop()
{
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