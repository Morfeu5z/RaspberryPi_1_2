import random
import time
import Adafruit_CharLCD as LCD
import Adafruit_DHT


# Raspberry Pi pin configuration:
lcd_rs        = 25#= 22  # Note this might need to be changed to 21 for older revision Pi's.
lcd_en        = 24#= 18
lcd_d4        = 23#= 16
lcd_d5        = 17#= 12
lcd_d6        = 18#= 13
lcd_d7        = 22#= 15
lcd_backlight = 2

# Define LCD column and row size for 16x2 LCD.
lcd_columns = 16
lcd_rows    = 2

# Initialize the LCD using the pins above.
lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7,
                           lcd_columns, lcd_rows, lcd_backlight)

# DHT11 config 
dht_type        = Adafruit_DHT.DHT11
dht_data_pin    = 26

def lesson_1():
    humidity, temperature = Adafruit_DHT.read_retry(dht_type, dht_data_pin)
    if humidity is not None and temperature is not None:
        try:
            humidity, temperature = Adafruit_DHT.read_retry(dht_type, dht_data_pin)
            message = ('{0:0.1f}\'C=Temp.\n{1:0.1f} %=Humd.'.format(temperature, humidity))
            print(message)
            lcd.clear()
            lcd.message(message)
            time.sleep(3)
        except (KeyboardInterrupt):
            print("bye!")
            sys.exit(1)
    else:
        print("[!] ERROR")
        sys.exit(1)


# Zadanie 2 - losowanie liczb binarnych
def lesson_2():
    value = random.randint(0,99) # Get random value 0-99
    #---
    a_bin = int(value / 10) # Get first number
    a_bin = bin(a_bin)      # Convert to binary
    a_bin = a_bin[2:]       # Delate 0b
    a_len = 4 - len(a_bin)  # Get length a_bin
    #---
    b_bin = value % 10      # Get last number
    b_bin = bin(b_bin)      # Convert to binary
    b_bin = b_bin[2:]       # Delete 0b
    b_len = 4 - len(b_bin)  # Get length b_bin
    #---
    addzero = '' 
    for x in range(a_len):
        addzero = addzero + "0"
    a_bin = addzero + a_bin     # Add '0' on start
    #---
    addzero = ''
    for x in range(b_len):
        addzero = addzero + "0"
    b_bin = addzero + b_bin     # Add '0' on start
    #---
    print('DEC: {}\nBCD: {}.{}'.format(value, a_bin, b_bin))
    #---
    lcd.clear()
    lcd.message('DEC: ' + str(value) + '\nBCD: ' + str(a_bin) + "." + str(b_bin))
    time.sleep(3.0)
    lcd.clear()


# MENU
doit = 9
while doit != 0:
    lcd.clear()
    lcd.message("Zad: 1 or 2\nExit: 0")

    print()
    print('1. Zadanie 1 - temperatura\n2. Zadanie 2 - BCD\n0. Zakoncz')
    doit = int(input())
    
    if doit == 1:
        lesson_1()

    if doit == 2:
        lesson_2()

print("Ending program...")
lcd.clear()
lcd.message("Ending\nprogram...")
time.sleep(1.0)
lcd.clear()
