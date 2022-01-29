// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
// - LiquidCrystal Library: https://github.com/arduino-libraries/LiquidCrystal

int SENSE = 2; // Soil Sensor input at Analog PIN A2
int val = 0;   // stores the value received from Soil Moisture Sensor

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN A0     // Digital pin connected to the DHT sensor
//#define SOILPIN A2    // Digital pin connected to the Soil Moisture Sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {
  val = analogRead(SENSE);
 // val = val / 10;
  Serial.print("Soil Moisture: ");
  Serial.print(val);
  if (val < 80 && val > 50){
	Serial.println("Soil is getting dry.");
  }
  else if (val < 50)
  {
	Serial.println(" Doing fine");
  }
  else
  {
	if (val > 100){
		Serial.println(" Soil is dry");
	}
  }
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }

  delay(2000);
}
