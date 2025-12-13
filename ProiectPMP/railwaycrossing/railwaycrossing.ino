#include <Servo.h>

//DE RETINUT CA AICI ESTE DOAR UN PROTOTIP. SUNT PREA MULTE PROCESE CARE SE BLOCHEAZA INTRE ELE


// int ledStanga = D0;


// int ledDreapta = D1;


// int ledAlb = D2;

// Servo bariera1, bariera2, bariera3, bariera4;


// const int hallPin1 = D5;
// bool barrierStateSens = false;
// //bool barrierStateContrasens = false;


// //modificam codul pentru a face ca procesele sa poata sa foloseasca procese in paralel
// int buzzer = D8;

// void setup() {
//   pinMode(ledStanga, OUTPUT);
//   pinMode(ledAlb, OUTPUT);
//   pinMode(ledDreapta, OUTPUT);  
//   pinMode(hallPin1, INPUT_PULLUP);
//   Serial.begin(74880);


//   bariera1.attach(D6);
//   //bariera3.attach(D7);
//   //bariera2.attach(D3);
//   //bariera4.attach(D4);

  
//   bariera1.write(90);
//   //bariera2.write(90);
//   //bariera3.write(90);
//   //bariera4.write(90);
// }


// void coboaraBarieraSens(){

//   for (int unghi = 90; unghi >= 0; unghi--){
//     bariera1.write(unghi);
//    // bariera3.write(unghi);
//     delay(10);
//   }

//   barrierStateSens = true;
// }

// void ridicaBarieraSens(){
//   for (int unghi = 0; unghi <= 90; unghi++){
//     bariera1.write(unghi);
//   //  bariera3.write(unghi);
//     delay(10);
//   } 

//   barrierStateSens = false;
// }
// /*
// void coboaraBarieraContrasens(){
//   for (int unghi = 90; unghi >= 0; unghi--){
//     bariera2.write(unghi);
//     bariera4.write(unghi);
//     delay(10);
//   }

//   barrierStateContrasens = true;
// }
// */
// /*
// void ridicaBarieraContrasens(){
//   for (int unghi = 0; unghi <= 90; unghi++){
//     bariera2.write(unghi);
//     bariera4.write(unghi);
//     delay(10);
//   }

//   barrierStateContrasens = false;
// }
// */
// void albIntermitent(){
  
//   digitalWrite(ledAlb, HIGH); 
//   delay(1000);
//   digitalWrite(ledAlb, LOW); 
//   delay(1000); 
// }


// void rosuIntermitent(){
  
//   digitalWrite(ledStanga, HIGH);
  
//   tone(buzzer, 100);
//   delay(500);
//   noTone(buzzer);
//   digitalWrite(ledStanga, LOW);
//   digitalWrite(ledDreapta, HIGH);
//   tone(buzzer, 100);
//   delay(500);
//   digitalWrite(ledDreapta, LOW);
//   noTone(buzzer);
  
  
// }


// void loop() {

//    int valoare = digitalRead(hallPin1);
//    Serial.println(valoare);
//    if (valoare == HIGH){
//     albIntermitent();
//     if(barrierStateSens){
//       ridicaBarieraSens();
      
//     //  ridicaBarieraContrasens();
//     }
//    }
//    else if(valoare == LOW){
//     rosuIntermitent();
    
//     if(!barrierStateSens){
//       coboaraBarieraSens();
      
//     //  coboaraBarieraContrasens();
//     }
    
//    }
// }

const int leduriStanga = D0;
const int leduriDreapta = D1;
const int leduriAlbe = D2;

const int senzorSemafor = D5;
const int senzorBariera = D7;
const int buzzer = D8;

bool barrierState = false;
bool stareAlb = false;
bool stareRosu = false;


unsigned int previousMillisAlb = 0;
unsigned int previousMillisRosu = 0;
unsigned int previousMillisBarieraSens = 0;
unsigned int previousMillisBarieraContrasens = 0;
unsigned int previousDebounceSemafor = 0;

unsigned int frecventaAlb = 500;
unsigned int frecventaRosu = 300;
unsigned int frecventaBariera = 20;
unsigned int frecventaDebounce = 80;


int stableStateSemafor = HIGH;
int lastReadingSemafor = HIGH;

Servo bariera;

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

  pinMode(senzorSemafor, INPUT_PULLUP);

  
  bariera.attach(D6);
  bariera.write(90);
}



void loop(){
  unsigned int currentMillis = millis();

  //adaugat logica debounce pentru senzorul hall

  int citireBrutaSemafor = digitalRead(senzorSemafor);
  
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
  
  int valoareBariera = digitalRead(senzorBariera);

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
        tone(buzzer, 100); 
      }
      else {
        digitalWrite(leduriStanga, LOW);
        digitalWrite(leduriDreapta, HIGH);
        noTone(buzzer);
      }
    }
  }

   

  //coborarea barierelor se va face cu un senzor infrarosu

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

  //senzor care ajuta la ridicarea barierelor si la oprirea semaforului dupa ce trece trenul(tot Hall cel mai probabil)
  



}






  

