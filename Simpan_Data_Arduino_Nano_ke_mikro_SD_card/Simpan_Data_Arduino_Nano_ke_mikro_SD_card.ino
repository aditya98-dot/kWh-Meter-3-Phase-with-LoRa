#include <SPI.h>
#include <SD.h>
#include "DS3231_Simple.h"
DS3231_Simple Clock;
File myFile;
               
String dataIn;
String dt[17];
int i;
boolean parsing = false;

String data="";
void setup()
{
  Serial.begin(9600);
  SD.begin(10);
  Clock.begin();
  dataIn = ""; // parsing data

  Serial.println("Initializing SD card...");
  if (!SD.begin(10)) {
  Serial.println("initialization failed!");
  while (1);
  }
}

// parsing data
void olahData() {
  while (Serial.available() > 0) {
    char inChar = (char)Serial.read();
    dataIn += inChar;
    if (inChar == '\n') {
      parsing = true;
    }
  }

  if (parsing) {
    parsingData();
    parsing = false;
    dataIn = "";
  }
}


void parsingData() {
  int j = 0;

  //kirim data yang telah diterima sebelumnya lalu menampilkannya pada serial monitor
  Serial.print("data masuk : ");
  Serial.print(dataIn);
  Serial.print("\n");

  dt[j] = "";     //inisialisasi variabel, (reset isi variabel)

  //proses parsing data
  for (i = 1; i < dataIn.length(); i++) {
    //pengecekan tiap karakter dengan karakter (#) dan (,)
    if ((dataIn[i] == '#') || (dataIn[i] == ','))
    {
      //increment variabel j, digunakan untuk merubah index array penampung
      j++;
      dt[j] = "";     //inisialisasi variabel array dt[j]
    }
    else
    {

      dt[j] = dt[j] + dataIn[i];    //proses tampung data saat pengecekan karakter selesai.

    }
  }

    DateTime waktu;
    waktu = Clock.read();
    
    myFile = SD.open("smart.txt",FILE_WRITE);
    if(myFile) {

    myFile.print(waktu.Day);
    myFile.print("/");
    myFile.print(waktu.Month);
    myFile.print("/");
    myFile.print(waktu.Year);
    myFile.print(" ");
    myFile.print(waktu.Hour);
    myFile.print(":");
    myFile.print(waktu.Minute);
    myFile.print(":");
    myFile.print(waktu.Second);
    myFile.print(" Node ID:");
    myFile.println(dt[0].toInt());
    
    myFile.print("Fasa R");
    myFile.print(": ");
    myFile.print(dt[1].toFloat());
    myFile.print(" V, ");
    myFile.print(dt[2].toFloat());
    myFile.print(" A, ");
    myFile.print(dt[3].toFloat());
    myFile.print(" Hz, PF: ");
    myFile.print(dt[4].toFloat());
    myFile.print(" , ");
    myFile.print(dt[5].toFloat());
    myFile.print(" Watt");
    myFile.println(" ");

    myFile.print("Fasa S");
    myFile.print(": ");
    myFile.print(dt[6].toFloat());
    myFile.print(" V, ");
    myFile.print(dt[7].toFloat());
    myFile.print(" A, ");
    myFile.print(dt[8].toFloat());
    myFile.print(" Hz, PF: ");
    myFile.print(dt[9].toFloat());
    myFile.print(" , ");
    myFile.print(dt[10].toFloat());
    myFile.print(" Watt");
    myFile.println(" ");
    
    myFile.print("Fasa T");
    myFile.print(": ");
    myFile.print(dt[11].toFloat());
    myFile.print(" V, ");
    myFile.print(dt[12].toFloat());
    myFile.print(" A, ");
    myFile.print(dt[13].toFloat());
    myFile.print(" Hz, PF: ");
    myFile.print(dt[14].toFloat());
    myFile.print(" , ");
    myFile.print(dt[15].toFloat());
    myFile.print(" Watt");
    myFile.println(" ");
    myFile.print("Daya Total: ");
    myFile.print(dt[16].toFloat());
    myFile.print("Watt");
    myFile.println(" ");
    myFile.println("-----------------------------------------------------------------------------------------------------");
    myFile.print("\n");
    
    Serial.println("Data disimpan");
    myFile.close();
    }else{
    Serial.println("Error");
    }
}

void loop (){
  olahData();
}
