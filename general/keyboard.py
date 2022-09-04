import serial
import time
import keyboard

arduino = serial.Serial(port='COM6', baudrate=115200, timeout=.1)

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

while True:
    if keyboard.is_pressed('w'): write_read(1)
    elif keyboard.is_pressed('s'): write_read(2)
    elif keyboard.is_pressed('a'): write_read(3)
    elif keyboard.is_pressed('d'): write_read(4)
    else: write_read(0)
