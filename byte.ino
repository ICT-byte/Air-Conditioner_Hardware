#include <LiquidCrystal_I2C.h>     //LiquidCrystal 
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  //lcd 

Servo ser; //서브모터
int servo = 2;

void setup()
{
    lcd.init(); //초기 lcd 설정
    lcd.backlight();

    ser.attach(servo); //초기 서브모터 설정
    ser.write(0);
}

void loop()
{
    int value = digitalRead(7);
    
    if(value == LOW){ //에어컨 off
      lcd.setCursor(6, 0);
      lcd.print("OFF");
      ser.write(0);
    }
    else{ //에어컨 on
      lcd.setCursor(7, 0);
      lcd.print("ON");
      ser.write(90);
    }
    delay(100);
    lcd.clear();
}
