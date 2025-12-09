




int ledStanga1 = D0;
int ledDreapta1 = D1;


int ledAlb1 = D2;




const int hallPin1 = D5;


int buzzer = D8;

void setup() {
  pinMode(ledStanga1, OUTPUT);
  pinMode(ledAlb1, OUTPUT);
  pinMode(ledDreapta1, OUTPUT);  
  pinMode(hallPin1, INPUT_PULLUP);
  Serial.begin(74880);
}

void albIntermitent(){
  delay(1000);
  digitalWrite(ledAlb1, HIGH);
  delay(1000);
  digitalWrite(ledAlb1, LOW);
  
}


void rosuIntermitent(){
  
  digitalWrite(ledStanga1, HIGH);
  tone(buzzer, 100);
  delay(1000);
  noTone(buzzer);
  digitalWrite(ledStanga1, LOW);
  digitalWrite(ledDreapta1, HIGH);
  tone(buzzer, 100);
  delay(1000);
  digitalWrite(ledDreapta1, LOW);
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

  

