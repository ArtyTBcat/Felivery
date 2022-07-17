# MIT License
# Copyright (c) 2022 ArtyTBcat
# Author: Nontakorn Bunluesriruang

from pyb import I2C

i2c = I2C(2, I2C.MASTER)             # create and init as a master
i2c.init(I2C.MASTER, baudrate=20000)


class driver:  # Control Motor
    ADDRESS = 0x42
    PROTOCOL = ["nr", "sp", "hs"]

    def control(colNum: int, motor: list):
        command = [driver.PROTOCOL[colNum], motor]
        i2c.send(str(command), driver.ADDRESS)

class dataModule:  # Sensors Data
    ADDRESS = 0x53
    # data format : [[latitude, longitude], [rangeSensor, rangeSensor, rangeSensor]]
    
    def reciveData():
        amountBytes = int(i2c.recv(2)) # get amount bytes
        data = bytearray(amountBytes)  # create a buffer
        i2c.recv(data)
        return list(data)

