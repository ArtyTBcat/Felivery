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

    def getData():
        pass


class dataModule:  # Sensors Data
    # data format
    # [[latitude, longitude], [rangeSensor, rangeSensor, rangeSensor]]
    pass
