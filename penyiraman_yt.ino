#define BLYNK_TEMPLATE_ID "TMPL6L6uh-GQO"
#define BLYNK_TEMPLATE_NAME "Penyiraman Otomatis"

#include <Wire.h>
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

#define BLYNK_AUTH_TOKEN "H19fNDd9iGE4i7jktXI7X8vHqOwn-AdZ"

int pump = 4; // Pin 2 pada NodeMCU, pin pompa
char auth[] = "H19fNDd9iGE4i7jktXI7X8vHqOwn-AdZ"; // TOKEN PADA APLIKASI BLYNX
char ssid[] = "Warkop"; // NAMA HOTSPOT
char pass[] = "kopisatu"; // PASSWORD HOTSPOT
int servoPin = 5;

Servo myservo;

BlynkTimer timer;


void sendSensor() {
  int POT = analogRead(A0);
  Blynk.virtualWrite(V1, POT);

  if (POT > 1000) {
    Serial.println("KERING");
    digitalWrite(pump, HIGH);
  } else if (POT < 600) {
    Serial.println("BASAH");
    digitalWrite(pump, LOW);
  }

  Serial.flush();  // Pastikan data terkirim ke Serial Monitor secara real-time
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendSensor);

  pinMode(pump, OUTPUT);
  digitalWrite(pump, HIGH);

  //myservo.attach(servoPin);
}

void loop() {
  Blynk.run();
  timer.run();
  // Menampilkan jam di Serial Monitor dengan waktu Jakarta

delay(100);
}