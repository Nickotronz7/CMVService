import cv2

img = cv2.imread('B.jpeg')
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
if(R > B):
    if(R > G):
        print("rojo")
    else:
        print("verde")
else:
    if(B > G):
        print("azul")
    else:
        print("verde")
