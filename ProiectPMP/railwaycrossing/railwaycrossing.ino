




int ledStanga = D0;


int ledDreapta = D1;


int ledAlb = D2;




const int hallPin1 = D5;


int buzzer = D8;

void setup() {
  pinMode(ledStanga, OUTPUT);
  pinMode(ledAlb, OUTPUT);
  pinMode(ledDreapta, OUTPUT);  
  pinMode(hallPin1, INPUT_PULLUP);
  Serial.begin(74880);
}

void albIntermitent(){
  delay(1000);
  digitalWrite(ledAlb, HIGH); 
  delay(1000);
  digitalWrite(ledAlb, LOW);
  
}


void rosuIntermitent(){
  
  digitalWrite(ledStanga, HIGH);
  
  tone(buzzer, 100);
  delay(1000);
  noTone(buzzer);
  digitalWrite(ledStanga, LOW);
  digitalWrite(ledDreapta, HIGH);
  tone(buzzer, 100);
  delay(1000);
  digitalWrite(ledDreapta, LOW);
  noTone(buzzer);
  
  
}


void loop() {

   int valoare = digitalRead(hallPin1);
   Serial.println(valoare);
   if (valoare == HIGH){
    albIntermitent();
   }
   else if(valoare == LOW){
    rosuIntermitent();
   }
    
}

  

