import cv2

# Load the cascade
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

old_x = 0
old_y = 0
detect = 0

cap = cv2.VideoCapture(0)
while(True):
    _ , img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Detect faces
    faces = face_cascade.detectMultiScale(gray, 1.1, 4)
    # Draw rectangle around the faces
    for (x, y, w, h) in faces:
        if detect==0:
            old_x = x
            old_y = y
        detect = 1
        cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)
        if old_x<x:
            #Turn Right
            pass
        elif old_x>x:
            #Turn Left
            pass
        elif old_y<y:
            #Forward
            pass
        elif old_y>y:
            #Bacckward
            pass
        old_x = x
        old_y = y
    # Display the output
    cv2.imshow('img', img)
    cv2.waitKey()
