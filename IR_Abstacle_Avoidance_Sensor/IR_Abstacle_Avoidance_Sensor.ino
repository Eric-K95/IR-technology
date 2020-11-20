//IR Obstacle Avoidance Sensor
//Skeched by JIN-WOO KIM

#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int buzzerPin = 6;
const int avoidPin = 3;
int ledPin1 = 13;
int ledPin2 = 12;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(avoidPin, INPUT);
  lcd.begin();
  lcd.setCursor(5, 0); //first column, row #5
  lcd.print("Hello!");
  lcd.setCursor(0, 1); //second column, row #1
  lcd.print("MECHATRONICS:)");
  delay(2000);   //delay of the message
  lcd.clear();   // clear screen
  lcd.setCursor(0, 0); //first column, row #1
  lcd.print("IR Abstacle");
  lcd.setCursor(0, 1); //second column, row #1
  lcd.print("Avoidance Sensor");
  delay(2000); //delay 2000ms
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  boolean avoidVal = digitalRead(avoidPin);
  if (avoidVal == LOW) //if LOW, object is closer
  { Serial.println("Object is detected!!!!!!!");
    lcd.setCursor(0,0); // first coulumn, first low
    lcd.print("State:"); //print the message on LCD screen
    lcd.setCursor(0,1); // second coulumn, second low
    lcd.print("ObstacleIsDetected"); //print the message on LCD screen
    digitalWrite(ledPin1, HIGH); //turn on the redLED
    digitalWrite(ledPin2, LOW); //blueLED stays LOW
    tone(buzzerPin, 1000,500);
    lcd.clear();
  }
  else {
    Serial.println("No Obstacle");
    lcd.setCursor(0,0); // first coulumn, first low
    lcd.print("State:"); //print the message on LCD screen
    lcd.setCursor(2,1); // second coulumn, third low
    lcd.print("No Obstacle"); //print message on LCD screen
    digitalWrite(ledPin2, HIGH); //turn on the blueLED
    digitalWrite(ledPin1, LOW); //redLED stays LOW
    noTone(buzzerPin);
  }
}
