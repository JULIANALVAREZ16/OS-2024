// C++ code
// Developer: JULIAN ALVAREZ

#include <LiquidCrystal.h>

#define SENSOR_TMP A0
#define LED_PIN 13
#define MOTOR_PIN 10

int seconds = 0;

LiquidCrystal screen_lcd(12, 11, 5, 4, 3, 2);

void setup() {
screen_lcd.begin(16, 2);
Serial.begin(9600);
pinMode(LED_PIN, OUTPUT);
pinMode(MOTOR_PIN, OUTPUT);
screen_lcd.print("**Hello world!**");
}

void loop() {
  float temp = analogRead(SENSOR_TMP) * 0.488281225 - 50;

screen_lcd.setCursor(0, 1);
screen_lcd.print(seconds);
delay(1000);
seconds += 1;
screen_lcd.print(" ");
screen_lcd.print(temp);
screen_lcd.print("   ");
Serial.print("Temperatura: ");
Serial.print(temp);
Serial.println(" C");

if (isnan(temp)) {
    Serial.println("Error al leer la temperatura");
    return;
}

if (temp < 10.0) {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(MOTOR_PIN,LOW);
} else if (temp >= 11.0 && temp <= 24.0) {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(MOTOR_PIN, LOW); 
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(MOTOR_PIN, HIGH);
} 
}
