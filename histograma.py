import cv2
import numpy
import sys
import base64
import time
import calendar

args = sys.argv[1:]

destPic_path = args[0]
encodedPic = args[1]

if (encodedPic[:2] != '/9'):
    encodedPic = encodedPic[27:]

picName = str(calendar.timegm(time.gmtime()))+".png"
tpic = open("/tmp/"+picName, "wb")
decodedPic = base64.b64decode(encodedPic)
tpic.write(decodedPic)
tpic.close()

img = cv2.imread(picName)
img_to_yuv = cv2.cvtColor(img, cv2.COLOR_BGR2YUV)
img_to_yuv[:, :, 0] = cv2.equalizeHist(img_to_yuv[:, :, 0])
hist_equalization_result = cv2.cvtColor(img_to_yuv, cv2.COLOR_YUV2BGR)

cv2.imwrite(destPic_path+picName+'.jpg', hist_equalization_result)