import time, pyautogui
time.sleep(3)
s = "We turn away to face the cold, enduring chill, as the day begs the night for mercy love. The sun so bright it leaves no shadows, only scars, carved into stone on the face of earth. The moon is up and over One Tree Hill we see the sun go down in your eyes."
lst = s.split(" ")
for i in lst:
    pyautogui.typewrite(i)
    time.sleep(0.00001)
    pyautogui.typewrite(" ")
pyautogui.press("enter")