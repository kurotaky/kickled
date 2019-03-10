#include <M5Stack.h>
#include <Adafruit_NeoPixel.h>
#include <Ticker.h>
#include <WiFi.h>
#include "Ambient.h"

#define PIN            G2 // GPIO
#define NUMPIXELS      59

#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "pasword********"

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Ticker ticker;
Ambient ambient;
WiFiClient client;

unsigned int channelId = ****; // AmbientのチャネルID
const char* writeKey = "**********"; // Ambientライトキー

int delayval = 50;
int val = 0;
int counter = 1;
int punchCounter = 0;

// M5Stack起動時に、setup内の処理を一度だけ実行します。
void setup() {
  Serial.begin(115200);

  // WiFi接続
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // initialize the M5Stack object
  M5.begin();

  ambient.begin(channelId, writeKey, &client);

  // This initializes the NeoPixel library.
  pixels.begin();
  pixels.setBrightness(255);  // MAX: 255
  // pixels.show();
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 200));
    pixels.show();
  }
}


// めでたいモード
void blink() {
  counter = counter + 1;
  Serial.println(counter);
  int r = (counter * 255) % 255;
  int g = (counter * 100) % 255;
  int b = (counter * 150) % 255;
  for(int i = 0; i < NUMPIXELS; i++) {
    if (i % 2 == 0) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    } else {
      pixels.setPixelColor(i, pixels.Color(188, 100, 100));
      pixels.show();
    }
  }
}

void finish() {
  // ticker.detach();
  delay(500);
  pixels.clear();
  pixels.show();
  ticker.attach_ms(200, blink);
}

// loop内の処理を繰り返します
void loop(){
  M5.update();
  // ADCって書いてある番号だけanalogReadできるらしい
  val = analogRead(G35); // read the input pin
  Serial.println(val);
  if (val > 50) {
    delay(100);
    Serial.println("count!!!");
    punchCounter = punchCounter + 1;
    Serial.println(punchCounter);
    ambient.set(1, String(val).c_str());
    ambient.send();
  }

  // loopBLE();

  if (punchCounter >= 10 && punchCounter < 20) {
    pixels.setPixelColor(1, pixels.Color(255, 1, 1));
    pixels.setPixelColor(2, pixels.Color(255, 1, 1));
    pixels.setPixelColor(3, pixels.Color(255, 1, 1));
    pixels.setPixelColor(4, pixels.Color(255, 1, 1));
    pixels.setPixelColor(5, pixels.Color(255, 1, 1));
    pixels.setPixelColor(6, pixels.Color(255, 1, 1));
    pixels.setPixelColor(7, pixels.Color(255, 1, 1));
    pixels.setPixelColor(8, pixels.Color(255, 1, 1));
    pixels.setPixelColor(9, pixels.Color(255, 1, 1));
    pixels.setPixelColor(10, pixels.Color(255, 1, 1));
    pixels.show();
  }

  if (punchCounter >= 20 & punchCounter < 30) {
    pixels.setPixelColor(11, pixels.Color(255, 1, 1));
    pixels.setPixelColor(12, pixels.Color(255, 1, 1));
    pixels.setPixelColor(13, pixels.Color(255, 1, 1));
    pixels.setPixelColor(14, pixels.Color(255, 1, 1));
    pixels.setPixelColor(15, pixels.Color(255, 1, 1));
    pixels.setPixelColor(16, pixels.Color(255, 1, 1));
    pixels.setPixelColor(17, pixels.Color(255, 1, 1));
    pixels.setPixelColor(18, pixels.Color(255, 1, 1));
    pixels.setPixelColor(19, pixels.Color(255, 1, 1));
    pixels.setPixelColor(20, pixels.Color(255, 1, 1));
    pixels.show();
  }

  if (punchCounter >= 30 & punchCounter < 40) {
    pixels.setPixelColor(21, pixels.Color(255, 1, 1));
    pixels.setPixelColor(22, pixels.Color(255, 1, 1));
    pixels.setPixelColor(23, pixels.Color(255, 1, 1));
    pixels.setPixelColor(24, pixels.Color(255, 1, 1));
    pixels.setPixelColor(25, pixels.Color(255, 1, 1));
    pixels.setPixelColor(26, pixels.Color(255, 1, 1));
    pixels.setPixelColor(27, pixels.Color(255, 1, 1));
    pixels.setPixelColor(28, pixels.Color(255, 1, 1));
    pixels.setPixelColor(29, pixels.Color(255, 1, 1));
    pixels.setPixelColor(30, pixels.Color(255, 1, 1));
    pixels.show();
  }

  if (punchCounter >= 40 & punchCounter < 50) {
    pixels.setPixelColor(31, pixels.Color(255, 1, 1));
    pixels.setPixelColor(32, pixels.Color(255, 1, 1));
    pixels.setPixelColor(33, pixels.Color(255, 1, 1));
    pixels.setPixelColor(34, pixels.Color(255, 1, 1));
    pixels.setPixelColor(35, pixels.Color(255, 1, 1));
    pixels.setPixelColor(36, pixels.Color(255, 1, 1));
    pixels.setPixelColor(37, pixels.Color(255, 1, 1));
    pixels.setPixelColor(38, pixels.Color(255, 1, 1));
    pixels.setPixelColor(39, pixels.Color(255, 1, 1));
    pixels.setPixelColor(40, pixels.Color(255, 1, 1));
    pixels.show();
  }


  if (punchCounter >= 50 & punchCounter <= 60) {
    pixels.setPixelColor(41, pixels.Color(255, 1, 1));
    pixels.setPixelColor(42, pixels.Color(255, 1, 1));
    pixels.setPixelColor(43, pixels.Color(255, 1, 1));
    pixels.setPixelColor(44, pixels.Color(255, 1, 1));
    pixels.setPixelColor(45, pixels.Color(255, 1, 1));
    pixels.setPixelColor(46, pixels.Color(255, 1, 1));
    pixels.setPixelColor(47, pixels.Color(255, 1, 1));
    pixels.setPixelColor(48, pixels.Color(255, 1, 1));
    pixels.setPixelColor(49, pixels.Color(255, 1, 1));
    pixels.setPixelColor(50, pixels.Color(255, 1, 1));
    pixels.show();
  }

  if (punchCounter > 60) {
    finish();
  }
}
