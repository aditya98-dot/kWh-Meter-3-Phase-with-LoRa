#include <SPI.h>
#include <LoRa.h>
#include <PZEM004Tv30.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 20, 4);

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
   String id = "101";
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

  lcd.setCursor(1,0);
  lcd.print("Perangkat ID : 101");
  lcd.setCursor(2,1);
  lcd.print("Mengirim Data ke");
  lcd.setCursor(3,2);
  lcd.print("Node Receiver");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Tegangan:");
  lcd.setCursor(1, 1);
  lcd.print("R:");
  lcd.print(vR/100, 1);
  lcd.print("V");
  lcd.setCursor(1, 2);
  lcd.print("S:");
  lcd.print(vS/100, 1);
  lcd.print("V");
  lcd.setCursor(1, 3);
  lcd.print("T:");
  lcd.print(vT/100, 1);
  lcd.print("V");
  delay(5000);
  lcd.clear();
   
  lcd.setCursor(0, 0);
  lcd.print("Arus:");
  lcd.setCursor(1, 1);
  lcd.print("R:");
  lcd.print(iR/100);
  lcd.print("A");
  lcd.setCursor(1, 2);
  lcd.print("S:");
  lcd.print(iS/100);
  lcd.print("A");
  lcd.setCursor(1, 3);
  lcd.print("T:");
  lcd.print(iT/100);
  lcd.print("A");
  delay(5000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Frekuensi:");
  lcd.setCursor(1, 1);
  lcd.print("R:");
  lcd.print(freqR/100);
  lcd.print("Hz");
  lcd.setCursor (1, 2);
  lcd.print("S:");
  lcd.print(freqS/100);
  lcd.print("Hz");
  lcd.setCursor(1, 3);
  lcd.print("T:");
  lcd.print(freqT/100);
  lcd.print("Hz");
  delay(5000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Faktor Daya:");
  lcd.setCursor(1, 1);
  lcd.print("R:");
  lcd.print(pfR/100);
  lcd.setCursor(1, 2);
  lcd.print("S:");
  lcd.print(pfS/100);
  lcd.setCursor(1, 3);
  lcd.print("T:");
  lcd.print(pfT/100);
  delay(5000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Daya Aktif:");
  lcd.setCursor(1, 1);
  lcd.print("R:");
  lcd.print(powerR/100, 1);
  lcd.print("W");
  lcd.setCursor(1, 2);
  lcd.print("S:");
  lcd.print(powerS/100, 1);
  lcd.print("W");
  lcd.setCursor(1, 3);
  lcd.print("T:");
  lcd.print(powerT/100, 1);
  lcd.print("W");
  delay(5000);
  lcd.clear();

  lcd.setCursor(2,1);
  lcd.print("Node Transmitter");
  delay(272000);
  lcd.clear();
}
