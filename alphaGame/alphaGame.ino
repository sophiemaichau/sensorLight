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
Adafruit_NeoPixel pixelB2 = Adafruit_NeoPixel(numPixels, pinPortB2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelC2 = Adafruit_NeoPixel(numPixels, pinPortC2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelD2 = Adafruit_NeoPixel(numPixels, pinPortD2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelE2 = Adafruit_NeoPixel(numPixels, pinPortE2, NEO_GRB + NEO_KHZ800);

CapacitiveSensor   grebA1 = CapacitiveSensor(39,33);
CapacitiveSensor   grebB1 = CapacitiveSensor(39,22);
CapacitiveSensor   grebC1 = CapacitiveSensor(39,27);
CapacitiveSensor   grebD1 = CapacitiveSensor(39,28);
CapacitiveSensor   grebE1 = CapacitiveSensor(39,34);

CapacitiveSensor   grebA2 = CapacitiveSensor(39,51);
CapacitiveSensor   grebB2 = CapacitiveSensor(39,40);
CapacitiveSensor   grebC2 = CapacitiveSensor(39,45);
CapacitiveSensor   grebD2 = CapacitiveSensor(39,46);
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

long preA2;
long prepreA2;
long avrA2;
boolean resultA2 = false;
boolean flagA2 = true;

long preB2;
long prepreB2;
long avrB2;
boolean resultB2 = false;
boolean flagB2 = true;

long preC2;
long prepreC2;
long avrC2;
boolean resultC2 = false;
boolean flagC2 = true;

long preD2;
long prepreD2;
long avrD2;
boolean resultD2 = false;
boolean flagD2 = true;

long preE2;
long prepreE2;
long avrE2;
boolean resultE2 = false;
boolean flagE2 = true;

// sensor value
// sensor value
long Ai; long Bi; long Ci; long Di; long Ei;
long Aii; long Bii; long Cii; long Dii; long Eii;

int sensivity = 1;

// game
boolean turn = true;
int count=0;

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

   allLightsOff();
}


void loop(){

      Ai = grebA1.capacitiveSensor(sensivity);
      Bi = grebB1.capacitiveSensor(30);
      Ci = grebC1.capacitiveSensor(30);
      Di = grebD1.capacitiveSensor(30);
      Ei = grebE1.capacitiveSensor(30);

      Aii = grebA2.capacitiveSensor(30);
      Bii = grebB2.capacitiveSensor(30);
      Cii = grebC2.capacitiveSensor(30);
      Dii = grebD2.capacitiveSensor(sensivity);
      Eii = grebE2.capacitiveSensor(sensivity);

  if(turn==true){
    if(Ai > 1000){
      if(flagA1){
      lightA1(light,0,light);
      lightA2(0,light,0);
      check1();
      Serial.print("\n A1 touched");
      flagA1=false;
      flagA2=false;
      turn=false;
      count++;
      }
    }
  
    if(Bi > 1000){
      if(flagB1){
      lightB1(light,0,light);
      lightB2(0,light,0);
      check1();
      Serial.print("\n B1 touched");
      flagB1=false;
      flagB2=false;
      turn=false;
      count++;
      }
    }
  
   if(Ci > 600){
      if(flagC1){
      lightC1(light,0,light);
      lightC2(0,light,0);
      check1();
      Serial.print("\n C1 touched");
      flagC1=false;
      flagC2=false;
      turn=false;
      count++;
      }
    }
  
   if(Di > 600){
      if(flagD1){
      lightD1(light,0,light);
      lightD2(0,light,0);
      check1();
      Serial.print("\n D1 touched");
      flagD1=false;
      flagD2=false;
      turn=false;
      count++;
      }
    }
  
    if(Ei > 600){
      if(flagE1){
        lightE1(light,0,light);
        lightE2(0,light,0);
        check1();
        Serial.print("\n E1 touched");
        flagE1=false;
        flagE2=false;
        turn=false;
        count++;
      }
    }
  }

// ----

  if(turn==false){
    if(Aii > 1000){
      if(flagA2){
      lightA2(light,0,light);
      lightA1(0,light,0);
      check2();
      Serial.print("\n A2 touched");
      flagA2=false;
      flagA1=false;
      turn=true;
      count++;
      }
    }
  
    if(Bii > 1000){
      if(flagB2){
      lightB2(light,0,light);
      lightB1(0,light,0);
      check2();
      Serial.print("\n B2 touched");
      flagB2=false;
      flagB1=false;
      turn=true;
      count++;
      }
    }
  
   if(Cii > 1000){
      if(flagC2){
      lightC2(light,0,light);
      lightC1(0,light,0);
      check2();
      Serial.print("\n C2 touched");
      flagC2=false;
      flagC1=false;
      turn=true;
      count++;
      }
    }
   
   if(D2touch()){
      if(flagD2){
      lightD2(light,0,light);
      lightD1(0,light,0);
      check2();
      Serial.print("\n D2 touched");
      flagD2=false;
      flagD1=false;
      turn=true;
      count++;
      }
    }
  
    if(Eii > 1000){
      if(flagE2){
        lightE2(light,0,light);
        lightC1(0,light,0);
        check2();
        Serial.print("\n E2 touched");
        flagE2=false;
        flagE1=false;
        turn=true;
        count++;
      }
    }
  }

  if(count==5){
    for(int i=0; i<10; i++){
      allLightsOn();
      delay(500);
      allLightsOff();
      delay(500);
    }
    count=0;
  }
}

// --- algoritme til gennemsnit


boolean D2touch(){
  boolean capFlag = false; 

  if(Dii > 250 && Dii > avrD2*3){
    resultD2 = true;
  }

  if(capFlag==false){
    preD2 = Dii;
    capFlag=true;
  }
  if(capFlag==true){
    prepreD2=Dii;
    capFlag=false;
  }
  
  avrD2 = (preD2+prepreD2)/2;

  return resultD2;
}

// check lys

void check1(){
  if(flagA1==false){
    lightA1(light,0,light);
  }

  if(flagB1==false){
    lightB1(light,0,light);
  }

  if(flagC1==false){
    lightC1(light,0,light);
  }

  if(flagD1==false){
    lightD1(light,0,light);
  }

  if(flagE1==false){
    lightE1(light,0,light);
  }  
}

void check2(){
  if(flagA2==false){
    lightA2(light,0,light);
  }

  if(flagB2==false){
    lightB2(light,0,light);
  }

  if(flagC2==false){
    lightC2(light,0,light);
  }

  if(flagD2==false){
    lightD2(light,0,light);
  }

  if(flagE2==false){
    lightE2(light,0,light);
  }  
}

// ------ lys

void lightA1(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelA1.setPixelColor(i, pixelA1.Color(r,g,b));
      }
      pixelA1.show();
}

void lightB1(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelB1.setPixelColor(i, pixelB1.Color(r,g,b));
      }
      pixelB1.show();
}

