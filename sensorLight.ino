#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
#include "StopWatch.h"

#define pinPortA1 2
#define pinPortB1 11
#define pinPortC1 12
#define pinPortD1 13
#define pinPortE1 6

#define pinPortA2 7
#define pinPortB2 8
#define pinPortC2 9
#define pinPortD2 10
#define pinPortE2 11

CapacitiveSensor   grebA1 = CapacitiveSensor(4,29);
CapacitiveSensor   grebB1 = CapacitiveSensor(4,5);
CapacitiveSensor   grebC1 = CapacitiveSensor(4,3);
CapacitiveSensor   grebD1 = CapacitiveSensor(4,24);
CapacitiveSensor   grebE1 = CapacitiveSensor(4,32);

CapacitiveSensor   grebA2 = CapacitiveSensor(4,40);
CapacitiveSensor   grebB2 = CapacitiveSensor(4,53);
CapacitiveSensor   grebC2 = CapacitiveSensor(4,48);
CapacitiveSensor   grebD2 = CapacitiveSensor(4,45);
CapacitiveSensor   grebE2 = CapacitiveSensor(4,37);

const int numPixels = 3;

Adafruit_NeoPixel pixelA1 = Adafruit_NeoPixel(numPixels, pinPortA1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelB1 = Adafruit_NeoPixel(numPixels, pinPortB1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelC1 = Adafruit_NeoPixel(numPixels, pinPortC1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelD1 = Adafruit_NeoPixel(2, pinPortD1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelE1 = Adafruit_NeoPixel(numPixels, pinPortE1, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixelA2 = Adafruit_NeoPixel(numPixels, pinPortA1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelB2 = Adafruit_NeoPixel(numPixels, pinPortB1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelC2 = Adafruit_NeoPixel(numPixels, pinPortC1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelD2 = Adafruit_NeoPixel(numPixels, pinPortD1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelE2 = Adafruit_NeoPixel(numPixels, pinPortE1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels;

int light = 255;

// for the method touch
long totalPre1 = 0;
long totalPre2 = 0;
int x = 1;

// sensor value
long Ai; long Bi; long Ci; long Di; long Ei;
long Aii; long Bii; long Cii; long Dii; long Eii;

// ----- from photon

StopWatch MySW;
StopWatch OffWall;

int count = 0;
int jumpDist = 3000;
int reading, lastReading;

boolean flagA1 = false;
boolean flagB1 = false;
boolean flagC1 = false;
boolean flagD1 = false;
boolean flagE1 = false;

boolean flagA2 = false;
boolean flagB2 = false;
boolean flagC2 = false;
boolean flagD2 = false;
boolean flagE2 = false;
boolean flag;

int timeOnWall = 0;
int finalCount = 0;
long inAir;
boolean turn = true;

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
}


void loop()                    
{
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

    inAir = OffWall.elapsed();

// ------------ player 1 ----------------------

if(turn==true){
  
    if(touch(Ai)){
      setLight(pixelA1);
      switchToPlayer2(flagA1);
      Serial.print("\n A1 touched"); 
    }

    if(touch(Bi)){
      setLight(pixelB1);
      switchToPlayer2(flagB1);
      Serial.print("\n B1 touched"); 
    }

    if(touch(Ci)){
      setLight(pixelC1);
      switchToPlayer2(flagC1);
      Serial.print("\n C1 touched"); 
    }

    if(touch(Di)){
      setLight(pixelD1);
      switchToPlayer2(flagD1);
      Serial.print("\n D1 touched"); 
    }

    if(touch(Ei)){
      setLight(pixelE1);
      switchToPlayer2(flagE1);
      Serial.print("\n E1 touched"); 
    }
}

// ---------- player 2 ---------------------

if(turn==false){
    if(touch(Aii)){
      setLight(pixelA2);
      switchToPlayer1(flagA2);
      Serial.print("\n A2 touched"); 
    }

    if(touch(Bii)){
      setLight(pixelB2);
      switchToPlayer1(flagB2);
      Serial.print("\n B2 touched"); 
    }

    if(touch(Cii)){
      setLight(pixelC2);
      switchToPlayer1(flagC2);
      Serial.print("\n C2 touched"); 
    }

    if(touch(Dii)){
      setLight(pixelD2);
      switchToPlayer1(flagD2);
      Serial.print("\n D2 touched"); 
    }

    if(touch(Eii)){
      setLight(pixelE2);
      switchToPlayer1(flagD2);
      Serial.print("\n E2 touched"); 
    }
}
// ---------- makes the path ---------------

    if(flagA1==true){
      setLight(pixelA1);
    }
    if(flagB1==true){
      setLight(pixelB1);
    }
    if(flagC1==true){
      setLight(pixelC1);
    }
    if(flagD1==true){
      setLight(pixelD1);
    }
    if(flagE1==true){
     setLight(pixelE1);
    }
    
   if(flagA2==true){
      setLight(pixelA2);
    }
    if(flagB2==true){
      setLight(pixelB2);
    }
    if(flagC2==true){
      setLight(pixelC2);
    }
    if(flagD2==true){
      setLight(pixelD2);
    }
    if(flagE2==true){
     setLight(pixelE2);
    }

// ------------faldet af væggen ---------------

if( ((touch(Ai)==false) && (touch(Bi)==false) && (touch(Ci)==false) && (touch(Di)==false) && (touch(Ei)==false) ||
    (touch(Aii)==false) && (touch(Bii)==false) && (touch(Cii)==false) && (touch(Dii)==false) && (touch(Eii)==false))
    && (count>=2) ){
      
      OffWall.start();

      if(inAir > jumpDist){
        displayResult();
        allLightsOff();
        count=0;
      }
    }
    
    delay(10);
}

void displayResult(){
  Serial.println();
  Serial.print("Tid på væggen: ");
  timeOnWall = MySW.elapsed() - jumpDist;
  Serial.print(timeOnWall);
  Serial.print(" milisekunder");
  Serial.println();
  Serial.print("Total antal greb: ");
  finalCount = count;
  Serial.print(finalCount);
  Serial.println();
  Serial.println("_________________________________");
  MySW.reset();
  OffWall.reset();
}

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

void switchToPlayer2(boolean stone){
  flag = stone;
  if(flag==false){
        count++;
        MySW.start();
        OffWall.reset();
        turn = false;
        flag=true;
  }
}

void switchToPlayer1(boolean stone){
  flag = stone;
  if(flag==false){
        count++;
        MySW.start();
        OffWall.reset();
        turn = true;
        flag=true;
  }
}
