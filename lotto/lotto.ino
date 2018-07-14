//Include Libery
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>;

//Data Set
#define ONE_WIRE_BUS 2
#define DHTPIN 3
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht1(DHTPIN, DHTTYPE);


//Setup One Wire
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

//Assign Sensor
DeviceAddress tempHand1 = { 0x28, 0xFF, 0xEE, 0xBA, 0x84, 0x16, 0x05, 0x3F };
DeviceAddress tempHand2 = { 0x28, 0xFF, 0x1A, 0x46, 0x84, 0x16, 0x03, 0x38 };
DeviceAddress tempHand3 = { 0x28, 0xFF, 0xE8, 0x3F, 0x85, 0x16, 0x05, 0x50 };
DeviceAddress tempHand4 = { 0x28, 0xFF, 0xBE, 0x48, 0xB3, 0x16, 0x05, 0x78 };

float Temp1;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);

  //Ready the device
  delay(500);

  Serial.begin(9600); // the bigger number the better


  Serial.println("Device Finish Setup"); //clears up any data left from previous projects


}

void loop() {
  // put your main code here, to run repeatedly:

}