void lightC1(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelC1.setPixelColor(i, pixelC1.Color(r,g,b));
      }
      pixelC1.show();
}

void lightD1(int r, int g, int b){
     for(int i=0;i<2;i++){
        pixelD1.setPixelColor(i, pixelD1.Color(r,g,b));
      }
      pixelD1.show();
}

void lightE1(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelE1.setPixelColor(i, pixelE1.Color(r,g,b));
      }
      pixelE1.show();
}

void lightA2(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelA2.setPixelColor(i, pixelA2.Color(r,g,b));
      }
      pixelA2.show();
}

void lightB2(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelB2.setPixelColor(i, pixelB2.Color(r,g,b));
      }
      pixelB2.show();
}

void lightC2(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelC2.setPixelColor(i, pixelC2.Color(r,g,b));
      }
      pixelC2.show();
}

void lightD2(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelD2.setPixelColor(i, pixelD2.Color(r,g,b));
      }
      pixelD2.show();
}

void lightE2(int r, int g, int b){
     for(int i=0;i<numPixels;i++){
        pixelE2.setPixelColor(i, pixelE2.Color(r,g,b));
      }
      pixelE2.show();
}

void allLightsOn(){
   lightA1(light,0,light);
   lightB1(light,0,light);
   lightC1(light,0,light);
   lightD1(light,0,light);
   lightE1(light,0,light);
   lightA2(light,0,light);
   lightB2(light,0,light);
   lightC2(light,0,light);
   lightD2(light,0,light);
   lightE2(light,0,light);
}

void allLightsOff(){
   lightA1(0,0,0);
   lightB1(0,0,0);
   lightC1(0,0,0);
   lightD1(0,0,0);
   lightE1(0,0,0);
   lightA2(0,0,0);
   lightB2(0,0,0);
   lightC2(0,0,0);
   lightD2(0,0,0);
   lightE2(0,0,0);
}

