#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
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

boolean A1touched=false;
boolean B1touched=false;
boolean C1touched=false;
boolean D1touched=false;
boolean E1touched=false;

boolean A2touched=false;
boolean B2touched=false;
boolean C2touched=false;
boolean D2touched=false;
boolean E2touched=false;

// sensor value
long Ai; long Bi; long Ci; long Di; long Ei;
long Aii; long Bii; long Cii; long Dii; long Eii;

int sensivity = 5;

// game
boolean turn = true;
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
        lightA2(0,light,light);
      }
    
      if(pulseB2==true){
        lightB2(0,light,light);
      }
    
      if(pulseC2==true){
        lightC2(0,light,light);
      }
    
      if(pulseD2==true){
        lightD2(0,light,light);
      }
    
      if(pulseE2==true){
        lightE2(0,light,light);
      }
  
    if(Ai > 5000){
      if(flagA1 && A1touched==false){
        pulseA1=true;
        lightA2(light,0,0);
        flagA2=false;
        Serial.print("\n A1 touched");
        turn=false;
        A1touched=true;
      }
      if(flagA1==false){
        player2won=true;
      }
    }
  
    if(Bi > 1000){
      if(flagB1 && B1touched==false){
        pulseB1=true;
        lightB2(light,0,0);
        flagB2=false;
        Serial.print("\n B1 touched");
        turn=false;
        B1touched=true;
      }
      if(flagB1==false){
        player2won=true;
      }
    }
  
   if(Ci > 1000){
      if(flagC1 && C1touched==false){
        pulseC1=true;
        lightC2(light,0,0);
        flagC2=false;
        Serial.print("\n C1 touched");
        turn=false;
        C1touched=true;
      }
      if(flagC1==false){
        player2won=true;
      }
    }
  
   if(Di > 1000){
      if(flagD1 && D1touched==false){
        pulseD1=true;
        lightD2(light,0,0);
        flagD2=false;
        Serial.print("\n D1 touched");
        turn=false;
        D1touched=true;
      }
      if(flagD1==false){
        player2won=true;
      }
    }
  
    if(Ei*5 > 1000){
      if(flagE1 && E1touched==false){
        pulseE1=true;
        pulseE2=true;
        touchedStone=true;
        lightB1(light,light,0);
        lightB2(0,light,light);
        Serial.print("\n E1 touched");
        E1touched=true;
        E2touched=true;
      }
    }
  }

