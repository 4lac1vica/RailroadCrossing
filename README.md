# RC

Components : **6 LEDS (4 reds and 2 whites)**, **one potentiometer**, **2 servos** and **one capacitor** (at 17.01.2026 update).
Tools : **Arduino IDE**

## RO 
Acest proiect propune proiectarea unui prototip de trecere la nivel cu calea ferata, folosindu-ma de un potentiometru, LED-uri si 2 servomotoare si un capacitor. Acestea au fost lipite pe un placaj din poliuretan. 
Link (pentru a putea fi observata evolutia montajului): https://www.youtube.com/watch?v=bM316-picHM&list=PLA1ZSYjgQUrnU9FbLbrIvAognBKYMzcuv

Proiectul a fost realizat pentru laboratorul de la materia Proiectare cu Microprocesoare. Codul este scris pentru Arduino Uno, fiind compatibil cu acest tip de placa. Pentru a programa sistemul am folosit tool-ul **Arduino IDE**, codul fiind scris in **C++**. In acest proiect am folosit mai multe notiuni specifice domneniului electronicii (la partea de montaj am folosit un **capacitor**), dar si notiuni specifice sistemelor automatizate, precum un **automat cu stari finite** pentru **semafoare (LED-uri)**, unul pentru **bariere(servomotoare)**. Desigur am folosit si cronometre interioare ale AVR, marcate prin functia **millis()**, pentru a paraleliza codul. 

**Features:**
  
  - **Finit State Machines**
  - **Timer0 library**
  - **Servo.h library**

**Organigrama pentru FSM-uri**

**Schema Electrica**

**Schema modulelor**


## EN 

This project proposes the design of a train barrier prototype, **using a potentiometer**, **LEDs**, **2 servomotors** and **one capacitor**. These were attached to a **polyurethane board**.
Link : https://www.youtube.com/watch?v=bM316-picHM&list=PLA1ZSYjgQUrnU9FbLbrIvAognBKYMzcuv


