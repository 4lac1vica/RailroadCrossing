#include <Servo.h>

#define STEP 10

enum StariSemafor{
  MOD_ROSU,
  MOD_ALB
};

enum StariBariera{
  COBORAT,
  COBORARE,
  RIDICARE,
  RIDICAT
};




const int ledAlb = 2;
const int ledRosuStanga = 3;
const int ledRosuDreapta = 4;
unsigned long previousAlb = 0;
unsigned long previousRosu = 0;
unsigned long previousTest = 0;
unsigned long previousBariera = 0;
unsigned long frecventaBariera = 20;
const unsigned long frecventa = 1000;
const unsigned long frecventaTest = 10000;
bool stareAlb;
bool stareRosu;
bool test;
StariSemafor stareSemafor;
StariBariera stareBariera;
int valoarePotentiometru;
Servo bariera1;
Servo bariera2;
Servo bariera3;
Servo bariera4;


int unghiBariera = 90;
const int unghiSus = 90;
const int unghiJos = 0;




void setup(){
  pinMode(ledAlb, OUTPUT);
  pinMode(ledRosuStanga, OUTPUT);
  pinMode(ledRosuDreapta, OUTPUT);


  bariera1.attach(9);
  bariera2.attach(10);
  bariera3.attach(11);
  bariera4.attach(12);
  bariera1.write(unghiSus);
  bariera2.write(unghiSus);
  bariera3.write(unghiSus);
  bariera4.write(unghiSus);
  stareAlb = false;
  stareRosu = false;
  test = false;
  

  stareSemafor = MOD_ROSU;
  stareBariera = RIDICAT;

  
}

void readInputs(){
  valoarePotentiometru = analogRead(A0);
}


void functieAlb(){

  
  unsigned long current = millis();
  digitalWrite(ledRosuStanga,  LOW);
  digitalWrite(ledRosuDreapta, LOW);
  if (current - previousAlb >= frecventa){
    previousAlb = current;
    stareAlb = !stareAlb;
    digitalWrite(ledAlb, stareAlb);
    
  }
}

void functieRosu(){
  unsigned long current = millis();
  digitalWrite(ledAlb, LOW);
  if (current - previousRosu >= frecventa){
    previousRosu = current;
    stareRosu = !stareRosu;
    digitalWrite(ledRosuStanga, stareRosu);
    digitalWrite(ledRosuDreapta, !stareRosu);
  }

}

void controlBariera(){
  unsigned long current = millis();

  if (current - previousBariera >= frecventaBariera){
    previousBariera = current;
    
   if (stareBariera == COBORARE){
    if (unghiBariera > unghiJos){
      unghiBariera--;
      bariera1.write(unghiBariera);
    }
    else {
      stareBariera = COBORAT;
    }
   }
   if (stareBariera == RIDICARE){
    if (unghiBariera < unghiSus){
      unghiBariera++;
      bariera1.write(unghiBariera);
    }
    else {
      stareBariera = RIDICAT;
    }
   }
  }
}



void modifyOutputs(){
  switch(stareSemafor){
    case MOD_ALB:
      functieAlb();
      break;
    case MOD_ROSU:
      functieRosu();
      break;
    default:
      break;
  }
}

void loop(){

  //modifyOutputs();
  //functieRosu();
  unsigned long currentTest = millis();

  if (currentTest - previousTest >= frecventaTest){
  previousTest = currentTest;
  test = !test;
  stareSemafor = test ? MOD_ALB : MOD_ROSU;

  
  previousAlb = currentTest;
  previousRosu = currentTest;
  stareAlb = false;
  stareRosu = false;
}

  if (stareSemafor == MOD_ROSU && stareBariera == RIDICAT) {
   stareBariera = COBORARE;
}

  if (stareSemafor == MOD_ALB && stareBariera == COBORAT) {
    stareBariera = RIDICARE;
}


controlBariera();
modifyOutputs();

  

}