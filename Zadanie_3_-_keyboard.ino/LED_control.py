import serial
import threading
from pynput.keyboard import Key, Controller

def readArdu():
    while True:
        m = ser.readline()
        print("\nRead message: {}".format(m))
    print("Stop loop.")


def main():
    AL = threading.Thread(target=readArdu)
    AL.start()
    end = ''
    while end!='exit':
        print()
        print("1. Send test message.")
        print("2. Send your own message.")
        print("0. Exit")
        end = int(input())
        
        if end == 1:   
            ser.write(b'567')

        if end == 2:
            print("Choose pin: ")
            mess = str(input())
            print(bytes(mess,"UTF-8"))
            ser.write(bytes(mess, "UTF-8"))


'''
ser = serial.Serial("/dev/ttyACM0",9600)
main()
'''

try:
    ser = serial.Serial("/dev/ttyACM0",9600)
    print("Connected to port ttyACM0")
    main()
except:
    try:
        ser = serial.Serial("/dev/ttyACM1",9600)
        print("Connected to port ttyACM1")
        main()
    except:
        try:
            ser = serial.Serial("COM3",9600)
            print("Connected to port COM3")
            main()
        except:
            print("Brak polaczenia z portem.")

