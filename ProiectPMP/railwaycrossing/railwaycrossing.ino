#include <Servo.h>

//DE RETINUT CA AICI ESTE DOAR UN PROTOTIP. SUNT PREA MULTE PROCESE CARE SE BLOCHEAZA INTRE ELE


int ledStanga = D0;


int ledDreapta = D1;


int ledAlb = D2;

Servo bariera1, bariera2, bariera3, bariera4;


const int hallPin1 = D5;
bool barrierStateSens = false;
//bool barrierStateContrasens = false;


//modificam codul pentru a face ca procesele sa poata sa foloseasca procese in paralel
int buzzer = D8;

void setup() {
  pinMode(ledStanga, OUTPUT);
  pinMode(ledAlb, OUTPUT);
  pinMode(ledDreapta, OUTPUT);  
  pinMode(hallPin1, INPUT_PULLUP);
  Serial.begin(74880);


  bariera1.attach(D6);
  //bariera3.attach(D7);
  //bariera2.attach(D3);
  //bariera4.attach(D4);

  
  bariera1.write(90);
  //bariera2.write(90);
  //bariera3.write(90);
  //bariera4.write(90);
}


void coboaraBarieraSens(){

  for (int unghi = 90; unghi >= 0; unghi--){
    bariera1.write(unghi);
   // bariera3.write(unghi);
    delay(10);
  }

  barrierStateSens = true;
}

void ridicaBarieraSens(){
  for (int unghi = 0; unghi <= 90; unghi++){
    bariera1.write(unghi);
  //  bariera3.write(unghi);
    delay(10);
  } 

  barrierStateSens = false;
}
/*
void coboaraBarieraContrasens(){
  for (int unghi = 90; unghi >= 0; unghi--){
    bariera2.write(unghi);
    bariera4.write(unghi);
    delay(10);
  }

  barrierStateContrasens = true;
}
*/
/*
void ridicaBarieraContrasens(){
  for (int unghi = 0; unghi <= 90; unghi++){
    bariera2.write(unghi);
    bariera4.write(unghi);
    delay(10);
  }

  barrierStateContrasens = false;
}
*/
void albIntermitent(){
  
  digitalWrite(ledAlb, HIGH); 
  delay(1000);
  digitalWrite(ledAlb, LOW); 
  delay(1000); 
}


void rosuIntermitent(){
  
  digitalWrite(ledStanga, HIGH);
  
  tone(buzzer, 100);
  delay(500);
  noTone(buzzer);
  digitalWrite(ledStanga, LOW);
  digitalWrite(ledDreapta, HIGH);
  tone(buzzer, 100);
  delay(500);
  digitalWrite(ledDreapta, LOW);
  noTone(buzzer);
  
  
}


void loop() {

   int valoare = digitalRead(hallPin1);
   Serial.println(valoare);
   if (valoare == HIGH){
    albIntermitent();
    if(barrierStateSens){
      ridicaBarieraSens();
      
    //  ridicaBarieraContrasens();
    }
   }
   else if(valoare == LOW){
    rosuIntermitent();
    
    if(!barrierStateSens){
      coboaraBarieraSens();
      
    //  coboaraBarieraContrasens();
    }
    
   }
}

  

