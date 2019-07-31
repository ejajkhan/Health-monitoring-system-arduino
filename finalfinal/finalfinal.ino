#include <LiquidCrystal.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 9

SoftwareSerial mySerial(rxPin, txPin);
LiquidCrystal lcd(1, 2 , 4, 5, 6, 7);
float temp;
int Signal;


void setup() {
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Hello world");
  

}

void loop() {
  lcd.clear();
  lcd.print("Temprature :");
  mySerial.print("Temprature :");
  temp=analogRead(A0);
  Signal = analogRead(A1);
  Signal=(Signal/8);
  temp=temp*0.48828125;
  lcd.print(temp);
  mySerial.print(temp);
  lcd.setCursor(0,1); 
  lcd.print("HeartBeat :");
  mySerial.print("HeartBeat :");
  lcd.print(Signal);
  mySerial.println(Signal);
  delay(1000);
  
}
