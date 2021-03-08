import cv2
import numpy
import sys
import base64
import time
import calendar
from shutil import copyfile

args = sys.argv[1:]

destPic_path = args[0]
encodedPic = args[1]

picName = str(calendar.timegm(time.gmtime()))+".png"
tpic = open("/tmp/"+picName, "wb")
decodedPic = base64.b64decode(encodedPic)
tpic.write(decodedPic)
tpic.close()

img = cv2.imread(picName)

img_shape = img.shape
height = img_shape[0]
width = img_shape[1]
R = 0
G = 0
B = 0

for row in range(width):
    for column in range(height):
        B = B+(img[column][row][0])
        G = G+(img[column][row][1])
        R = R+(img[column][row][2])

colors = [R, G, B]

iMax = colors.index(max(colors))

if (iMax == 0):
    copyfile("/tmp/"+picName, destPic_path+'R/')
elif (iMax == 1):
    copyfile("/tmp/"+picName, destPic_path+'G/')
else:
    copyfile("/tmp/"+picName, destPic_path+'B/')
