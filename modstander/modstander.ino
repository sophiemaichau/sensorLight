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

boolean flagA1 = true;
boolean flagB1 = true;
boolean flagC1 = true;
boolean flagD1 = true;
boolean flagE1 = true;

boolean flagA2 = true;
boolean flagB2 = true;
boolean flagC2 = true;
boolean flagD2 = true;
boolean flagE2 = true;

// sensor value
long Ai; long Bi; long Ci; long Di; long Ei;
long Aii; long Bii; long Cii; long Dii; long Eii;

int sensivity = 5;

// game
boolean turn = true;
int count=0;
boolean touchedStone=false;

boolean player1won=false;
boolean player2won=false;

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

//    Serial.print("\n A1: "); Serial.print(Ai); 
//    Serial.print("\n B1: "); Serial.print(Bi); 
//    Serial.print("\n C1: "); Serial.print(Ci); 
//    Serial.print("\n D1: "); Serial.print(Di); 
//    Serial.print("\n E1: "); Serial.print(Ei*5);
//    Serial.print("\n ");
//
//    Serial.print("\n A2: "); Serial.print(Aii); 
//    Serial.print("\n B2: "); Serial.print(Bii); 
//    Serial.print("\n C2: "); Serial.print(Cii); 
//    Serial.print("\n D2: "); Serial.print(Dii); 
//    Serial.print("\n E2: "); Serial.print(Eii);
//    Serial.print("\n ");

  
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
      Serial.print("\n A1 touched");
      flagA1=false;
      flagA2=false;
      turn=false;
      }
    }
  
    if(Bi > 1000){
      if(flagB1){
      check1();
      lightB1(light,light,0);
      Serial.print("\n B1 touched");
      flagB1=false;
      turn=false;
      }
    }
  
   if(Ci > 1000){
      if(flagC1){
      check1();
      lightC1(light,light,0);
      Serial.print("\n C1 touched");
      flagC1=false;
      flagC2=false;
      turn=false;
      }
    }
  
   if(Di > 1000){
      if(flagD1){
      check1();
      lightD1(light,light,0);
      Serial.print("\n D1 touched");
      flagD1=false;
      flagD2=false;
      turn=false;
      }
    }
  
    if(Ei*5 > 1000){
      if(flagE1){
        lightE1(light,light,0);
        lightE2(light,0,0);
        touchedStone=true;
        lightB1(light,light,0);
        lightB2(0,light,light);
        Serial.print("\n E1 touched");
        flagE2=false;
        turn=false;
      }
      if(flagE1==false){
        player2won=true;
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
        Serial.print("\n A2 touched");
        flagA2=false;
        flagA1=false;
        turn=true;
      }
    }
  
    if(Bii > 7000){
      if(flagB2){
        check2();
        lightB2(0,light,light);
        Serial.print("\n B2 touched");
        flagB2=false;
        turn=true;
      }
    }
  
   if(Cii > 2000){
      if(flagC2){
        check2();
        lightC2(0,light,light);
        Serial.print("\n C2 touched");
        flagC2=false;
        flagC1=false;
        turn=true;
      }
    }
   
   if(Dii > 1000){
      if(flagD2){
        lightD2(0,light,light);
        lightD1(light,0,0);
        Serial.print("\n D2 touched");
        flagD1=false;
        flagD2=false;
        turn=true;
      }
      if(flagD2==false){
        player1won=true;
      }
    }
  
    if(Eii > 2000){
       if(flagE2){
        lightE2(0,light,light);
        lightE1(light,0,0);
        touchedStone=true;
        lightB1(light,light,0);
        lightB2(0,light,light);
        Serial.print("\n E2 touched");
        flagE1=false;
        turn=true;
      }
      if(flagE2==false){
        player1won=true;
      }
    }
  }

  // når spillet er klaret
  
  if(player1won==true){
    for(int i=0; i<10; i++){
      player1blink();
      delay(500);
      allLightsOff();
      delay(500);
    }
    count=0;
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
    turn=false;
    touchedStone=false;
  }

  if(player2won==true){
    for(int i=0; i<10; i++){
      player2blink();
      delay(500);
      allLightsOff();
      delay(500);
    }
    count=0;
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
    turn=true;
    touchedStone=false;
  }
 
}

// check lys

void check1(){
  if(flagA1==false){
    lightA1(light,light,0);
  }

  if(flagB1==false){
    lightB1(light,light,0);
  }

  if(flagC1==false){
    lightC1(light,light,0);
  }

  if(flagD1==false){
    lightD1(light,light,0);
  }

  if(flagE1==false){
    lightE1(light,light,0);
  }  
}

void check2(){
  if(flagA2==false){
    lightA2(0,light,light);
  }

  if(flagB2==false){
    lightB2(0,light,light);
  }

  if(flagC2==false){
    lightC2(0,light,light);
  }

  if(flagD2==false){
    lightD2(0,light,light);
  }

  if(flagE2==false){
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

void player1blink(){
   lightA1(light,light,0);
   lightB1(light,light,0);
   lightC1(light,light,0);
   lightD1(light,light,0);
   lightE1(light,light,0);
   lightA2(light,light,0);
   lightB2(light,light,0);
   lightC2(light,light,0);
   lightD2(light,light,0);
   lightE2(light,light,0);
}

void player2blink(){
   lightA2(0,light,light);
   lightB2(0,light,light);
   lightC2(0,light,light);
   lightD2(0,light,light);
   lightE2(0,light,light);
   lightA2(0,light,light);
   lightB2(0,light,light);
   lightC2(0,light,light);
   lightD2(0,light,light);
   lightE2(0,light,light);
}

