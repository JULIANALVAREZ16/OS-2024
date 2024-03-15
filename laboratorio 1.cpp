// C++ code
// Developer: JULIAN ALVAREZ

const int LED_GREEN = 11;
const int LED_YELLOW = 13;
const int LED_RED = 12;
boolean intermitence;

void setup()
{
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  Serial.begin(9600); // Baudios
  Serial.println("*** Menu ***");
  Serial.println("[1] Turn on led green");
  Serial.println("[2] Turn off led green");
  Serial.println("[3] Turn on led red");
  Serial.println("[4] Turn off led red");
  Serial.println("[5] Turn on led yellow");
  Serial.println("[6] Turn off led yellow");
  Serial.println("[7] Turn on leds green, red and yellow");
  Serial.println("[8] Turn off leds green, red and yellow");
  Serial.println("[9] Turn on/off the leds green, red, and yellow");
  Serial.println("** Please, press your option");
}

void led_intermitence()
{
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  delay(1000);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  delay(1000);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char opt = Serial.read();
    switch (opt)
    {
    case '1':
      digitalWrite(LED_GREEN, HIGH);
      Serial.println("Green led has been turned on");
      intermitence = false;
      break;
    case '2':
      digitalWrite(LED_GREEN, LOW);
      Serial.println("Green led has been turned off");
      intermitence = false;
      break;
    case '3':
      digitalWrite(LED_RED, HIGH);
      Serial.println("Red led has been turned on");
      intermitence = false;
      break;
    case '4':
      digitalWrite(LED_RED, LOW);
      Serial.println("Red led has been turned off");
      intermitence = false;
      break;
    case '5':
      digitalWrite(LED_YELLOW, HIGH);
      Serial.println("Yellow led has been turned on");
      intermitence = false;
      break;
    case '6':
      digitalWrite(LED_YELLOW, LOW);
      Serial.println("Yellow led has been turned off");
      intermitence = false;
      break;
    case '7':
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      intermitence = false;
      break;
    case '8':
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      intermitence = false;
      break;
    case '9':
      intermitence = true;
      break;
    default:
      Serial.println("Press a correct option");
      break;
    }
  }

  if (intermitence)
  {
    led_intermitence();
  }
}
