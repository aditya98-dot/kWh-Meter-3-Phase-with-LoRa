#include "DS3231_Simple.h"
DS3231_Simple Clock;

void setup() {
  Serial.begin(9600);
  Clock.begin();
}

void loop() { 
  DateTime waktu;
  waktu.Day    = 03;       //atur tanggal
  waktu.Month  = 6;      //atur bulan
  waktu.Year   = 22;      //atur tahun
  waktu.Hour   = 20;      //atur jam
  waktu.Minute = 12;      //atur menit
  waktu.Second = 00;      //atur detik
  Clock.write(waktu);
  
  Serial.print("Waktu telah di atur ke: ");
  Clock.printTo(Serial);
  Serial.println();
  
  Serial.print("Program berakhir (RESET untuk menjalakan lagi)");
  while(1);
}
