/*****************************************************************************
  Created by: Aditya Pratama. email: adityapratama141198@gmail.com. Oct 2021
  3 Phase kWh Meter Using LoRa Version 1.0
  This is open source code. Please include my name in copies of this code
  Thankyou ...
 *****************************************************************************/

#include <SPI.h>
#include <LoRa.h>
#include <PZEM004Tv30.h>

PZEM004Tv30 pzem_r(2, 3);
PZEM004Tv30 pzem_s(4, 5);
PZEM004Tv30 pzem_t(6, 7);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  while (!Serial);
  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

//  Unkomen jika ingin mereset energi pada PZEM004Tv3.0
//  Serial.println("Reset Energy");
//  pzem_r.resetEnergy();
//  pzem_s.resetEnergy();
//  pzem_t.resetEnergy();

}

void loop() {
   String id = "102";
   float vR = pzem_r.voltage() * 100;
   float iR = pzem_r.current() * 100;
   float freqR = pzem_r.frequency() * 100;
   float pfR = pzem_r.pf() * 100;
   float powerR = pzem_r.power() * 100;

   float vS = pzem_s.voltage()* 100;
   float iS = pzem_s.current()* 100;
   float freqS = pzem_s.frequency() * 100;
   float pfS = pzem_s.pf()* 100;
   float powerS = pzem_s.power() * 100;
    
   float vT = pzem_t.voltage()* 100;
   float iT = pzem_t.current()* 100;
   float freqT = pzem_t.frequency() * 100;
   float pfT = pzem_t.pf()* 100;
   float powerT = pzem_t.power() * 100;

   String str = "*" + id + "," + String(vR) + "," + String(iR) + "," + String(freqR) + "," + String(pfR) + "," + String(powerR) + "," + String(vS) + "," + String(iS) + "," + String(freqS)+ "," + String(pfS) + "," + String(powerS) + "," + String(vT)  + "," + String(iT) + "," + String(freqT) + "," + String(pfT) + "," + String(powerT) +'#';
   Serial.println(str);

  // send packet
  Serial.println("Sending Packet....");
  LoRa.beginPacket();
  LoRa.println(str);
  LoRa.endPacket();
  delay(310000);
}
