import asyncio

import cv2
from cvzone.HandTrackingModule import HandDetector
from time import sleep
import numpy as np
import cvzone
import pygame

pygame.mixer.init()

cap = cv2.VideoCapture(0)
cap.set(3, 1280)
cap.set(4, 720)

detector = HandDetector(detectionCon=0.8)
keys = [["C", "D", "E", "F", "G", "A", "B"]]


def drawAll(img, buttonList):
    for button in buttonList:
        x, y = button.pos
        w, h = button.size
        cvzone.cornerRect(img, (button.pos[0], button.pos[1], button.size[0], button.size[1]),
                          20, rt=0)
        cv2.rectangle(img, button.pos, (x + w, y + h), (255, 0, 255), cv2.FILLED)
        cv2.putText(img, button.text, (x + 20, y + 65),
                    cv2.FONT_HERSHEY_PLAIN, 4, (255, 255, 255), 4)
    return img


class Button():
    def __init__(self, pos, text, size=[85, 85]):
        self.pos = pos
        self.size = size
        self.text = text


async def play(text):
    await asyncio.sleep(1.0)
    pygame.mixer.Sound("audios/" + text.lower() + ".wav").play(maxtime=1000)


buttonList = []
for i in range(len(keys)):
    for j, key in enumerate(keys[i]):
        buttonList.append(Button([100 * j + 50, 100 * i + 50], key))

while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)
    img = drawAll(img, buttonList)
    play = False

    if hands:
        hand1 = hands[0]
        lmList = hand1["lmList"]

        for button in buttonList:
            x, y = button.pos
            w, h = button.size
            dx = lmList[8][0] - lmList[4][0]
            dy = lmList[8][1] - lmList[4][1]
            dis = np.sqrt(dx * dx + dy * dy)

            if x < lmList[8][0] < x + w and y < lmList[8][1] < y + h and dis < 100:
                cv2.rectangle(img, (x - 5, y - 5), (x + w + 5, y + h + 5), (175, 0, 175), cv2.FILLED)
                cv2.putText(img, button.text, (x + 20, y + 65),
                            cv2.FONT_HERSHEY_PLAIN, 4, (255, 255, 255), 4)
                l, _, _ = detector.findDistance((x, y), (lmList[8][0], lmList[8][1]), img)
                print(l)

                if l < 60:
                    pygame.mixer.Sound("audios/" + button.text.lower() + ".wav").play(maxtime=1000)
                    cv2.rectangle(img, button.pos, (x + w, y + h), (0, 255, 0), cv2.FILLED)
                    cv2.putText(img, button.text, (x + 20, y + 65),
                                cv2.FONT_HERSHEY_PLAIN, 4, (255, 255, 255), 4)
                    sleep(0.2)

    cv2.imshow("Image", img)
    cv2.waitKey(1)


