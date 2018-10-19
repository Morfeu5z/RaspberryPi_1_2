import random
import time
import Adafruit_CharLCD as LCD


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

# Print a two line message
# lcd.message('Hello\nworld!')

# time.sleep(5.0)
# lcd.clear()

for x in range(10):
    value = random.randint(0,99)
    value = bin(value)
    lcd.clear()
    lcd.message(str(value))
    time.sleep(1.0)

lcd.clear()
lcd.message("Ending program...")
time.sleep(1.0)
