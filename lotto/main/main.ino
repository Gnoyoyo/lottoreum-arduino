#include <Arduino.h>
#include <TM1637Display.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>;

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define Button 12
#define Light 6
#define LightSource 5
#define RedLight 10
#define GreenLight 9
#define ONE_WIRE_BUS 52
#define DHTPIN 45
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht1(DHTPIN, DHTTYPE);

TM1637Display display(CLK, DIO);

int buttonState;


//Setup One Wire
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

//Assign Sensor
DeviceAddress sensorHand1 = { 0x28, 0xFF, 0xEE, 0xBA, 0x84, 0x16, 0x05, 0x3F };
DeviceAddress sensorHand2 = { 0x28, 0xFF, 0x1A, 0x46, 0x84, 0x16, 0x03, 0x38 };
DeviceAddress sensorHand3 = { 0x28, 0xFF, 0xE8, 0x3F, 0x85, 0x16, 0x05, 0x50 };
DeviceAddress sensorHand4 = { 0x28, 0xFF, 0xBE, 0x48, 0xB3, 0x16, 0x05, 0x78 };

float Temp1;

void setup()
{
  pinMode(Button, INPUT);
  pinMode(Light, OUTPUT);
  pinMode(LightSource, OUTPUT);
  pinMode(GreenLight, OUTPUT);
  pinMode(RedLight, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(30, OUTPUT);
  digitalWrite(26, HIGH);
  digitalWrite(30, LOW);
  digitalWrite(LightSource, HIGH);
  digitalWrite(GreenLight, LOW);
  digitalWrite(RedLight, HIGH);

  Serial.begin(9600); // Serial Bud rate

  sensors.begin();

  sensors.setResolution(sensorHand1, 12);
  sensors.setResolution(sensorHand2, 12);
  sensors.setResolution(sensorHand3, 12);
  sensors.setResolution(sensorHand4, 12);

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


    for (x = 20; x >= 15 ; x--) {
      display.showNumberDec(x, true);
      delay(1000);
    }

    readPower();

    for (x = 15; x >= 0 ; x--) {
      display.showNumberDec(x, true);
      delay(1000);
    }

  } else {
    digitalWrite(Light, LOW);
  }
}

float getTemperature(DeviceAddress deviceAddress)
{
  float tempC;
  //sensors.requestTemperatures();
  tempC = sensors.getTempC(deviceAddress);
  return (tempC);
}

void readPower()
{
  sensors.requestTemperatures();
  delay(1000);

  Serial.print(getTemperature(sensorHand1));
  Serial.print(";");
  Serial.print(getTemperature(sensorHand2));
  Serial.print(";");
  Serial.print(getTemperature(sensorHand3));
  Serial.print(";");
  Serial.print(getTemperature(sensorHand4));
  Serial.print(";");
  Serial.print(dht1.readTemperature());
  Serial.print(";");
  Serial.print(dht1.readHumidity());
  Serial.print("/n");
}


