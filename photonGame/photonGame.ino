#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
#include "StopWatch.h"
#include <SoftwareSerial.h>

SoftwareSerial ser(10,11);

#define pinPortA1 14
#define pinPortB1 13
#define pinPortC1 12
#define pinPortD1 15
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

int sensivity = 5;

// game
boolean turn = true;
int count=0;

boolean pulseA1=false;
boolean pulseB1=false;
boolean pulseC1=false;
boolean pulseD1=false;
boolean pulseE1=false;

boolean pulseA2=false;
boolean pulseB2=false;
boolean pulseC2=false;
boolean pulseD2=false;
boolean pulseE2=false;

boolean pulseA1again=false;
boolean pulseB1again=false;
boolean pulseC1again=false;
boolean pulseD1again=false;
boolean pulseE1again=false;

boolean pulseA2again=false;
boolean pulseB2again=false;
boolean pulseC2again=false;
boolean pulseD2again=false;
boolean pulseE2again=false;

boolean touchedStone=false;

char x;

// flere flag
boolean flagA1once=false;
boolean flagB1once=false;
boolean flagC1once=false;
boolean flagD1once=false;
boolean flagE1once=false;

boolean flagA2once=false;
boolean flagB2once=false;
boolean flagC2once=false;
boolean flagD2once=false;
boolean flagE2once=false;

