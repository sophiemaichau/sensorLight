#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

SoftwareSerial ser(10,11); // RX, TX

int game = 0;

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

int valueAi = 900;
int valueBi = 800;
int valueCi = 800;
int valueDi = 500;
int valueEi = 500;

int valueAii = 500;
int valueBii = 600;
int valueCii = 500;
int valueDii = 200;
int valueEii = 500;


int light = 255;
int less = 70;

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

int sensivity = 10;

// game
boolean turn = true;

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

boolean player1won=false;
boolean player2won=false;

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

int count = 0;

void setup() {
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

 
void loop() {
  x = ser.read();

  if(x=='t'){
    // samarbejdende
    game = 1;
  }
  if(x=='o'){
   // modstander
    game = 2;
  }

  switch(game){
    case 1:
      function1();
      break;
    case 2:
      function2();
      break;
  }
} 

void function1(){
  if(touchedStone==false){
    
    for(int i=0; i<5; i++){
    // spiller 1 er lime og spiller 2 er violet
    lightE1(less,light,0);
    lightE2(less,0,light);
    lightB1(less,light,0);
    lightB2(less,0,light);
    delay(25);
    }

    for(int i=0; i<5; i++){
    allLightsOff();
    delay(25);
    }

    if(turn==false){
      turn=true;
    }
  }
   

  if(turn==true){

      Ai = grebA1.capacitiveSensor(sensivity);
      Bi = grebB1.capacitiveSensor(sensivity);
      Ci = grebC1.capacitiveSensor(sensivity);
      Di = grebD1.capacitiveSensor(sensivity);
      Ei = grebE1.capacitiveSensor(sensivity);
  
    if(Ai > valueAi){
      if(flagA1){
      check1();
      lightA1(less,light,0);
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
  
    if(Bi > valueBi){
      if(flagB1){
      check1();
      lightB1(0,0,0);
      delay(500);
      lightB1(less,light,0);
      //pulseB1again=true;
      pulseB2=true;
      Serial.print("\n B1 touched");
      flagB2once=true;
      flagB1=false;
      turn=false;
      count++;
      }
      if(flagB1once==true){
        pulseB1=false;
        pulseB1again=true;
      }
    }
  
   if(Ci > valueCi){
      if(flagC1){
      check1();
      lightC1(less,light,0);
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
  
   if(Di > valueDi){
      if(flagD1){
      check1();
      lightD1(less,light,0);
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
  
    if(Ei > valueEi){
      if(flagE1){
        lightE1(less,light,0);
        pulseE2=true;
        touchedStone=true;
        lightB1(less,light,0);
        lightB2(less,0,light);
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
    
    if(Aii > valueAii){
      if(flagA2){
        check2();
        lightA2(less,0,light);
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
  
    if(Bii > valueBii){
      if(flagB2){
        check2();
        lightB2(0,0,0);
        delay(500);
        lightB2(less,0,light);
        //pulseB2again=true;
        pulseB1=true;
        Serial.print("\n B2 touched");
        flagB1once=true;
        flagB2=false;
        turn=true;
        count++;
      }
      if(flagB2once==true){
        pulseB2=false;
        pulseB2again=true;
      }
    }
  
   if(Cii > valueCii){
      if(flagC2){
        check2();
        lightC2(less,0,light);
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
   
   if(Dii > valueDii){
      if(flagD2){
        check2();
        lightD2(less,0,light);
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
  
    if(Eii > valueEii){
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
      player1blink();
      player2blink();
      delay(500);
      allLightsOff();
      delay(500);
    }
    count=0;
    touchedStone=false;
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

   flagA1once=false;
   flagB1once=false;
   flagC1once=false;
   flagD1once=false;
   flagE1once=false;
  
   flagA2once=false;
   flagB2once=false;
   flagC2once=false;
   flagD2once=false;
   flagE2once=false; 

   pulseA1again=false;
   pulseB1again=false;
   pulseC1again=false;
   pulseD1again=false;
   pulseE1again=false;
  
   pulseA2again=false;
   pulseB2again=false;
   pulseC2again=false;
   pulseD2again=false;
   pulseE2again=false;
 
    turn=true;

    touchedStone=false;
  }
}

void function2(){
  if(touchedStone==false){
    
    for(int i=0; i<5; i++){
    // spiller 1 er gul og spiller 2 er tyrkis
    lightE1(less,light,0);
    lightE2(less,0,light);
    lightB1(less,light,0);
    lightB2(less,0,light);
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
        blinkA1again();
      }
    
      if(pulseB1==true){
        blinkB1again();
      }
    
      if(pulseC1==true){
        blinkC1again();
      }
    
      if(pulseD1==true){
        blinkD1again();
      }
    
      if(pulseE1==true){
        blinkE1again();
      }
    
      if(pulseA2==true){
        lightA2(less,0,light);
      }
    
      if(pulseB2==true){
        lightB2(less,0,light);
      }
    
      if(pulseC2==true){
        lightC2(less,0,light);
      }
    
      if(pulseD2==true){
        lightD2(less,0,light);
      }
    
      if(pulseE2==true){
        lightE2(less,0,light);
      }
  
    if(Ai > valueAi){
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
  
    if(Bi > valueBi){
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
  
   if(Ci > valueCi){
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
  
   if(Di > valueDi){
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
  
    if(Ei > valueEi){
      if(flagE1 && E1touched==false){
        pulseE1=true;
        pulseE2=true;
        touchedStone=true;
        lightB1(less,light,0);
        lightB2(less,0,light);
        Serial.print("\n E1 touched");
        E1touched=true;
        E2touched=true;
      }
    }
  }

// ----

  if(turn==false){

      if(pulseA1==true){
        lightA1(less,light,0);
      }
    
      if(pulseB1==true){
        lightB1(less,light,0);
      }
    
      if(pulseC1==true){
        lightC1(less,light,0);
      }
    
      if(pulseD1==true){
        lightD1(less,light,0);
      }
    
      if(pulseE1==true){
        lightE1(less,light,0);
      }

      if(pulseA2==true){
        blinkA2again();
      }
    
      if(pulseB2==true){
        blinkB2again();
      }
    
      if(pulseC2==true){
        blinkC2again();
      }
    
      if(pulseD2==true){
        blinkD2again();
      }
    
      if(pulseE2==true){
        blinkE2again();
      }

      Aii = grebA2.capacitiveSensor(sensivity);
      Bii = grebB2.capacitiveSensor(sensivity);
      Cii = grebC2.capacitiveSensor(sensivity);
      Dii = grebD2.capacitiveSensor(sensivity);
      Eii = grebE2.capacitiveSensor(sensivity);
    
    if(Aii > valueAii){
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
  
    if(Bii > valueBii){
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
  
   if(Cii > valueCii){
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
   
   if(Dii > valueDii){
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
  
    if(Eii > valueEii){
      if(flagE2 && E2touched==false){
        pulseE2=true;
        pulseE1=true;
        touchedStone=true;
        lightB1(less,light,0);
        lightB2(less,0,light);
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
      looserBlink2();
      delay(500);
      allLightsOff();
      delay(500);
    }
     player1won=false;    
     reset();
     turn=false;
     
  }

  if(player2won==true){
    for(int i=0; i<10; i++){
      player2blink();
      looserBlink1();
      delay(500);
      allLightsOff();
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


// ---------------

// check lys

void check1(){
  if(flagA1==false){
    pulseA1again=false;
    lightA1(less,light,0);
  }

  if(flagB1==false){
    pulseB1again=false;
    lightB1(less,light,0);
  }

  if(flagC1==false){
    pulseC1again=false;
    lightC1(less,light,0);
  }

  if(flagD1==false){
    pulseD1again=false;
    lightD1(less,light,0);
  }

  if(flagE1==false){
    pulseE1again=false;
    lightE1(less,light,0);
  }  
}

void check2(){
  if(flagA2==false){
    pulseA2again=false;
    lightA2(less,0,light);
  }

  if(flagB2==false){
    pulseB2again=false;
    lightB2(less,0,light);
  }

  if(flagC2==false){
    pulseC2again=false;
    lightC2(less,0,light);
  }

  if(flagD2==false){
    pulseD2again=false;
    lightD2(less,0,light);
  }

  if(flagE2==false){
    pulseE2again=false;
    flagE2once=false;
    lightE2(less,0,light);
  }
}

// --
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

// lime green
//void allLightsOn(){
//   lightA1(70,255,0);
//   lightB1(70,255,0);
//   lightC1(70,255,0);
//   lightD1(70,255,0);
//   lightE1(70,255,0);
//   lightA2(70,255,0);
//   lightB2(70,255,0);
//   lightC2(70,255,0);
//   lightD2(70,255,0);
//   lightE2(70,255,0);
//}

// violet
void allLightsOn(){
   lightA1(70,0,255);
   lightB1(70,0,255);
   lightC1(70,0,255);
   lightD1(70,0,255);
   lightE1(70,0,255);
   lightA2(70,0,255);
   lightB2(70,0,255);
   lightC2(70,0,255);
   lightD2(70,0,255);
   lightE2(70,0,255);
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
  int k = 70;
  lightA1(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightA1(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightA1(k,0,l); 
        delay(12);
      }
}

void blinkB1(){
  int l = 255;
  int k = 70;
  lightB1(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightB1(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightB1(k,0,l); 
        delay(12);
      }
}

void blinkC1(){
  int l = 255;
  int k = 70;
  lightC1(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightC1(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightC1(k,0,l); 
        delay(12);
      }
}

void blinkD1(){
  int l = 255;
  int k = 70;
  lightD1(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightD1(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightD1(k,0,l); 
        delay(12);
      }
}

void blinkE1(){
  int l = 255;
  int k = 70;
  lightE1(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightE1(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightE1(k,0,l); 
        delay(12);
      }
}

void blinkA2(){
  int l = 255;
  int k = 70;
  lightA2(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightA2(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightA2(k,l,0); 
        delay(12);
      }
}

void blinkB2(){
  int l = 255;
  int k = 70;
  lightB2(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightB2(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightB2(k,l,0); 
        delay(12);
      }
}

void blinkC2(){
  int l = 255;
  int k = 70;
  lightC2(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightC2(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightC2(k,l,0); 
        delay(12);
      }
}

void blinkD2(){
  int l = 255;
  int k = 70;
  lightD2(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightD2(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightD2(k,l,0); 
        delay(12);
      }
}


void blinkE2(){
  int l = 255;
  int k = 70;
  lightE2(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightE2(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightE2(k,l,0); 
        delay(12);
      }
}

// ------------------- again

void blinkA1again(){
  int l = 255;
  int k = 70;
  lightA1(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightA1(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightA1(k,l,0); 
        delay(12);
      }
}

void blinkB1again(){
  int l = 255;
  int k = 70;
  lightB1(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightB1(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightB1(k,l,0); 
        delay(12);
      }
}

void blinkC1again(){
  int l = 255;
  int k = 70;
  lightC1(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightC1(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightC1(k,l,0); 
        delay(12);
      }
}

void blinkD1again(){
  int l = 255;
  int k = 70;
  lightD1(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightD1(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightD1(k,l,0); 
        delay(12);
      }
}


void blinkE1again(){
  int l = 255;
  int k = 70;
  lightE1(k,l,0); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightE1(k,l,0); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightE1(k,l,0); 
        delay(12);
      }
}

void blinkA2again(){
  int l = 255;
  int k = 70;
  lightA2(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightA2(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightA2(k,0,l); 
        delay(12);
      }
}

void blinkB2again(){
  int l = 255;
  int k = 70;
  lightB2(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightB2(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightB2(k,0,l); 
        delay(12);
      }
}

void blinkC2again(){
  int l = 255;
  int k = 70;
  lightC2(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightC2(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightC2(k,0,l); 
        delay(12);
      }
}

void blinkD2again(){
  int l = 255;
  int k = 70;
  lightD2(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightD2(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightD2(k,0,l); 
        delay(12);
      }
}

void blinkE2again(){
  int l = 255;
  int k = 70;
  lightE2(k,0,l); 
   for(int i=0; i<10; i++){
        l -= 25;
        k -= 7;
        lightE2(k,0,l); 
        delay(12);
      }
   for(int i=0; i<10; i++){
        l += 25;
        k += 7;
        lightE2(k,0,l); 
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

void player1blink(){
   lightA1(less,light,0);
   lightB1(less,light,0);
   lightC1(less,light,0);
   lightD1(less,light,0);
   lightE1(less,light,0);
}

void player2blink(){
   lightA2(less,0,light);
   lightB2(less,0,light);
   lightC2(less,0,light);
   lightD2(less,0,light);
   lightE2(less,0,light);
}

void looserBlink1(){
  lightA1(light,0,0);
  lightB1(light,0,0);
  lightC1(light,0,0);
  lightD1(light,0,0);
  lightE1(light,0,0);
}

void looserBlink2(){
  lightA2(light,0,0);
  lightB2(light,0,0);
  lightC2(light,0,0);
  lightD2(light,0,0);
  lightE2(light,0,0);
}
