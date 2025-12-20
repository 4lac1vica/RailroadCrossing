#include <Servo.h>

//Proiect PMP Todi Tinu-Constantin grupa 30237 

//de adaugat failsafe in caz ca bariera nu functioneaza. Buton + Intrerupere.

const int leduriStanga = 2;
const int leduriDreapta = 3;
const int leduriAlbe = 4;



const int senzorSemafor1 = 5;
const int senzorSemafor2 = 6;
const int buzzer = 8;

bool stareAlb = false;
bool stareRosu = false;



unsigned long  previousMillisAlb = 0;
unsigned long previousMillisRosu = 0;
unsigned long previousMillisBarieraSens = 0;
unsigned long previousMillisBarieraContrasens = 0;
unsigned long previousDebounceSemafor = 0;

const unsigned long frecventaAlb = 500;
const unsigned long frecventaRosu = 300;
const unsigned long frecventaBariera = 20;
const unsigned  frecventaDebounce = 80;


int stableStateSemafor = HIGH;
int lastReadingSemafor = HIGH;

//Servo bariera;

int pozitieBariera = 90;

// am creat fsm pentru semafoare si bariere!


enum modSemafor {
  MOD_ALB,
  MOD_ROSU
};

enum modBarieraSens {
  MOD_RIDICAT,
  MOD_COBORARE,
  MOD_JOS,
  MOD_RIDICARE
};


modSemafor semafor = MOD_ALB;
modBarieraSens barieraSens = MOD_RIDICAT;

void setup(){
  pinMode(leduriStanga, OUTPUT);
  pinMode(leduriDreapta, OUTPUT);
  pinMode(leduriAlbe, OUTPUT);

  pinMode(senzorSemafor2, INPUT_PULLUP);


 // bariera.attach(7);
 // bariera.write(90);
}

//incercam modularizare(citire inputuri - procesarea datelor - update outputs)


void readInputs(){
  

}

void processData(){

}

void updateOutputs(){

}



void loop(){
  unsigned long currentMillis = millis();

  //adaugat logica debounce pentru senzorul hall

  int citireBrutaSemafor = digitalRead(senzorSemafor2);
  
  if (citireBrutaSemafor != lastReadingSemafor){
    previousDebounceSemafor = currentMillis;

  }

  if ((currentMillis - previousDebounceSemafor) >= frecventaDebounce){
    if (citireBrutaSemafor != stableStateSemafor){
      stableStateSemafor = citireBrutaSemafor;
    }
  }
  
  lastReadingSemafor = citireBrutaSemafor;
  int valoareSemafor = stableStateSemafor;
  
 // int valoareBariera = digitalRead(senzorBariera);

  if (valoareSemafor == HIGH){ 
    semafor = MOD_ALB;
    digitalWrite(leduriStanga, LOW);
    digitalWrite(leduriDreapta, LOW);
    noTone(buzzer);
    //asta inseamna ca nu vine nici un tren, la senzori hall 1 inseamna ca nu detecteaza nimic, iar 0 inseamna ca detecteaza ceva
    if (currentMillis - previousMillisAlb >= frecventaAlb){
      previousMillisAlb = currentMillis;      //odata la 500 de milisecunde este schimbata starea din aprins in stins si viceversa
      stareAlb = !stareAlb;
      digitalWrite(leduriAlbe, stareAlb);
    }
  } 
  else if (valoareSemafor == LOW){           
    
    //analog leduri rosii
    
    digitalWrite(leduriAlbe, LOW);
    semafor = MOD_ROSU;
    if (currentMillis - previousMillisRosu >= frecventaRosu){
      previousMillisRosu = currentMillis;
      stareRosu = !stareRosu;

      if (stareRosu){
        digitalWrite(leduriStanga, HIGH);
        digitalWrite(leduriDreapta, LOW);
        tone(buzzer, 1000, 200); 
      }
      else {
        digitalWrite(leduriStanga, LOW);
        digitalWrite(leduriDreapta, HIGH);
        noTone(buzzer);
      }
    }
  }

   
/*
  

  if (currentMillis - previousMillisBarieraSens >= frecventaBariera){
    
    previousMillisBarieraSens = currentMillis;
    
    switch(barieraSens){
      case MOD_COBORARE:
        pozitieBariera--;
        bariera.write(pozitieBariera);
        if (pozitieBariera <= 0){
          barieraSens = MOD_JOS;
        }
        break;
      case MOD_RIDICARE:
        pozitieBariera++;
        bariera.write(pozitieBariera);
        if (pozitieBariera >= 90){
          barieraSens = MOD_RIDICAT;
        }
        break;
    }
  }
*/
  //senzor care ajuta la ridicarea barierelor si la oprirea semaforului dupa ce trece trenul(tot Hall cel mai probabil)
  



}






  