void setup()                    
{
   Serial.begin(9600);
   ser.begin(9600);
   
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

    Serial.print("\n A1: "); Serial.print(Ai); 
    Serial.print("\n B1: "); Serial.print(Bi); 
    Serial.print("\n C1: "); Serial.print(Ci); 
    Serial.print("\n D1: "); Serial.print(Di); 
    Serial.print("\n E1: "); Serial.print(Ei*5);
    Serial.print("\n ");

    Serial.print("\n A2: "); Serial.print(Aii); 
    Serial.print("\n B2: "); Serial.print(Bii); 
    Serial.print("\n C2: "); Serial.print(Cii); 
    Serial.print("\n D2: "); Serial.print(Dii); 
    Serial.print("\n E2: "); Serial.print(Eii);
    Serial.print("\n ");

  // printer information ud, sendt fra app
  x = ser.read();
  if(ser.available()){
    if(x=='t'){
    Serial.write(x);
    }
  }
  
  if(touchedStone==false){
    
    for(int i=0; i<5; i++){
    // spiller 1 er gul og spiller 2 er tyrkis
    lightE1(light,light,0);
    lightE2(0,light,light);
    lightB1(light,light,0);
    lightB2(0,light,light);
    delay(25);
    }

    for(int i=0; i<5; i++){
    allLightsOff();
    delay(25);
    }
  }
   

  if(turn==true){

      Ai = grebA1.capacitiveSensor(sensivity);
      Bi = grebB1.capacitiveSensor(sensivity);
      Ci = grebC1.capacitiveSensor(sensivity);
      Di = grebD1.capacitiveSensor(sensivity);
      Ei = grebE1.capacitiveSensor(sensivity);
  
    if(Ai > 5000){
      if(flagA1){
      check1();
      lightA1(light,light,0);
      pulseA2=true;
      Serial.print("\n A1 touched");
      flagA2once=true;
      flagA1=false;
      flagA2=false;
      turn=false;
      count++;
      }
      if(flagA1once==true){
        pulseA1=false;
        pulseA1again=true;
      }
    }
  
    if(Bi > 1000){
      if(flagB1){
      check1();
      lightB1(light,light,0);
      pulseB2=true;
      Serial.print("\n B1 touched");
      flagB2once=true;
      flagB1=false;
      flagB2=false;
      turn=false;
      count++;
      }
      if(flagB1once==true){
        pulseB1=false;
        pulseB1again=true;
      }
    }
  
   if(Ci > 1000){
      if(flagC1){
      check1();
      lightC1(light,light,0);
      pulseC2=true;
      Serial.print("\n C1 touched");
      flagC2once=true;
      flagC1=false;
      flagC2=false;
      turn=false;
      count++;
      }
      if(flagC1once==true){
        pulseC1=false;
        pulseC1again=true;
      }
    }
  
   if(Di > 1000){
      if(flagD1){
      check1();
      lightD1(light,light,0);
      pulseD2=true;
      Serial.print("\n D1 touched");
      flagD2once=true;
      flagD1=false;
      flagD2=false;
      turn=false;
      count++;
      }
      if(flagD1once==true){
        pulseD1=false;
        pulseD1again=true;
      }
    }
  
    if(Ei*5 > 1000){
      if(flagE1){
        lightE1(light,light,0);
        pulseE2=true;
        touchedStone=true;
        lightB1(light,light,0);
        lightB2(0,light,light);
        Serial.print("\n E1 touched");
        flagE1=false;
        flagE2=false;
        flagE2once=true;
        turn=false;
        count++;
      }
    }
  }

// ----

  if(turn==false){

      Aii = grebA2.capacitiveSensor(sensivity);
      Bii = grebB2.capacitiveSensor(sensivity);
      Cii = grebC2.capacitiveSensor(sensivity);
      Dii = grebD2.capacitiveSensor(sensivity);
      Eii = grebE2.capacitiveSensor(sensivity);
    
    if(Aii > 1000){
      if(flagA2){
        check2();
        lightA2(0,light,light);
        pulseA1=true;
        Serial.print("\n A2 touched");
        flagA1once=true;
        flagA2=false;
        flagA1=false;
        turn=true;
        count++;
      }
      if(flagA2once==true){
        pulseA2=false;
        pulseA2again=true;
      }
    }
  
    if(Bii > 7000){
      if(flagB2){
        check2();
        lightB2(0,light,light);
        pulseB1=true;
        Serial.print("\n B2 touched");
        flagB1once=true;
        flagB2=false;
        flagB1=false;
        turn=true;
        count++;
      }
      if(flagB2once==true){
        pulseB2=false;
        pulseB2again=true;
      }
    }
  
   if(Cii > 2000){
      if(flagC2){
        check2();
        lightC2(0,light,light);
        pulseC1=true;
        Serial.print("\n C2 touched");
        flagC1once=true;
        flagC2=false;
        flagC1=false;
        turn=true;
        count++;
      }
      if(flagC2once==true){
        pulseC2=false;
        pulseC2again=true;
      }
    }
   
   if(Dii > 1000){
      if(flagD2){
        check2();
        lightD2(0,light,light);
        pulseD1=true;
        Serial.print("\n D2 touched");
        flagD1=false;
        flagD2=false;
        flagD1once=true;
        turn=true;
        count++;
      }
      if(flagD2once==true){
        pulseD2=false;
        pulseD2again=true;
      }
    }
  
    if(Eii > 2000){
      if(flagE2once==true){
        pulseE2=false;
        pulseE2again=true;
      }
    }
  }

  if(pulseA1==true){
    blinkA1();
  }

  if(pulseB1==true){
    blinkB1();
  }

  if(pulseC1==true){
    blinkC1();
  }

  if(pulseD1==true){
    blinkD1();
  }

  if(pulseE1==true){
    blinkE1();
  }

  if(pulseA2==true){
    blinkA2();
  }

  if(pulseB2==true){
    blinkB2();
  }

  if(pulseC2==true){
    blinkC2();
  }

  if(pulseD2==true){
    blinkD2();
  }

  if(pulseE2==true){
    blinkE2();
  }

  // ------------

   if(pulseA1again==true){
    blinkA1again();
  }

  if(pulseB1again==true){
    blinkB1again();
  }

  if(pulseC1again==true){
    blinkC1again();
  }

  if(pulseD1again==true){
    blinkD1again();
  }

  if(pulseE1again==true){
    blinkE1again();
  }


  if(pulseA2again==true){
    blinkA2again();
  }

  if(pulseB2again==true){
    blinkB2again();
  }

  if(pulseC2again==true){
    blinkC2again();
  }

  if(pulseD2again==true){
    blinkD2again();
  }

  if(pulseE2again==true){
    blinkE2again();
  }

  // når spillet er klaret
  if(flagB1==false && flagB2==false){
    for(int i=0; i<10; i++){
      allLightsOn();
      delay(500);
      allLightsOff();
      delay(500);
    }
    count=0;
    touchedStone=false;
    //x='anything';
  }
  
  if(count==0){
    allLightsOff();
    flagA1=true;
    flagB1=true;
    flagC1=true;
    flagD1=true;
    flagE1=true;
    flagA2=true;
    flagB2=true;
    flagC2=true;
    flagD2=true;
    flagE2=true;

    pulseA1=false;
    pulseB1=false;
    pulseC1=false;
    pulseD1=false;
    pulseE1=false;
    pulseA2=false;
    pulseB2=false;
    pulseC2=false;
    pulseD2=false;
    pulseE2=false;
    
    turn=true;
  }
}

