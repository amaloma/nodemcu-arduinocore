#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "********";
const char* password = "********";

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  // configure traged server and url
  // https not work!
  http.begin("https://jsonplaceholder.typicode.com/posts/1", "‎‎fe 7b b2 86 c7 60 ca ed 74 3b 9d 1d 22 e9 3e a8 d3 6c 10 bd"); //HTTPS
  //http.begin("http://jsonplaceholder.typicode.com/posts/1"); //HTTP

  Serial.print("[HTTP] GET...\n");
  // start connection and send HTTP header
  int httpCode = http.GET();

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();

  delay(30000);
  
}
