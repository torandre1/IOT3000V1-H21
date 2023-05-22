/*  Kode hentet fra:
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
* by Dejan Nedelkovski, www.HowToMechatronics.com
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*
* Koden er modifisert av oss i forbindelse med eksamen i emnet 
* IOT3000, H2021, ved USN Vestfold.
* 
* Programkommentar: Oppsettet består av en Arduino, RF24 og Moisture-sensor.
* Data som blir avlest sendes videre til annet RF24-komponent som er programmert 
* til å fungere som receiver. 
*
*/

/* Bibliotek-import */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/* Pins og kommunikasjonsadresse */
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
//int pot = A0;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
}
void loop() {
  int value;
  value = analogRead(A0);
  Serial.println("Sending sensor value:");  // Driftsmelding
  radio.write(&value, sizeof(value));       // Skriver/sender data
  Serial.println(value);                    // Driftsmelding
  delay(1000);
}
