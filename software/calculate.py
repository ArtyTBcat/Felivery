import math

line1 = 10 #DB
line2 = 3 #DA

cosStha = line2 / line1
print(cosStha)
angle = math.degrees(math.acos(cosStha))
print(f'cosAngle = {cosStha} angle = {angle}')