#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "common.h"

uint8_t slaveNum;

RF24 radio(7, 8); // CE, CSN

uint8_t getSlaveNum(void) {
  uint8_t num = 0;
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);

  delay(50);

  num |= digitalRead(2) == HIGH ? 0x01 : 0x00;
  num |= digitalRead(3) == HIGH ? 0x02 : 0x00;
  num |= digitalRead(4) == HIGH ? 0x04 : 0x00;

  num = (~num) & 0x07;
  return num;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  radio.begin();
  Serial.println("Configuring slave");
  slaveNum = getSlaveNum();
  Serial.print("Slave number: ");
  Serial.println(slaveNum);
  if (slaveNum >= addressCount) {
    Serial.print("The slave address is out of range: ");
    Serial.println(slaveNum);
    Serial.print("Setting the slave address to ");
    slaveNum = addressCount - 1;
    Serial.print(slaveNum);
  }
  Serial.print("Slave TX address: ");
  Serial.println((const char *)&address[slaveNum].tx[0]);
  Serial.print("Slave RX address: ");
  Serial.println((const char *)&address[slaveNum].rx[0]);
  radio.openReadingPipe(1, &address[slaveNum].rx[0]);
  radio.openWritingPipe(address[slaveNum].tx);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Printing...");
  const char text[] = "Hello World " ;
  radio.write(&text, sizeof(text));
  delay(1000);
}
