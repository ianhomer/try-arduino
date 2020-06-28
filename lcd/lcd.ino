/*
  LiquidCrystal Library - Hello World

 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 Library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 Example added 9 Jul 2009
 by Tom Igoe
 Modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int buttonPin = 4;
int ledPin = 5;
long offset = 5000;
int buttonState = 0;
int buttonPreviousState = 0;
int explodingCount = 0;
int flashSpeed = 1000;
long count = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  // Print a message to the LCD.
  display();
}

void display() {
  lcd.setCursor(0,0);
  if (buttonState == LOW) {
    if (explodingCount < 200) {
      flashSpeed = 1000;
      lcd.print("stop pressing me");
    } else if (explodingCount < 800) {
      lcd.print("fool, stop it    ");
      flashSpeed = 200;
    } else if (explodingCount < 1200) {
      flashSpeed = 100;
      lcd.print("... DANGER ......... ");
    } else {
      flashSpeed = 50;
      lcd.print("BANG!!!!!!!!!!!!");
    }
  } else {
    lcd.print("cows : ");
    lcd.print(buttonState);
    lcd.print(":");
    lcd.print(count);
    lcd.print(":");
    lcd.print(digitalRead(buttonPin));
  }
}

void flash() {
  int on = (millis() / flashSpeed) % 2;
  if (on == 1) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  } 
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != buttonPreviousState) {
    buttonPreviousState = buttonState;
    count++;
  }
  if (buttonState == LOW) {
    offset += 1000;
    explodingCount++;
    flash();
  } else {
    explodingCount = 0;
    digitalWrite(ledPin, LOW);
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 193);
  // print the number of seconds since reset:
  lcd.print(offset + (millis() / 1000));
  display();
}
