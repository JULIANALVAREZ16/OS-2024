// C++ code
// Developer: Julian Alvarez

const int LED_PIN = 13; // Pin del LED
const int TEMPERATURE_PIN = A0; // Pin sensor de temperatura
const int MOTOR_PIN= 12; // Pin motor

void setup (){
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    pinMode(MOTOR_PIN, OUTPUT);
}

void loop(){
    float temp = analogRead(TEMPERATURE_PIN) * 0.48828125 - 50;
    if (temp < 5){
        digitalWrite(LED_PIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        delay(500);
        Serial.println("Temperatura muy baja. LED parpadeando.");
    }
    else if (temp >= 6 && temp <= 25){
        digitalWrite(LED_PIN, LOW);
        digitalWrite(MOTOR_PIN, LOW);
        Serial.println("Temperatura dentro del rango deseado. LED apagado.");
    }
    else if (temp > 25){
        digitalWrite(LED_PIN, LOW);
        digitalWrite(MOTOR_PIN, HIGH);
        Serial.println("Temperatura alta. Motor encendido.");
    }
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");
}