// ----

  if(turn==false){

      if(pulseA1==true){
        lightA1(light,light,0);
      }
    
      if(pulseB1==true){
        lightB1(light,light,0);
      }
    
      if(pulseC1==true){
        lightC1(light,light,0);
      }
    
      if(pulseD1==true){
        lightD1(light,light,0);
      }
    
      if(pulseE1==true){
        lightE1(light,light,0);
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

      Aii = grebA2.capacitiveSensor(sensivity);
      Bii = grebB2.capacitiveSensor(sensivity);
      Cii = grebC2.capacitiveSensor(sensivity);
      Dii = grebD2.capacitiveSensor(sensivity);
      Eii = grebE2.capacitiveSensor(sensivity);
    
    if(Aii > 1000){
      if(flagA2 && A2touched==false){
        pulseA2=true;
        lightA1(light,0,0);
        flagA1=false;
        Serial.print("\n A2 touched");
        turn=true;
        A2touched=true;
      }
      if(flagA2==false){
        player1won=true;
      }
    }
  
    if(Bii > 7000){
      if(flagB2 && B2touched==false){
        pulseB2=true;
        lightB1(light,0,0);
        flagB1=false;
        Serial.print("\n B2 touched");
        turn=true;
        B2touched=true;
      }
      if(flagB2==false){
        player1won=true;
      }
    }
  
   if(Cii > 2000){
      if(flagC2 && C2touched==false){
        pulseC2=true;
        lightC1(light,0,0);
        flagC1=false;
        Serial.print("\n C2 touched");
        turn=true;
        C2touched=true;
      }
      if(flagC2==false){
        player1won=true;
      }
    }
   
   if(Dii > 1000){
      if(flagD2 && D2touched==false){
        pulseD2=true;
        lightD1(light,0,0);
        flagD1=false;
        Serial.print("\n D2 touched");
        turn=true;
        D2touched=true;
      }
      if(flagD2==false){
        player1won=true;
      }
    }
  
    if(Eii > 2000){
      if(flagE2 && E2touched==false){
        pulseE2=true;
        pulseE1=true;
        touchedStone=true;
        lightB1(light,light,0);
        lightB2(0,light,light);
        Serial.print("\n E2 touched");
        E2touched=true;
        E1touched=true;
        
      }
    }
  }

  // når spillet er klaret
  
  if(player1won==true){
    for(int i=0; i<10; i++){
      player1blink();
       lightA2(light,0,0);
       lightB2(light,0,0);
       lightC2(light,0,0);
       lightD2(light,0,0);
       lightE2(light,0,0);
      delay(500);
      allLightsOff();
       lightA2(light,0,0);
       lightB2(light,0,0);
       lightC2(light,0,0);
       lightD2(light,0,0);
       lightE2(light,0,0);
      delay(500);
    }
     player1won=false;    
     reset();
     turn=false;
     
  }

  if(player2won==true){
    for(int i=0; i<10; i++){
      player2blink();
       lightA1(light,0,0);
       lightB1(light,0,0);
       lightC1(light,0,0);
       lightD1(light,0,0);
       lightE1(light,0,0);
      delay(500);
      allLightsOff();
       lightA1(light,0,0);
       lightB1(light,0,0);
       lightC1(light,0,0);
       lightD1(light,0,0);
       lightE1(light,0,0);
      delay(500);
    }
   player2won=false;
   reset();
   turn=true;
  }

  if(B1touched==true){
    player1won=true;
  }

  if(B2touched==true){
    player2won=true;
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
}

void player2blink(){
   lightA2(0,light,light);
   lightB2(0,light,light);
   lightC2(0,light,light);
   lightD2(0,light,light);
   lightE2(0,light,light);
}

void blinkA1(){
  int l = 255;
  lightA1(l,l,0);; 
   for(int i=0; i<10; i++){
        l -= 25;
        lightA1(l,l,0);;
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightA1(l,l,0);;
        delay(12);
      }
}

void blinkB1(){
  int l = 255;
  lightB1(l,l,0);; 
   for(int i=0; i<10; i++){
        l -= 25;
        lightB1(l,l,0);;
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightB1(l,l,0);;
        delay(12);
      }
}

void blinkC1(){
  int l = 255;
  lightC1(l,l,0);; 
   for(int i=0; i<10; i++){
        l -= 25;
        lightC1(l,l,0);;
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightC1(l,l,0);;
        delay(12);
      }
}

void blinkD1(){
  int l = 255;
  lightD1(l,l,0);; 
   for(int i=0; i<10; i++){
        l -= 25;
        lightD1(l,l,0);;
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightD1(l,l,0);;
        delay(12);
      }
}


void blinkE1(){
  int l = 255;
  lightE1(l,l,0);; 
   for(int i=0; i<10; i++){
        l -= 25;
        lightE1(l,l,0);;
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        lightE1(l,l,0);;
        delay(12);
      }
}

void blinkA2(){
  int l = 255;
  lightA2(0,l,l); 
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

void blinkB2(){
  int l = 255;
  lightB2(0,l,l); 
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

void blinkC2(){
  int l = 255;
  lightC2(0,l,l); 
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

void blinkD2(){
  int l = 255;
  lightD2(0,l,l); 
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

void blinkE2(){
  int l = 255;
  lightE2(0,l,l); 
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

void reset(){
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

     A1touched=false;
     B1touched=false;
     C1touched=false;
     D1touched=false;
     E1touched=false;
    
     A2touched=false;
     B2touched=false;
     C2touched=false;
     D2touched=false;
     E2touched=false;
     
     touchedStone=false;
}

