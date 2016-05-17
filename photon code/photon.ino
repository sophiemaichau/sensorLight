#include "StopWatch/StopWatch.h"

StopWatch MySW;
StopWatch OffWall;

const int lys = 2;
const int lys2 = 3;
const int lys3 = 4;

const int knappin = 5;
const int knappin2 = 6;
const int knappin3 = 7;

int count = 0;
int jumpDist = 3000;

int reading, lastReading;

boolean flag = false;
boolean flag2 = false;
boolean flag3 = false;
boolean partVar = false;

int timeOnWall = 0;
int finalCount = 0;

long inAir;

bool success;

void setup() {
  Serial.begin(9600);
  
  pinMode(lys, OUTPUT);
  pinMode(knappin, INPUT_PULLUP);

  pinMode(lys2, OUTPUT);
  pinMode(knappin2, INPUT_PULLUP);

  pinMode(lys3, OUTPUT);
  pinMode(knappin3, INPUT_PULLUP);
  
  Particle.variable("tid",timeOnWall);
  Particle.variable("greb",finalCount);
  Particle.variable("success",success);
  
}

void displayResult(){
  success = true;
  timeOnWall = MySW.elapsed() - jumpDist;
  Serial.print(timeOnWall);
  finalCount = count;
  Serial.println(finalCount);
  MySW.reset();
  OffWall.reset();
  delay(10000);
  success = false;
}

void loop() {
    inAir = OffWall.elapsed();
  // trykker på knap
  if(!digitalRead(knappin)){
        digitalWrite(lys, HIGH);
        if(flag==false){
          count++;
          flag = true;
          Serial.print("\nAntal greb: ");
          Serial.print(count);
          MySW.start();

          Serial.print("\nI luften: ");
          Serial.print(inAir);
          OffWall.reset();
        }
  }
        
  if(!digitalRead(knappin2)){
        digitalWrite(lys2, HIGH);
        if(flag2==false){
          count++;
          flag2 = true;
          Serial.print("\nAntal greb: ");
          Serial.print(count);
           MySW.start();

           Serial.print("\nI luften: ");
           Serial.print(inAir);
           OffWall.reset();
        }
  }

  if(!digitalRead(knappin3)){
        digitalWrite(lys3, HIGH);
        if(flag3==false){
          count++;
          flag3 = true;
          Serial.print("\nAntal greb: ");
          Serial.print(count);
           MySW.start();

           Serial.print("\nI luften: ");
           Serial.print(inAir);
           OffWall.reset();
        }
  }

  if(flag==true){
    digitalWrite(lys, HIGH);
  }
  if(flag2==true){
    digitalWrite(lys2, HIGH);
  }
  if(flag3==true){
    digitalWrite(lys3, HIGH);
  }
  //////

  
  // faldet af væggen
  if(digitalRead(knappin) && digitalRead(knappin2)
  && digitalRead(knappin3) && (count >= 1)){
    
      OffWall.start();

      if(inAir > jumpDist){
      displayResult();
      flag=false;
      flag2=false;
      flag3=false;
      digitalWrite(lys, LOW);
      digitalWrite(lys2, LOW);
      digitalWrite(lys3, LOW);
      count=0;
    }
  }
}
