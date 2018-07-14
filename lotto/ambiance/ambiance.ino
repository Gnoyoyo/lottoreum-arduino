#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define Button 12
#define Light 6
#define LightSource 5
#define RedLight 10
#define GreenLight 9


TM1637Display display(CLK, DIO);

int buttonState;

void setup()
{
  pinMode(Button, INPUT);
  pinMode(Light, OUTPUT);
  pinMode(LightSource, OUTPUT);
  pinMode(GreenLight, OUTPUT);
  pinMode(RedLight, OUTPUT);
  digitalWrite(Light, LOW);
  digitalWrite(LightSource, HIGH);
  digitalWrite(GreenLight, LOW);
  digitalWrite(RedLight, HIGH);

  Serial.begin(9600); // Serial Bud rate

}

void loop()
{
  digitalWrite(Light, LOW);
  digitalWrite(RedLight, HIGH);
  digitalWrite(GreenLight, LOW);
  int k;
  int x;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);


  buttonState = digitalRead(Button);

  Serial.println(buttonState);

  if (buttonState == 1) {

    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, HIGH);
    digitalWrite(Light, HIGH);


    for (x = 10; x >= 0 ; x--) {

      display.showNumberDec(x, true);
      delay(1000);
    }

  } else {
    digitalWrite(Light, LOW);
  }
}
