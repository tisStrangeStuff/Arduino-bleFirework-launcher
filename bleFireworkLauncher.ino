//Bluetooth firework launcher code
char inSerial[15];
const long  heatTime = 5000;
const byte MOSFET_1 = 5;
const byte MOSFET_2 = 4;
const byte MOSFET_3 = 3;
const byte rx = 0;
unsigned long currentTime;
long waitTime1;
long waitTime2;
long waitTime3;
void setup() {

  Serial.begin(9600);
  pinMode(rx, INPUT);
  pinMode(MOSFET_1, OUTPUT);
  pinMode(MOSFET_2, OUTPUT);
  pinMode(MOSFET_3, OUTPUT);
  allPinsLow();
}
void loop() {
  currentTime = millis();
  int i = 0;
  int m = 0;

  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      inSerial[i] = Serial.read();
      i++;
    }
    inSerial[i] = '\0';
    CoilCheck(inSerial);
  }

  //Heats the coils for 5 seconds

  while (waitTime3 > currentTime) {
    //turns on mosfet 3
    digitalWrite(MOSFET_3, HIGH);

  }


  while (waitTime2 > currentTime) {
    //tunrs on mosfet 2
    digitalWrite(MOSFET_2, HIGH);

  }

  while (waitTime1 > currentTime) {
    //turns on mosfet 1
    digitalWrite(MOSFET_1, HIGH);

  }
  //shuts off the mosfets, pretty messy but it works.

  if (waitTime1 == currentTime) {
    //shuts off mosfet 1
    digitalWrite(MOSFET_1, LOW);
    Serial.println("Heated 1");
  }

  if (waitTime2 == currentTime) {
    //shuts off mosfet 2
    digitalWrite(MOSFET_2, LOW);
    Serial.println("Heated 2");
  }

  if (waitTime3 == currentTime) {
    //shuts off mosfet 3
    digitalWrite(MOSFET_2, LOW);
    Serial.println("Heated 3");
  }
}

// writes all pins low
void allPinsLow() {

  digitalWrite(MOSFET_1, LOW);
  digitalWrite(MOSFET_2, LOW);
  digitalWrite(MOSFET_3, LOW);

}

void CoilCheck(char inStr[]) {    //compares recived data to firing commands

  //fires 1
  if (strcmp(inStr, "fire1") == 0) {

    waitTime1 = currentTime + heatTime;
    Serial.println("Firing 1");

    for (int m = 0; m < sizeof(inStr); m++) {

      inStr[m] = 0;

    }
  }
  //fires 2
  if (strcmp(inStr, "fire2") == 0) {

    waitTime2 = currentTime + heatTime;
    Serial.println("Firing 2");
    for (int m = 0; m < sizeof(inStr); m++) {

      inStr[m] = 0;

    }
  }
  //fires 3
  if (strcmp(inStr, "fire3") == 0) {

    waitTime3 = currentTime + heatTime;
    Serial.println("Firing 3");
    for (int m = 0; m < sizeof(inStr); m++) {

      inStr[m] = 0;

    }
  }
}
