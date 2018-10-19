import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(12, GPIO.OUT)

dioda = GPIO.PWM(12,100)
w = 0
dioda.start(w)

try:
    while True:
        w += 5
        if w > 100:
            w = 0
        dioda.ChangeDutyCycle(w)
        time.sleep(0.05)
except KeyboardInterrupt:
    print('Koniec')

dioda.stop()
GPIO.cleanup()