import cv2 as cv

cap = cv.VideoCapture(0)

while 1:
    _, image = cap.read()
    blurImg = cv.GaussianBlur(image, (3, 3), sigmaX=0, sigmaY=0)
    canny = cv.Canny(blurImg, 100, 200)
    cv.imshow("canny", canny)
    key = cv.waitKey(5)
    if key == 27:
        break
