#include "Arduino.h"
#include "Audio.h"
#include "SD.h"
#include "FS.h"
 
//neopixels
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN 35
#define NUMPIXELS 20
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 250 // Time (in milliseconds) to pause between pixels

// adafruit sd card pinout thing
#define SD_CS          5
#define SPI_MOSI      23 
#define SPI_MISO      19
#define SPI_SCK       18
 
// amp pinouts
#define I2S_DOUT      22
#define I2S_BCLK      26
#define I2S_LRC       25
 
// set up sound sensor pinout things
int digitalPin = 34;
int analogPin = 32;

int duration = getAudioFileDuration();

 // create audio object (i have no idea what this does imma be fr)
Audio audio;
 
void setup() {
  
  // initialize pins for sound sensor
  pinMode(digitalPin, INPUT);
  pinMode(analogPin, INPUT);
  //probably not gonna use the analog pin, but have it anyways for fun and additional tweaking :3

  // microsd card setup, set cs as output
  pinMode(SD_CS, OUTPUT);      
  digitalWrite(SD_CS, HIGH); 
  
  // spi stuff ans setup
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);

  // cereal port yum yum
  Serial.begin(9600);
  // start sd card
  if(!SD.begin(SD_CS))
  {
    Serial.println("uh oh you did a fucky wucky, your sd card isnt working");
    while(true); 
  }
  //set up i2s
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  // set volume
  audio.setVolume(10);
  // find audio file
  audio.connecttoFS(SD,"/sculkshriek.mp3");
  //neopixel setup
  pixels.begin(); 
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop()
{
  // sound detection/playing
  soundDetect = digitalRead(digitalPin);
  if (soundDetect == HIGH) { //if sound is detected by the sensor SCREAM AHHHHHHH
    audio.connecttoFS(SD, "/sculkshriek.mp3");
    delay(duration);
  }

  //neopixel animation
  for(int b=0; b<10; b++) { // loop to move the pixels around the ring via the b variable; set b to less than 10, makes pixels loop around
    strip.clear(); // set all pixels to off
    // for loop to select the two pixels on opposite sides of the ring
    for(int c=b; c<strip.numPixels(); c += 10) { // make spacing between glowing pixels; 20 pixels in PCB, so space them by 9 pixels (10 in code)
      strip.setPixelColor(c, strip.Color(0,146,149)); // set the selected pixels to the sculk color
    }
    strip.show(); // make neopixels actually show colors now
    delay(250);  // briefly pause between pixel so my eyes dont hurt
  }
}
