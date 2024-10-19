#include <WiFi.h>
#include <Firebase_ESP_Client.h>

// Replace with your network credentials and Firebase secret
char* ssid = "";
char* password = "";
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  
}

void loop() {
  // Here's an example of sending the value 100 to a node named "test"
  Firebase.setFloat("test", 100);

  // Check for errors
  if (Firebase.failed()) {
      Serial.print("setting /test failed:");
      Serial.println(Firebase.error());
      return;
  }

  delay(5000);  // Wait for 5 seconds before sending again
}
