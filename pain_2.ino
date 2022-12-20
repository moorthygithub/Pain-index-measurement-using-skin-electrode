#include <Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);
const int LED=13;
const int GSR=A2;
int threshold=0;
int sensorValue;

void setup(){
  lcd.init();
  lcd.backlight();
  long sum=0;
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  delay(5);
  lcd.begin(16, 4);
  delay(100);
  for(int i=0;i<10;i++)
  {
  sensorValue=0;
  sum += sensorValue;
  delay(5);
  }
  threshold = sum/10;
   Serial.print("threshold =");
   Serial.println(threshold);
  }

void loop(){
  lcd.clear();  
  int painlevel;
  painlevel = 2;
  lcd.print("Pain level: ");//lcd displaying
  lcd.print(painlevel);
  delay(300);
  int temp;
  sensorValue=analogRead(GSR);
  Serial.print("sensorValue=");
  Serial.println(sensorValue);
  //delay(2000);  
  lcd.setCursor(0, 1);
  lcd.print("<=3-Normal");
  lcd.setCursor(0,2);
  lcd.print("<=7-Need Tablet");  
  lcd.setCursor(0,3);
  lcd.print("<=10-Meet Doctor");  
  //delay(5000);
  temp = threshold - sensorValue;
  if(abs(temp)>1)
  {
    sensorValue=analogRead(GSR);
    temp = threshold - sensorValue;
    if(abs(temp)>60){
    digitalWrite(LED,HIGH);
    Serial.println("Emotion Changes Detected!");
    //lcd.print("Emotion Changes Detected!");
    delay(3000);
    digitalWrite(LED,LOW);
    delay(5);
  }
 }
}
