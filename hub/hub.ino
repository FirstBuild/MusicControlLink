#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "common.h"

RF24 radio(7, 8); // CE, CSN

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  radio.begin();
  Serial.println("Configuring master");
  for (int i=0; i<addressCount; i++) {
    radio.openReadingPipe(i+1, &address[i].rx[0]);
    Serial.print("Listening on ");
    Serial.println((char *)&address[i].rx[0]);
  }
  Serial.println("Master configuration complete.");
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  uint8_t pn;
  if (radio.available(&pn)) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.print(pn);
    Serial.print(":");
    Serial.println(text);
  }
}
