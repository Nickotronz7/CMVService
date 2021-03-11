from cv2 import cv2
import numpy
import sys
import base64
import time
import calendar
from shutil import copyfile

args = sys.argv[1:]

destPic_path = args[0]
encodedPic = args[1]

if (encodedPic[:2] != '/9'):
    encodedPic = encodedPic[27:]

picName = str(calendar.timegm(time.gmtime()))+".jpg"
tpic = open("/tmp/"+picName, "wb")
decodedPic = base64.b64decode(encodedPic)
tpic.write(decodedPic)
tpic.close()

img = cv2.imread("/tmp/"+picName,)

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
    copyfile("/tmp/"+picName, destPic_path+'R/'+picName)
elif (iMax == 1):
    copyfile("/tmp/"+picName, destPic_path+'G/'+picName)
else:
    copyfile("/tmp/"+picName, destPic_path+'B/'+picName)
