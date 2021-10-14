main_boo = True


try :
    import pyautogui , time , os
    print("imported")
except:
    print("Woops! ")
    print(""" Pyautogui is not installed in your System
    for installin pls enter the following command in your terminal 
     [pip install pyautogui]  """)
    main_boo = False


if os.name != "nt":
    main_boo = False
    print("Windows Os is required")


if not(main_boo):
    while True:
        pass


boo = True


while main_boo:
    if boo:
        rnge = int(2)

        for i in range(101):
            time.sleep(0.1)
            print(f"Loading {i}%\r", end='')

    if boo:
        for i in range(rnge):
            pyautogui.press("win")
            pyautogui.typewrite("Notepad")
            pyautogui.press("enter")
            pyautogui.hotkey("win", "up")
            pyautogui.typewrite("Lol got you ")
            boo = False
        
        for i in range(3):
            pyautogui.hotkey("win", "r")
            pyautogui.typewrite("chrome")
            pyautogui.press("enter")
            time.sleep(1)
            pyautogui.hotkey("ctrl", "l")
            pyautogui.typewrite("https://www.youtube.com/watch?v=dQw4w9WgXcQ")
            pyautogui.press("enter")