// check lys

void check1(){
  if(flagA1==false){
    pulseA1again=false;
    lightA1(light,light,0);
  }

  if(flagB1==false){
    pulseB1again=false;
    lightB1(light,light,0);
  }

  if(flagC1==false){
    pulseC1again=false;
    lightC1(light,light,0);
  }

  if(flagD1==false){
    pulseD1again=false;
    lightD1(light,light,0);
  }

  if(flagE1==false){
    pulseE1again=false;
    lightE1(light,light,0);
  }  
}

void check2(){
  if(flagA2==false){
    pulseA2again=false;
    lightA2(0,light,light);
  }

  if(flagB2==false){
    pulseB2again=false;
    lightB2(0,light,light);
  }

  if(flagC2==false){
    pulseC2again=false;
    lightC2(0,light,light);
  }

  if(flagD2==false){
    pulseD2again=false;
    lightD2(0,light,light);
  }

  if(flagE2==false){
    pulseE2again=false;
    flagE2once=false;
    lightE2(0,light,light);
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
   lightA1(0,light,0);
   lightB1(0,light,0);
   lightC1(0,light,0);
   lightD1(0,light,0);
   lightE1(0,light,0);
   lightA2(0,light,0);
   lightB2(0,light,0);
   lightC2(0,light,0);
   lightD2(0,light,0);
   lightE2(0,light,0);
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

// pulserende lys

void blinkA1(){
  int l = 255;
  lightA1(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightA1(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightA1(0,l,l);
        delay(12);
      }
}

void blinkB1(){
  int l = 255;
  lightB1(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightB1(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightB1(0,l,l);
        delay(12);
      }
}

void blinkC1(){
  int l = 255;
  lightC1(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightC1(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightC1(0,l,l);
        delay(12);
      }
}

void blinkD1(){
  int l = 255;
  lightD1(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightD1(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightD1(0,l,l);
        delay(12);
      }
}


void blinkE1(){
  int l = 255;
  lightE1(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightE1(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightE1(0,l,l);
        delay(12);
      }
}

void blinkA2(){
  int l = 255;
  lightA2(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightA2(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightA2(l,l,0);
        delay(12);
      }
}

void blinkB2(){
  int l = 255;
  lightB2(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightB2(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightB2(l,l,0);
        delay(12);
      }
}

void blinkC2(){
  int l = 255;
  lightC2(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightC2(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightC2(l,l,0);
        delay(12);
      }
}

void blinkD2(){
  int l = 255;
  lightD2(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightD2(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightD2(l,l,0);
        delay(12);
      }
}

void blinkE2(){
  int l = 255;
  lightE2(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightE2(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightE2(l,l,0);
        delay(12);
      }
}

// -------------------

void blinkA2again(){
  int l = 255;
  lightA2(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightA2(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightA2(0,l,l);
        delay(12);
      }
}

void blinkB2again(){
  int l = 255;
  lightB2(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightB2(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightB2(0,l,l);
        delay(12);
      }
}

void blinkC2again(){
  int l = 255;
  lightC2(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightC2(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightC2(0,l,l);
        delay(12);
      }
}

void blinkD2again(){
  int l = 255;
  lightD2(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightD2(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightD2(0,l,l);
        delay(12);
      }
}


void blinkE2again(){
  int l = 255;
  lightE2(l,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightE2(0,l,l);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightE2(0,l,l);
        delay(12);
      }
}


void blinkA1again(){
  int l = 255;
  lightA1(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightA1(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightA1(l,l,0);
        delay(12);
      }
}

void blinkB1again(){
  int l = 255;
  lightB1(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightB1(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightB1(l,l,0);
        delay(12);
      }
}

void blinkC1again(){
  int l = 255;
  lightC1(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightC1(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightC1(l,l,0);
        delay(12);
      }
}

void blinkD1again(){
  int l = 255;
  lightD1(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightD1(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightD1(l,l,0);
        delay(12);
      }
}

void blinkE1again(){
  int l = 255;
  lightE1(l,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        lightE1(l,l,0);
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightE1(l,l,0);
        delay(12);
      }
}



