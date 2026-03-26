# RC

Components : **6 LEDS (4 reds and 2 whites)**, **one potentiometer**, **2 servos** and **one capacitor** (at 17.01.2026 update).
Tools : **Arduino IDE**

## RO 
Acest proiect propune proiectarea unui prototip de trecere la nivel cu calea ferata, folosindu-ma de **un potentiometru**, **LED-uri**, **2 servomotoare** si **un capacitor**. Acestea au fost lipite pe un placaj din poliuretan. 

Link (pentru a putea fi observata evolutia montajului): https://www.youtube.com/watch?v=bM316-picHM&list=PLA1ZSYjgQUrnU9FbLbrIvAognBKYMzcuv

Proiectul a fost realizat pentru laboratorul de la materia Proiectare cu Microprocesoare. Codul este scris pentru Arduino Uno, fiind compatibil cu acest tip de placa. Pentru a programa sistemul am folosit tool-ul **Arduino IDE**, codul fiind scris in **C++**. In acest proiect am folosit mai multe notiuni specifice domeniului electronicii (la partea de montaj am folosit un **capacitor**), dar si notiuni specifice sistemelor automatizate, precum un **automat cu stari finite** pentru **semafoare (LED-uri)**, unul pentru **bariere(servomotoare)**. Desigur am folosit si cronometre interioare ale AVR, marcate prin functia **millis()**, pentru a paraleliza codul. 

**Features:**
  
  - **Finit State Machines**
  - **Timer0 library**
  - **Servo.h library**

**Organigrama pentru FSM-uri**

**Schema Electrica**


<img width="626" height="397" alt="image" src="https://github.com/user-attachments/assets/b92ba507-c847-4997-8387-0ddd489f96c7" />

**Schema de montaj**


<img width="572" height="449" alt="image" src="https://github.com/user-attachments/assets/0fbad88a-040c-4d5a-b4f2-384074b13954" />


Proiectul este **scalabil**, putand fi adaugate mai multe functionalitati, precum un **buzzer** pentru a genera o alarma cand *trenul* se apropie, un **semafor de cale** care sa simuleze trecerea trenului, mai precis, trecerea sa fie actionata de acel semafor, etc.


## EN 

This project proposes the design of a train barrier prototype, **using a potentiometer**, **LEDs**, **2 servomotors** and **one capacitor**. These were attached to a **polyurethane board**.

Link : https://www.youtube.com/watch?v=bM316-picHM&list=PLA1ZSYjgQUrnU9FbLbrIvAognBKYMzcuv

**Features**

- **Finit State Machines**
- **Timer1.h library**
- **Servo.h library**

**State Diagrams**




**Electrical diagram**


<img width="626" height="397" alt="image" src="https://github.com/user-attachments/assets/f828d2cc-2ed5-477a-a4f5-7523addfef6c" />

**Assembly diagram**


<img width="616" height="450" alt="image" src="https://github.com/user-attachments/assets/d4e9f9cd-8a2a-4a0a-927e-2c91a51c01f3" />


