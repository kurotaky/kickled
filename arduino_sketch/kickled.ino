#include <M5Stack.h>
#include <Adafruit_NeoPixel.h>
#include <Ticker.h>

#define PIN            G2 // GPIO
#define NUMPIXELS      59

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Ticker ticker;

int delayval = 50;
int val = 0;
int counter = 1;
int punchCounter = 0;

// M5Stack起動時に、setup内の処理を一度だけ実行します。
void setup() {
  Serial.begin(115200);

  // initialize the M5Stack object
  M5.begin();

  // This initializes the NeoPixel library.
  pixels.begin();
  pixels.setBrightness(100);  // MAX: 255
  // pixels.show();
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 177));
    pixels.show();
  }
  // ticker.attach_ms(200, blink);   // 0.2秒間隔で割り込み
}

void blink() {
  counter = counter + 1;
  Serial.println(counter);
  int r = (counter * 255) % 255;
  int g = (counter * 100) % 255;
  int b = (counter * 150) % 255;
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();
  }
}

void finish() {
  // ticker.detach();
  delay(1000);
  pixels.clear();
  pixels.show();
  delay(1000);
  ticker.attach_ms(200, blink);
}

// loop内の処理を繰り返します
void loop(){
  M5.update();
  // ADCって書いてある番号だけanalogReadできるらしい
  val = analogRead(G35); // read the input pin
  // Serial.println(val);
  if (val > 50) {
    delay(500);
    Serial.println("count!!!");
    punchCounter = punchCounter + 1;
    Serial.println(punchCounter);
  }

  if (punchCounter > 20) {
    finish();
  }
}
