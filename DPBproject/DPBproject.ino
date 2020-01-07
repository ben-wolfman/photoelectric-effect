#include <Adafruit_NeoPixel.h>

#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6

#define NUMPIXELS 30 //number of neopixels

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS, PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(NUMPIXELS, PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel photon = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

int delayspeed = 0;
int delayint = 0;

int volt = 0;
int wave = 0;
int intensity = 0;

int sodium = 0;
int zinc = 0;
int copper = 0;
int platinum = 0;
int calcium = 0;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  pixels1.begin();
  pixels2.begin();
  pixels3.begin();
  pixels4.begin();
  photon.begin();
  Serial.begin(9600);
}

void loop() {
  
  setColorWave();
  setSpeeds();
  setPhoton();
  setDelayInt();
  serialPrint();
  delay(delayint); //Based on intensity

  for(int i=0;i<NUMPIXELS;i++){
    setColorWave();
    setSpeeds();
    pixels1.setPixelColor(i, pixels1.Color(redColor, greenColor, blueColor)); // Moderately bright green color.
  if ((i >= 2)) {
      pixels1.setPixelColor(i-2, pixels1.Color(0, 0, 0));
    }
    if (i >= 29) {
        pixels1.setPixelColor(i-1, pixels1.Color(0, 0, 0));
    pixels1.setPixelColor(i, pixels1.Color(0, 0, 0));
    }

    pixels1.show(); // This sends the updated pixel color to the hardware.
    tone(8, 1250 - analogRead(A0), 50);

    setSpeeds();
    delay(delayspeed); // Delay for a period of time (in milliseconds).
 
    if ((i == NUMPIXELS)){
      i = 0; //Start again
        
    }
  }

  setPhoton();
  setDelayInt();
  serialPrint();
  delay(delayint); //Based on intensity
  
  for(int i=0;i<NUMPIXELS;i++){
    setColorWave();
    setSpeeds();
    pixels2.setPixelColor(i, pixels2.Color(redColor, greenColor, blueColor));
  if ((i >= 2)) {
      pixels2.setPixelColor(i-2, pixels2.Color(0, 0, 0));
    }
    if (i >= 29) {
        pixels2.setPixelColor(i-1, pixels2.Color(0, 0, 0));
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
    }

    pixels2.show();
    tone(8, 1250 - analogRead(A0), 50);

    setSpeeds();
    delay(delayspeed);

    if ((i == NUMPIXELS)){
      i = 0;
        
    }
  }

  setPhoton();
  setDelayInt();
  serialPrint();
  delay(delayint); //Based on intensity
  
  for(int i=0;i<NUMPIXELS;i++){
    setColorWave();
    setSpeeds();
    pixels3.setPixelColor(i, pixels3.Color(redColor, greenColor, blueColor));
  if ((i >= 2)) {
      pixels3.setPixelColor(i-2, pixels3.Color(0, 0, 0));
    }
    if (i >= 29) {
        pixels3.setPixelColor(i-1, pixels3.Color(0, 0, 0));
    pixels3.setPixelColor(i, pixels3.Color(0, 0, 0));
    }

    pixels3.show();
    tone(8, 1250 - analogRead(A0), 50);

    setSpeeds();
    delay(delayspeed);
  
    if ((i == NUMPIXELS)){
      i = 0;
        
    }
  }

  setPhoton();
  setDelayInt();
  serialPrint();
  delay(delayint); //Based on intensity
   
  for(int i=0;i<NUMPIXELS;i++){
    setColorWave();
    setSpeeds();
    pixels4.setPixelColor(i, pixels4.Color(redColor, greenColor, blueColor));
  if ((i >= 2)) {
      pixels4.setPixelColor(i-2, pixels4.Color(0, 0, 0));
    }
    if (i >= 29) {
        pixels4.setPixelColor(i-1, pixels4.Color(0, 0, 0));
    pixels4.setPixelColor(i, pixels4.Color(0, 0, 0));
    }

    pixels4.show();
    tone(8, 1250 - analogRead(A0), 50);

    setSpeeds();
    delay(delayspeed);
    
    if ((i == NUMPIXELS)){
      i = 0;
        
    }
  }

}

//sets the LED color based on the wavelength
void setColorWave() {
  //wave = (((analogRead(A0))/1.705));
  wave = (((analogRead(A0))/1.705)+130);
  if ((wave <= 700) && (wave > 560)) {
    redColor = 255;
    greenColor = (255 - ((wave-560)*(1.821428571)));
    blueColor = 0;
  }
  if ((wave <= 560) && (wave > 520)) {
    redColor = ((wave-520)*0.1568627451);
    greenColor = 255;
    blueColor = 0;
  }
  if ((wave <= 520) && (wave > 490)) {
    redColor = 0;
    greenColor = 255;
    blueColor = (255 - ((wave-490)*0.1176470588));
  }
  if ((wave <= 490) && (wave > 450)) {
    redColor = 0;
    greenColor = ((wave-450)*0.1568627451);
    blueColor = 255;
  }
  if ((wave <= 450) && (wave > 400)) {
    redColor = (180 - ((wave-400)*0.2777777778));
    greenColor = 0;
    blueColor = 255;
  }
  if (wave <= 400) {
    redColor = 150;
    greenColor = 150;
    blueColor = 150;
  }
}

void setDelayInt() {
  intensity = (100 - (analogRead(A2)/10.23)); //Should not change speed
  delayint = (3000 - (intensity*30));
}

void setSpeeds() {
  volt = ((analogRead(A1)/102.3));
  delayspeed = ((wave/10) - ((volt/10)*10));
}

void serialPrint() {
  Serial.print("wavelength: ");
  Serial.print(wave);
  Serial.println("nm");
  Serial.print("intensity: ");
  Serial.print(100 - intensity);
  Serial.println("Hz");
  Serial.print("voltage: ");
  Serial.print(volt);
  Serial.println("V");
}

void setPhoton() {
  for(int i=0;i<NUMPIXELS;i++){
  
    photon.setPixelColor(i, photon.Color(redColor, greenColor, blueColor));
    photon.show();
    delay(0); //Doesn't change
 
    if ((i == NUMPIXELS)){
      i = 0;
    }
  }
}
