#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
#include "StopWatch.h"

#define pinPortA1 10
#define pinPortB1 13
#define pinPortC1 12
#define pinPortD1 11
#define pinPortE1 9

#define pinPortA2 7
#define pinPortB2 4
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
Adafruit_NeoPixel pixelB2 = Adafruit_NeoPixel(numPixels, pinPortB2, NEO_GRB + NEO_KHZ800); Adafruit_NeoPixel pixelC2 = Adafruit_NeoPixel(numPixels, pinPortC2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelD2 = Adafruit_NeoPixel(numPixels, pinPortD2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelE2 = Adafruit_NeoPixel(numPixels, pinPortE2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels;

CapacitiveSensor   grebA1 = CapacitiveSensor(39,33);
CapacitiveSensor   grebB1 = CapacitiveSensor(39,22);
CapacitiveSensor   grebC1 = CapacitiveSensor(39,27);
CapacitiveSensor   grebD1 = CapacitiveSensor(39,28);
CapacitiveSensor   grebE1 = CapacitiveSensor(39,34);

CapacitiveSensor   grebA2 = CapacitiveSensor(39,51);
CapacitiveSensor   grebB2 = CapacitiveSensor(39,46);
CapacitiveSensor   grebC2 = CapacitiveSensor(39,45);
CapacitiveSensor   grebD2 = CapacitiveSensor(39,40);
CapacitiveSensor   grebE2 = CapacitiveSensor(39,52);

int light = 255;

// algoritme, tre globale variable for hvert greb

long preA1;
long prepreA1;
long avrA1;
boolean resultA1 = false;
boolean flagA1 = true;

long preB1;
long prepreB1;
long avrB1;
boolean resultB1 = false;
boolean flagB1 = true;

long preC1;
long prepreC1;
long avrC1;
boolean resultC1 = false;
boolean flagC1 = true;

long preD1;
long prepreD1;
long avrD1;
boolean resultD1 = false;
boolean flagD1 = true;

long preE1;
long prepreE1;
long avrE1;
boolean resultE1 = false;
boolean flagE1 = true;

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

      Ai = grebA1.capacitiveSensor(50);
      Bi = grebB1.capacitiveSensor(50);
      Ci = grebC1.capacitiveSensor(50);
      Di = grebD1.capacitiveSensor(50);
      Ei = grebE1.capacitiveSensor(50);

    Aii = grebA2.capacitiveSensor(50);
    Bii = grebB2.capacitiveSensor(50);
    Cii = grebC2.capacitiveSensor(50);
    Dii = grebD2.capacitiveSensor(50);
    Eii = grebE2.capacitiveSensor(50);
  
//    Serial.print("\n A1: "); Serial.print(Ai); 
//    Serial.print("\n B1: "); Serial.print(Bi); 
//    Serial.print("\n C1: "); Serial.print(Ci); 
//    Serial.print("\n D1: "); Serial.print(Di); 
//    Serial.print("\n E1: "); Serial.print(Ei);

//    Serial.print("\n A2: "); Serial.print(Aii); 
//    Serial.print("\n B2: "); Serial.print(Bii); 
//    Serial.print("\n C2: "); Serial.print(Cii); 
//    Serial.print("\n D2: "); Serial.print(Dii); 
    Serial.print("\n E2: "); Serial.print(Eii);

  if(A1touch()){
    if(flagA1){
    setLight(pixelA1);
    Serial.print("\n A1 touched");
    flagA1=false;
    }
  }

  if(B1touch()){
    if(flagB1){
    setLight(pixelB1);
    Serial.print("\n B1 touched");
    flagB1=false;
    }
  }

 if(C1touch()){
    if(flagC1){
    setLight(pixelC1);
    Serial.print("\n C1 touched");
    flagC1=false;
    }
  }

 if(D1touch()){
    if(flagD1){
    setLight(pixelD1);
    Serial.print("\n D1 touched");
    flagD1=false;
    }
  }

  if(E1touch()){
    if(flagE1){
      setLight(pixelE1);
      Serial.print("\n E1 touched");
      flagE1=false;
    }
  }


delay(100);

}
 
// --- algoritme til gennemsnit

boolean A1touch(){
  boolean capFlag = false; 

  if(Ai > 250 && Ai > avrA1*6){
    resultA1 = true;
  }

  if(capFlag==false){
    preA1 = Ai;
    capFlag=true;
  }
  if(capFlag==true){
    prepreA1=Ai;
    capFlag=false;
  }
  
  avrA1 = (preA1+prepreA1)/2;

  return resultA1;
}

boolean B1touch(){
  boolean capFlag = false; 

  if(Bi > 250 && Bi > avrB1*3){
    resultB1 = true;
  }

  if(capFlag==false){
    preB1 = Bi;
    capFlag=true;
  }
  if(capFlag==true){
    prepreB1=Bi;
    capFlag=false;
  }
  
  avrB1 = (preB1+prepreB1)/2;

  return resultB1;
}

boolean C1touch(){
  boolean capFlag = false; 

  if(Ci > 250 && Ci > avrC1*6){
    resultC1 = true;
  }

  if(capFlag==false){
    preC1 = Ci;
    capFlag=true;
  }
  if(capFlag==true){
    prepreC1=Ci;
    capFlag=false;
  }
  
  avrC1 = (preC1+prepreC1)/2;

  return resultC1;
}

boolean D1touch(){
  boolean capFlag = false; 

  if(Di > 250 && Di > avrD1*3){
    resultD1 = true;
  }

  if(capFlag==false){
    preD1 = Di;
    capFlag=true;
  }
  if(capFlag==true){
    prepreD1=Di;
    capFlag=false;
  }
  
  avrD1 = (preD1+prepreD1)/2;

  return resultD1;
}

boolean E1touch(){
  boolean capFlag = false; 

  if(Ei > 250 && Ei > avrE1*3){
    resultE1 = true;
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
