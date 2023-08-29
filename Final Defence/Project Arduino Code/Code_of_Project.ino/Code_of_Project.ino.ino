#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <NewPing.h>  // Only if using an ultrasonic water level sensor

// Replace with your WiFi credentials
char auth[] = "cmLtwz07mRPazy6h5X2fjBk_XjUeq6Jg";
char ssid[] = "Project Moon";
char pass[] = "18701012";

// Pins
const int waterLevelPin = D1;    // Pin for water level sensor
const int soilMoisturePin = A0;  // Pin for soil moisture sensor
const int rainSensorPin = D2;    // Pin for rain sensor
const int waterPump = D3;        // pin for Motor


// Blynk virtual pins
#define SOIL_MOISTURE_VIRTUAL V0
#define WEATHER_STATUS_VIRTUAL V1
#define SOIL_MOISTURE_STATUS_VIRTUAL V2
#define WATER_PUMP_VIRTUAL V3

#define BLYNK_TEMPLATE_ID "TMPL65ba0tg7O"
#define BLYNK_TEMPLATE_NAME "Tea Garden Sprinkler System"

// Variables
int waterLevel;
int soilMoisture;
int rainSensorState;
bool blynkServerConnected = false;
int motorState;
// (Optional) Initialize NewPing library for ultrasonic sensor
// #define MAX_DISTANCE 200  // Change this value based on your sensor's capabilities
// NewPing sonar(waterLevelPin, waterLevelPin, MAX_DISTANCE);



// Function to read rain sensor state (1 if wet, 0 if dry)
int getRainSensorState() {
  return digitalRead(rainSensorPin);
}

// Function to read soil moisture sensor value (0 to 1023)
int getSoilMoisture() {
  return analogRead(soilMoisturePin);
}

void setup() {
  Serial.begin(9600);

  pinMode(waterPump, OUTPUT);
  pinMode(rainSensorPin, INPUT);
  pinMode(soilMoisturePin, INPUT);
  pinMode(waterLevelPin, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  Blynk.begin(auth, ssid, pass);

  // (Optional) Set the frequency for reading sensors
  Blynk.virtualWrite(SOIL_MOISTURE_VIRTUAL, 100);   // 5 seconds
  Blynk.virtualWrite(WEATHER_STATUS_VIRTUAL, 100);  // 5 seconds
  Blynk.virtualWrite(WATER_PUMP_VIRTUAL, 100);      // 5 seconds
}

void loop() {
  // connecting to blynk server
  if (!blynkServerConnected) {
    Serial.print("\n\n\nConnecting to Blynk Server");
    while (!Blynk.connected()) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nConnected to Blynk Server");
    blynkServerConnected = true;
  }







  //soil moisture display section
  soilMoisture = getSoilMoisture();
  soilMoisture = (map(soilMoisture, 0, 1024, 0, 100) - 100) * -1;
  Blynk.virtualWrite(SOIL_MOISTURE_VIRTUAL, soilMoisture);
  Serial.print("Soil Moisture Data is = ");
  Serial.println(soilMoisture);
  if (soilMoisture < 20) {
    Blynk.virtualWrite(SOIL_MOISTURE_STATUS_VIRTUAL, "Soil is too DRY - Need Water");
  } else if (soilMoisture < 50 && soilMoisture >= 20) {
    Blynk.virtualWrite(SOIL_MOISTURE_STATUS_VIRTUAL, "Soil is PERFECT");
  } else {
    Blynk.virtualWrite(SOIL_MOISTURE_STATUS_VIRTUAL, "Soil is too WET");
  }






  //Weather Status display section
  rainSensorState = getRainSensorState();
  Serial.print("Wether Status is = ");
  if (rainSensorState == 0) {
    Serial.println("Raining");
    Blynk.virtualWrite(WEATHER_STATUS_VIRTUAL, "Raining");
  } else {
    Serial.println("Sunny");
    Blynk.virtualWrite(WEATHER_STATUS_VIRTUAL, "Not Raining");
  }





  // logic Section of Motor ON or OFF

  Serial.print("Motor state ");
  Serial.println(motorState);
  if (rainSensorState != 0 && soilMoisture <= 20 && motorState == 1) {
    Blynk.virtualWrite(WATER_PUMP_VIRTUAL, 1);
    digitalWrite(waterPump, LOW);
    Serial.println("Motor is ON\n\n");
  } else {
    Blynk.virtualWrite(WATER_PUMP_VIRTUAL, 0);
    digitalWrite(waterPump, HIGH);
    Serial.println("Motor is OFF\n\n");
  }



  Blynk.run();
  delay(1000);
}

BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(WATER_PUMP_VIRTUAL);
}
BLYNK_WRITE(V3) {
  motorState = param.asInt();  // Get the state of the button (0 or 1)
}
