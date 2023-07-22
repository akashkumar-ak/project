#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int soilMoistureValue = 0;

int percentage=0;

void setup() {
  
  pinMode(8,OUTPUT);

  Serial.begin(9600);

}

void loop() {

lcd.begin(16, 2);

soilMoistureValue = analogRead(A0);

Serial.println(percentage);

percentage = ( 100 - ( (soilMoistureValue/1023.00) * 100 ) );

lcd.setCursor(0,0);
lcd.print("Moisture: ");
lcd.print(percentage);
lcd.print("%");

if(percentage < 40)  

{

  Serial.println(" pump on");

  digitalWrite(8,LOW);

  
  lcd.setCursor(1,1);
  lcd.print("Motor ON");
  delay(1000);
}

if(percentage >60)

{

  Serial.println("pump off");

  digitalWrite(8,HIGH);
  lcd.setCursor(1, 1);
  lcd.print("Motor OFF");
  delay(1000);

}
}
