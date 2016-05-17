#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
#include "StopWatch.h"

#define pinPortA1 10
#define pinPortB1 13
#define pinPortC1 12
#define pinPortD1 11
#define pinPortE1 9

#define pinPortA2 7
#define pinPortB2 3
#define pinPortC2 5
#define pinPortD2 6
#define pinPortE2 8

const int numPixels = 3;

Adafruit_NeoPixel pixelA1 = Adafruit_NeoPixel(numPixels, pinPortA1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelB1 = Adafruit_NeoPixel(numPixels, pinPortB1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelC1 = Adafruit_NeoPixel(numPixels, pinPortC1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelD1 = Adafruit_NeoPixel(2, pinPortD1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelE1 = Adafruit_NeoPixel(numPixels, pinPortE1, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixelA2 = Adafruit_NeoPixel(numPixels, pinPortA2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelB2 = Adafruit_NeoPixel(numPixels, pinPortB2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelC2 = Adafruit_NeoPixel(numPixels, pinPortC2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelD2 = Adafruit_NeoPixel(numPixels, pinPortD2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelE2 = Adafruit_NeoPixel(numPixels, pinPortE2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels;

CapacitiveSensor   grebA1 = CapacitiveSensor(4,29);
CapacitiveSensor   grebB1 = CapacitiveSensor(4,2);
// CapacitiveSensor   grebC1 = CapacitiveSensor(4,22);
CapacitiveSensor   grebD1 = CapacitiveSensor(4,24);
CapacitiveSensor   grebE1 = CapacitiveSensor(4,32);

CapacitiveSensor   grebA2 = CapacitiveSensor(4,40);
CapacitiveSensor   grebB2 = CapacitiveSensor(4,53);
CapacitiveSensor   grebC2 = CapacitiveSensor(4,48);
CapacitiveSensor   grebD2 = CapacitiveSensor(4,45);
CapacitiveSensor   grebE2 = CapacitiveSensor(4,37);

int light = 255;

// for the method touch
long totalPre1 = 0;
long totalPre2 = 0;
int x = 1;

// sensor value
long Ai; long Bi; long Ci; long Di; long Ei;
long Aii; long Bii; long Cii; long Dii; long Eii;

void setup()                    
{
   Serial.begin(9600);
   pixelA1.begin();
   pixelB1.begin();
   pixelC1.begin();
   pixelD1.begin();
   pixelE1.begin();
   pixelA2.begin();
   pixelB2.begin();
   pixelC2.begin();
   pixelD2.begin();
   pixelE2.begin();

   pixelA1.show();
   pixelB1.show();
   pixelC1.show();
   pixelD1.show();
   pixelE1.show();
   pixelA2.show();
   pixelB2.show();
   pixelC2.show();
   pixelD2.show();
   pixelE2.show();
}


void loop(){
  
    Ai = grebA1.capacitiveSensor(1);
    Bi = grebB1.capacitiveSensor(1);
//    Ci = grebC1.capacitiveSensor(50);
    Di = grebD1.capacitiveSensor(1);
    Ei = grebE1.capacitiveSensor(1);

    Aii = grebA2.capacitiveSensor(1);
    Bii = grebB2.capacitiveSensor(1);
    Cii = grebC2.capacitiveSensor(1);
    Dii = grebD2.capacitiveSensor(1);
    Eii = grebE2.capacitiveSensor(1);

    Serial.print("\n A1: "); Serial.print(Ai); 
    Serial.print("\n B1: "); Serial.print(Bi); 
//    Serial.print("\n C1: "); Serial.print(Ci); 
    Serial.print("\n D1: "); Serial.print(Di); 
    Serial.print("\n E1: "); Serial.print(Ei);

    Serial.print("\n A2: "); Serial.print(Aii); 
    Serial.print("\n B2: "); Serial.print(Bii); 
    Serial.print("\n C2: "); Serial.print(Cii); 
    Serial.print("\n D2: "); Serial.print(Dii); 
    Serial.print("\n E2: "); Serial.print(Eii);

    if(touch(Ai)){
      setLight(pixelA1);
      Serial.print("\n A1 touched"); 
    }

    if(touch(Bi)){
      setLight(pixelB1);
      Serial.print("\n B1 touched"); 
    }

    if(touch(Ci)){
      setLight(pixelC1);
      Serial.print("\n C1 touched"); 
    }
    
    if(touch(Di)){
      setLight(pixelD1);
      Serial.print("\n D1 touched"); 
    }

    if(touch(Ei)){
      setLight(pixelE1);
      Serial.print("\n E1 touched"); 
    }

    
    if(touch(Aii)){
      setLight(pixelA2);
      Serial.print("\n A2 touched"); 
    }

    if(touch(Bii)){
      setLight(pixelB2);
      Serial.print("\n B2 touched"); 
    }

    if(touch(Cii)){
      setLight(pixelC2);
      Serial.print("\n C2 touched"); 
    }
    
    if(touch(Dii)){
      setLight(pixelD2);
      Serial.print("\n D2 touched"); 
    }

    if(touch(Eii)){
      setLight(pixelE2);
      Serial.print("\n E2 touched"); 
    }
}

// ---------------

boolean touch(long total) {
  boolean result = false;
  
  if (total > 250 && (((totalPre2 + totalPre1)/2) * 4) < total ){
    result = true;
  }
  
  if ( x == 1 ) {
    totalPre1 = total;
    x = 2;
  }
  else if ( x == 2  ) {
    totalPre2 = total;
    x = 1;
  }
  return result;
}

// ------ lysstyring
void setLight(Adafruit_NeoPixel pixelNumber){
    pixels = pixelNumber;
    for(int i=0; i<3; i++){
      pixels.setPixelColor(i, pixels.Color(light,0,light));
      pixels.show();
      }
}

void lightsOff(Adafruit_NeoPixel pixelNumber){
    pixels = pixelNumber;
    for(int i=0; i<3; i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      pixels.show();
      }
}

void allLightsOff(){
    lightsOff(pixelA1);
    lightsOff(pixelB1);
    lightsOff(pixelC1);
    lightsOff(pixelD1);
    lightsOff(pixelE1);
    
    lightsOff(pixelA2);
    lightsOff(pixelB2);
    lightsOff(pixelC2);
    lightsOff(pixelD2);
    lightsOff(pixelE2);
}

void allLightsOn(){
    setLight(pixelA1);
    setLight(pixelB1);
    setLight(pixelC1);
    setLight(pixelD1);
    setLight(pixelE1);
    
    setLight(pixelA2);
    setLight(pixelB2);
    setLight(pixelC2);
    setLight(pixelD2);
    setLight(pixelE2);
}
