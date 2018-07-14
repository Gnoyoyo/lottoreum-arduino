#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define Button 12
#define Light 6
#define LightSource 5

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

TM1637Display display(CLK, DIO);

int buttonState;

void setup()
{
  pinMode(Button, INPUT);
  pinMode(Light, OUTPUT);
  pinMode(LightSource, OUTPUT);
  digitalWrite(Light, LOW);
  digitalWrite(LightSource, HIGH);

  Serial.begin(9600); // the bigger number the better

}

void loop()
{
  digitalWrite(Light, LOW);
  int k;
  int x;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);


  buttonState = digitalRead(Button);

  Serial.println(buttonState);

  if (buttonState == 1) {

    digitalWrite(Light, HIGH);


    for (x = 10; x >= 0 ; x--) {

      display.showNumberDec(x, true);
      delay(1000);
    }

  } else {
    digitalWrite(Light, LOW);
  }

  digitalWrite(Light, LOW);

}
