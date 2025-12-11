#include <Servo.h>




int ledStanga = D0;


int ledDreapta = D1;


int ledAlb = D2;

Servo bariera1;


const int hallPin1 = D5;
bool barrierState = false;

int buzzer = D8;

void setup() {
  pinMode(ledStanga, OUTPUT);
  pinMode(ledAlb, OUTPUT);
  pinMode(ledDreapta, OUTPUT);  
  pinMode(hallPin1, INPUT_PULLUP);
  Serial.begin(74880);


  bariera1.attach(D6);
  bariera1.write(90);
}


void coboaraBariera(){

  for (int unghi = 90; unghi >= 0; unghi--){
    bariera1.write(unghi);
    delay(10);
  }

  barrierState = true;
}

void ridicaBariera(){
  for (int unghi = 0; unghi <= 90; unghi++){
    bariera1.write(unghi);
    delay(10);
  } 

  barrierState = false;
}


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
    if(barrierState){
      ridicaBariera();
    }
   }
   else if(valoare == LOW){
    rosuIntermitent();
    
    if(!barrierState){
      coboaraBariera();
    }
    
   }
}

  

