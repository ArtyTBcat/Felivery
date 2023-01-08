import serial
import keyboard

ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM5'
ser.open()

class run():
    def serialwrt(self):
        com = input("input here>    ")      
        # ser.write(com)
        ser.write(b'hello')

while True:
    if keyboard.is_pressed("w"): 
        ser.write(b'1')
        # print("w")
    elif keyboard.is_pressed("a"): 
        ser.write(b"2")
        # print("a")
    elif keyboard.is_pressed("s"): 
        ser.write(b"3")
        # print("s")
    elif keyboard.is_pressed("d"): 
        ser.write(b"4")
        # print("d")

    cc=str(ser.readline())
    print(cc[2:][:-5])
