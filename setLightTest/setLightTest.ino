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
#define pinPortC2 32
#define pinPortD2 6
#define pinPortE2 8

const int numPixels = 3;

Adafruit_NeoPixel pixelA1 = Adafruit_NeoPixel(numPixels, pinPortA1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelB1 = Adafruit_NeoPixel(numPixels, pinPortB1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelC1 = Adafruit_NeoPixel(numPixels, pinPortC1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelD1 = Adafruit_NeoPixel(2, pinPortD1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelE1 = Adafruit_NeoPixel(numPixels, pinPortE1, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixelA2 = Adafruit_NeoPixel(numPixels, pinPortA2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelB2 = Adafruit_NeoPixel(numPixels, pinPortB2, NEO_GRB + NEO_KHZ800); Adafruit_NeoPixel pixelC2 = Adafruit_NeoPixel(numPixels, pinPortC2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelD2 = Adafruit_NeoPixel(numPixels, pinPortD2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelE2 = Adafruit_NeoPixel(numPixels, pinPortE2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels;

CapacitiveSensor   grebA1 = CapacitiveSensor(4,29);
CapacitiveSensor   grebB1 = CapacitiveSensor(4,2);
// CapacitiveSensor   grebC1 = CapacitiveSensor(4,22);
CapacitiveSensor   grebD1 = CapacitiveSensor(4,24);
CapacitiveSensor   grebE1 = CapacitiveSensor(4,5); // 32

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

// algoritme, tre globale variable for hvert greb
long preE1;
long prepreE1;
long avrE1;
boolean resultE1 = false;
long touchedValueE1;

int count=0;

// sensor value
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

//    Ai = grebA1.capacitiveSensor(1);
//    Bi = grebB1.capacitiveSensor(1);
//    Ci = grebC1.capacitiveSensor(1);
//    Di = grebD1.capacitiveSensor(1);
    Ei = grebE1.capacitiveSensor(1);

//    Aii = grebA2.capacitiveSensor(1);
//    Bii = grebB2.capacitiveSensor(1);
//    Cii = grebC2.capacitiveSensor(1);
//    Dii = grebD2.capacitiveSensor(1);
//    Eii = grebE2.capacitiveSensor(1);
  
//  Serial.print("\n E1: "); Serial.print(Ei);



  if(E1touch()==true){
    // setLight(pixelE1);
    Serial.print("\n E1 touched: ");
    count++;
   // Serial.print(count);
  }
  
}

 
// --- algoritme til gennemsnit

boolean E1touch(){
  boolean capFlag = false; 

  if(Ei > 250 && Ei > avrE1*3){
    resultE1 = true;
    touchedValueE1 = Ei;

      if(Ei > touchedValueE1/2){
        resultE1 = true;
       }
  }
  
  if(Ei < touchedValueE1){
    resultE1 = false;
  }

  if(capFlag==false){
    preE1 = Ei;
    capFlag=true;
  }
  if(capFlag==true){
    prepreE1=Ei;
    capFlag=false;
  }
  
  avrE1 = (preE1+prepreE1)/2;

  return resultE1;
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
//    setLight(pixelC2);
    setLight(pixelD2);
    setLight(pixelE2);
}
