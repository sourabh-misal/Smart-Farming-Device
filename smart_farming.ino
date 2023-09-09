#include <SoftwareSerial.h>
SoftwareSerial bt(9, 8); // RX, TX

#include <LiquidCrystal.h> 
#include "dht.h"
#define dataPin A0
#define ms A1

int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

dht DHT;

int temp;
int hum;

int msensor_pin = A1 ;
int msoutput_value =0;

void setup() {
 
 Serial.begin(9600); 
 Serial.setTimeout(50);
 bt.begin(9600); 
 delay(1000);
 Serial.println("Reading From the Sensor ...");
 analogWrite(6,Contrast); 
 lcd.begin(16,2);  
 delay(1000);
}

void loop(){
  int readData = DHT.read11(dataPin);

   hum = DHT.humidity;
   temp = DHT.temperature;
   msoutput_value= analogRead(msensor_pin);

   int ms_temp = msoutput_value;
    
   Serial.print("Mositure:= ");
   Serial.println(msoutput_value);
   msoutput_value = map(msoutput_value,550,10,0,100);
   Serial.print("Mositure %:= ");
   Serial.print(msoutput_value);
   Serial.println("%");


   Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("% ");

  lcd.setCursor(0,1); 
  lcd.print("Temp: "); 
  lcd.print(temp); 
  lcd.print((char)223); 
  lcd.print("C ");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moisture: ");
  lcd.print(msoutput_value);
  lcd.print("% ");

  

 bt.print("Mositure: ");
 bt.print(msoutput_value); 
 delay(100);
 bt.println("%");
 bt.println("");
 bt.print("Temp: "); 
 bt.print(DHT.temperature); 
 delay(100);
 bt.println("c");
 bt.println("");
 delay(100);
 bt.print("Humidity: ");
 bt.print(DHT.humidity); 
 delay(100);
 bt.println("%");
 bt.println("");
delay(1000);
}