import cv2 as cv
import numpy as np

def empty(x):
    pass

cap = cv.VideoCapture(0)

cv.namedWindow("trackbar")
cv.resizeWindow("trackbar", 640, 240)
cv.createTrackbar("HUE min", "trackbar", 0, 179, empty)
cv.createTrackbar("HUE max", "trackbar", 179, 179, empty)
cv.createTrackbar("SAT min", "trackbar", 0, 255, empty)
cv.createTrackbar("SAT max", "trackbar", 255, 255, empty)
cv.createTrackbar("VALUE min", "trackbar", 0, 255, empty)
cv.createTrackbar("VALUE max", "trackbar", 255, 255, empty)

while True:
    _, frame = cap.read()
    hsvImage = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    hMin = cv.getTrackbarPos("HUE min", "trackbar")
    hMax = cv.getTrackbarPos("HUE max", "trackbar")
    sMin = cv.getTrackbarPos("SAT min", "trackbar")
    sMax = cv.getTrackbarPos("SAT max", "trackbar")
    vMin = cv.getTrackbarPos("VALUE min", "trackbar")
    vMax = cv.getTrackbarPos("VALUE max", "trackbar")

    lower = np.array([hMin, sMin, vMin])
    upper = np.array([hMax, sMax, vMax])

    mask = cv.inRange(hsvImage, lower, upper)

    cv.imshow("Gambar", frame)
    cv.imshow("Mask", mask)

    key = cv.waitKey(5)
    if key == 27:
        print(hMin, hMax, sMin, sMax, vMin, vMax)
        break


cv.destroyAllWindows()
