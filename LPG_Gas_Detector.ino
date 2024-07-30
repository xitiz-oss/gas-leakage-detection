//Importing the resources required for WIFI connectivity, servo motor control and the Thingspeak platform integration.
//imports
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
//initializing the components required for Wifi connectivity and ThingSpeak integration
const char* ssid = "Islington College";
const char* password = "I$LiNGT0N2024";
const char* server = "api.thingspeak.com";
unsigned long channelNumber = 2373261;
const char* api = "2XHYUKB80NDEPO0Z";
//Specifying the pin connections for Buzzer, Red_light, Exhaust_fan, Servo_pin and
Sensor.
#define BUZZER D0
#define RED_LIGHT D3
#define EXHAUST_FAN 5
#define SERVO_PIN D8
#define SENSOR A0
  //Creating Servo Object
  Servo servo;

//Declaring a boolean variable to monitor if the gas alarm is currently active or not.
//When alarmActive is false, no alert actions are being carried out and the gas level is
within a safe range.bool alarmActive = false;
//Initializing the WifiClient library
WiFiClient client;
void setup() {
  // put your setup code here, to run once:
  //Starting the serial monitor
  Serial.begin(115200);
  //Connecting to the designated WIFI network using initialized ssid and password
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    //delaying for 250 miliseconds
    delay(250);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  //Initialize Thingspeak
  ThingSpeak.begin(client);
  //Specify the the pins mode of operation
  pinMode(SENSOR, INPUT);

  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(EXHAUST_FAN, OUTPUT);
  digitalWrite(EXHAUST_FAN, HIGH);
  servo.attach(SERVO_PIN);
  servo.write(0);
}
void loop() {
  // put your main code here, to run repeatedly:
  //code to read the data from the sensor
  int gasLevel = analogRead(SENSOR);
  ThingSpeak.writeField(channelNumber, 1, gasLevel, api);
  delay(1500);
  if (gasLevel > 500 && !alarmActive) {
    //Call the triggerActions() function
    triggerActions();
    //set the alarmActive to true
    alarmActive = true;
    Serial.println(gasLevel);
  } else if (gasLevel <= 500 && alarmActive) {
    //Call the resetActions() function to reset the alarm
    resetActions();
    //set the alarmActive to false
    alarmActive = false;
  }

  delay(1000);
}
//fucntion to trigger the alarms on gas leakage detection
void triggerActions() {
  digitalWrite(BUZZER, HIGH);
  digitalWrite(RED_LIGHT, HIGH);
  digitalWrite(EXHAUST_FAN, LOW);
  servo.write(180);
  delay(4000);
}
//function to reset the alarms after the alarm
void resetActions() {
  digitalWrite(BUZZER, LOW);
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(EXHAUST_FAN, HIGH);
  servo.write(0);
  delay(1000);
}