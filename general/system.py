# !/bin/bash
# Copyright 2022 Google LLC
# Author: Nontakorn Bunluesriruang

from matplotlib import pyplot as plt
import numpy as np
import math
from math import sin, cos, tan

# this is the list of Data  that the arduino will send need to write serial Communication
# [[GPSlocation(x,y)], [sensor1, sensor2, sensor3(meter)]] old -> new
serialData = [[[13.355262068371927, 100.9770627872032],  [5, 5, 5]], [
    [13.346638176680193, 100.95625298165196], [5, 5, 4.5]]]


# this is a class that will decode, find heading and GPS coordinates from the data provided from the Arduino
class arduData:
    locationArray = []
    sensorData = None

    def decode(self):
        arduData.sensorData = serialData[-1][1]
        for array in serialData:
            arduData.locationArray.append(array[0])

    def initial_compass_bearing(pointA, pointB):
        # find the bearing heading between pointA and pointB
        # dl = atan2(sin(Δlong).cos(lat2),cos(lat1).sin(lat2) − sin(lat1).cos(lat2).cos(Δlong))
        # ---Parameters---
        #   - `pointA: The tuple representing the latitude/longitude for the
        #     first point. Latitude and longitude must be in decimal degrees
        #   - `pointB: The tuple representing the latitude/longitude for the
        #     second point. Latitude and longitude must be in decimal degrees

        # ----Return----
        #   The bearing in degrees

        if (type(pointA) != tuple) or (type(pointB) != tuple):
            raise TypeError("Only tuples are supported as arguments")
        lat1 = math.radians(pointA[0])
        lat2 = math.radians(pointB[0])
        diffLong = math.radians(pointB[1] - pointA[1])
        x = math.sin(diffLong) * math.cos(lat2)
        y = math.cos(lat1) * math.sin(lat2) - (math.sin(lat1)
                                               * math.cos(lat2) * math.cos(diffLong))

        initial_bearing = math.atan2(x, y)
        initial_bearing = math.degrees(initial_bearing)
        compass_bearing = (initial_bearing + 360) % 360

        return compass_bearing


arduData().decode()
print(arduData.initial_compass_bearing((13.36126111571239,
      100.98905732794863), (13.367541208480262, 100.99165855364252)))
