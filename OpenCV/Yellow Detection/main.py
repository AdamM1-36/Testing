import numpy as np
import cv2 as cv

cap = cv.VideoCapture(0)

#yellow
yl = np.array([17, 106, 56])
yu = np.array([32, 255, 255])

while 1:
    _, frame = cap.read()
    hsvImage = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
    yMask = cv.inRange(hsvImage, yl, yu)
    yCont, _ = cv.findContours(yMask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    if len(yCont)!=0:
        for ct in yCont:
            if cv.contourArea(ct) > 5000:
                print('yellow detected')
    cv.imshow('tes', yMask)
    key = cv.waitKey(5)
    if key == 27:
        break
