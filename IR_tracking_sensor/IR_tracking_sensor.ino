//TCRT 5000 IR Tracking Sensor
//Skeched by JIN-WOO KIM

#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int buzzerPin = 6;
const int trackingPin = 3;
const int ledPin = 13; //pin13 built-in led

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(trackingPin, INPUT);
  lcd.begin();
  lcd.setCursor(5, 0); //fifth column, row #1
  lcd.print("Hello!");
  lcd.setCursor(0, 1); //first column, row #2
  lcd.print("MECHATRONICS:)");
  delay(2000);   //delay of the message
  lcd.clear();   // clear screen
  lcd.setCursor(0, 0); //first column, row #1
  lcd.print("TCRT5000");
  lcd.setCursor(0, 1); //first column, row #2
  lcd.print("IR Tracking");
  delay(2000); //delay 2000ms
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  boolean val = digitalRead(trackingPin); //read the value of tracking module
  if (val == HIGH) //if it is HIGH
  { digitalWrite(ledPin, LOW); //turn off the led
    Serial.println("Detect: Black");
    noTone(buzzerPin);
    lcd.setCursor(0, 0); //first column, row #1
    lcd.print("Detect:");
    lcd.setCursor(8, 0); //eight column, row #2
    lcd.print("Black");
  }
  else {
    digitalWrite(ledPin, HIGH);
    Serial.println("Detect: White");
    lcd.setCursor(0, 0); //first column, row #1
    lcd.print("Detect:");
    lcd.setCursor(8, 0); //eight column, row #2
    lcd.print("White");
    tone(buzzerPin, 1000, 500);
  }
}
