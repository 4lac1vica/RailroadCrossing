//cod refacut complet 

enum StariSemafor{
  MOD_ROSU,
  MOD_ALB
};


const int ledAlb = 2;
const int ledRosuStanga = 3;
const int ledRosuDreapta = 4;
unsigned long previousAlb = 0;
unsigned long previousRosu = 0;
unsigned long previousTest = 0;
const unsigned long frecventa = 1000;
const unsigned long frecventaTest = 10000;
bool stareAlb;
bool stareRosu;
bool test;
StariSemafor stareSemafor;


void setup(){
  pinMode(ledAlb, OUTPUT);
  pinMode(ledRosuStanga, OUTPUT);
  pinMode(ledRosuDreapta, OUTPUT);

  stareAlb = false;
  stareRosu = false;
  test = false;
  stareSemafor = MOD_ROSU;
}



void functieAlb(){

  
  unsigned long current = millis();

  if (current - previousAlb >= frecventa){
    previousAlb = current;
    stareAlb = !stareAlb;
    digitalWrite(ledAlb, stareAlb);
    
  }
}

void functieRosu(){
  unsigned long current = millis();
  
  if (current - previousRosu >= frecventa){
    previousRosu = current;
    stareRosu = !stareRosu;
    digitalWrite(ledRosuStanga, stareRosu);
    digitalWrite(ledRosuDreapta, !stareRosu);
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


  digitalWrite(ledAlb, LOW);
  digitalWrite(ledRosuStanga, LOW);
  digitalWrite(ledRosuDreapta, LOW);
  stareAlb = false;
  stareRosu = false;
}

modifyOutputs();

  

}

