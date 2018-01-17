/***************************************************
  Adafruit MQTT Library ESP8266 Example

  Must use ESP8266 Arduino from:
    https://github.com/esp8266/Arduino

  Works great with Adafruit's Huzzah ESP board & Feather
  ----> https://www.adafruit.com/product/2471
  ----> https://www.adafruit.com/products/2821

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Tony DiCola for Adafruit Industries.
  MIT license, all text above must be included in any redistribution

  *******************************************************
  *This code is edited by Sachin Soni(techiesms)
  *Search for "techiesms" in YouTube for project tutorial
  *******************************************************
  
 ****************************************************/
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#define S3 D0
#define S2 D1
#define S1 D2
#define S0 D3
#define analogpin A0
/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "SSID_NAME"
#define WLAN_PASS       "PASSWORD"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "USERNAME"
#define AIO_KEY         "AIOKEY"

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'photocell' for publishing.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish sensor_1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sensor-1");
Adafruit_MQTT_Publish sensor_2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sensor-2");
Adafruit_MQTT_Publish sensor_3 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sensor-3");
Adafruit_MQTT_Publish sensor_4 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sensor-4");
// Setup a feed called 'onoff' for subscribing to changes.
//Adafruit_MQTT_Subscribe onoffbutton = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff");

/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(analogpin, INPUT);
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);  

  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff feed.
  //mqtt.subscribe(&onoffbutton);
}

uint32_t x=0;

void loop() {
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
  MQTT_connect();

 

  // Now we can publish stuff!
  Serial.print(F("\nSending Sensor's Value "));
  digitalWrite(S0,LOW);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 1 ");Serial.println(analogRead(analogpin));
  Serial.print("...");
  int Value = analogRead(analogpin);
  if (! sensor_1.publish(Value)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 2 ");Serial.println(analogRead(analogpin));
  Serial.print("...");
  Value = analogRead(analogpin);
  if (! sensor_2.publish(Value)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 3 ");Serial.println(analogRead(analogpin));
  Serial.print("...");
  Value = analogRead(analogpin);
  if (! sensor_3.publish(Value)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 4 ");Serial.println(analogRead(analogpin));
  Serial.print("...");
  Value = analogRead(analogpin);
  if (! sensor_4.publish(Value)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

  delay(2000);
  // ping the server to keep the mqtt connection alive
  // NOT required if you are publishing once every KEEPALIVE seconds
  /*
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }
  */
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
