/*****************************************************************************
  Created by: Aditya Pratama. email: adityapratama141198@gmail.com. Oct 2021
  3 Phase kWh Meter Using LoRa Version 1.0
  This is open source code. Please include my name in copies of this code
  Thankyou ...
 *****************************************************************************/

#include <WebServer.h>
#include <WiFiClient.h>
#include <WiFi.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define ss 5
#define rst 14
#define dio0 2 

LiquidCrystal_I2C lcd(0x27, 16,2);  //LCD
int buz = 15;                       // Buzzer

//PZEM-004T
String dataIn, dt[16];
int perangkat_id;
int i;
boolean parsing = false;
float Vr, Ir, freqR, pfr, powerR, Vs, Is, freqS, pfs, powerS, Vt, It, freqT, pft, powerT, powerTotal;

// koneksi wifi
const char* ssid = "REPLACE WITH YOUR SSID";
const char* password = "REPLACE WITH YOUR PASSWORD";

//WiFiClient client;
char server [] = "152.195.416.242"; //This IP on your local computer
WiFiClient client;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  //LCD
  lcd.init();                   
  lcd.backlight();
  dataIn = ""; // parsing data
  while (!Serial);
  pinMode (buz,OUTPUT);
  
  //connect the LoRa
  LoRa.setPins(ss, rst, dio0);
  Serial.println("LoRa Receiver");
 
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa Failed!");
    lcd.setCursor(0, 0);
    lcd.print("Gagal Connect to");
    lcd.setCursor(0, 1);
    lcd.print("Node Receiver");
    while(1);
  } lcd.clear();
 
  // koneksi ke WiFi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    lcd.setCursor(0, 0);
    lcd.print("Cek Koneksi WiFi");
    digitalWrite(buz,HIGH);
    delay(500);
    digitalWrite(buz,LOW);
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  lcd.clear();

  // Start the server
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
  Serial.println("connecting...");
}

void parsingData(){
  int j = 0;
  //kirim data yang telah diterima sebelumnya lalu menampilkannya pada serial monitor dan LCD
  lcd.setCursor(0, 0);
  lcd.print("Data Masuk dari");
  lcd.setCursor(0, 1);
  lcd.print("Node Transmitter");
  delay(2000);
  lcd.clear();
  lcd.print("Mode Online");
  Serial.print("data masuk : " + dataIn);
  Serial.print("\n");

  dt[j] = "";     //inisialisasi variabel, (reset isi variabel)

  //proses parsing data
  for (i = 1; i < dataIn.length(); i++) {
    //pengecekan tiap karakter dengan karakter (#) dan (,)
    if ((dataIn[i] == '#') || (dataIn[i] == ',')){
      //increment variabel j, digunakan untuk merubah index array penampung
      j++;
      dt[j] = "";     //inisialisasi variabel array dt[j]
    } else {
      dt[j] = dt[j] + dataIn[i];    //proses tampung data saat pengecekan karakter selesai.
    }
  }

  // tampung data ke variabel
  perangkat_id += dt[0].toInt();
  Vr += dt[1].toInt() / 100.0;
  Ir += dt[2].toInt() / 100.0;
  freqR += dt[3].toInt() / 100.0;
  pfr += dt[4].toInt() / 100.0;
  powerR += dt[5].toInt() / 100.0;
  Vs += dt[6].toInt() / 100.0;
  Is += dt[7].toInt() / 100.0;
  freqS += dt[8].toInt() / 100.0;
  pfs += dt[9].toInt() / 100.0;
  powerS += dt[10].toInt() / 100.0;
  Vt += dt[11].toInt() / 100.0;
  It += dt[12].toInt() / 100.0;
  freqT += dt[13].toInt() / 100.0;
  pft += dt[14].toInt() / 100.0;
  powerT += dt[15].toInt() / 100.0;
  powerTotal = powerR + powerS + powerT;
}

void loop(){
// parsing data
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
  while (LoRa.available()>0) {
    char inChar = (char)LoRa.read();
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

 // Sending Data to phpmyadmin_database
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    // YOUR URL
    client.print("GET /listrik/db_listrik.php?perangkat_id="); client.print(perangkat_id);
    client.print("&tegangan_R="); client.print(Vr);
    client.print("&arus_R="); client.print(Ir);
    client.print("&frekuensi_R="); client.print(freqR);
    client.print("&PF_R="); client.print(pfr);
    client.print("&daya_R="); client.print(powerR);
    
    client.print("&tegangan_S="); client.print(Vs);
    client.print("&arus_S="); client.print(Is);
    client.print("&frekuensi_S="); client.print(freqS);
    client.print("&PF_S="); client.print(pfs);
    client.print("&daya_S="); client.print(powerS);
    
    client.print("&tegangan_T="); client.print(Vt);
    client.print("&arus_T="); client.print(It);
    client.print("&frekuensi_T="); client.print(freqT);
    client.print("&PF_T="); client.print(pft);
    client.print("&daya_T="); client.print(powerT);
    client.print("&daya_Total="); client.print(powerTotal);

    Serial.print("GET /listrik/db_listrik.php?perangkat_id="); Serial.println(perangkat_id);
    Serial.print("&tegangan_R="); Serial.println(Vr);
    Serial.print("&arus_R="); Serial.println(Ir);
    Serial.print("&frekuensi_R="); Serial.println(freqR);
    Serial.print("&PF_R="); Serial.println(pfr);
    Serial.print("&daya_R="); Serial.println(powerR);
    Serial.print("&tegangan_S="); Serial.println(Vs);
    Serial.print("&arus_S="); Serial.println(Is);
    Serial.print("&frekuensi_S="); Serial.println(freqS);
    Serial.print("&PF_S="); Serial.println(pfs);
    Serial.print("&daya_S="); Serial.println(powerS);
    Serial.print("&tegangan_T="); Serial.println(Vt);
    Serial.print("&arus_T="); Serial.println(It);
    Serial.print("&frekuensi_T="); Serial.println(freqT);
    Serial.print("&PF_T="); Serial.println(pft);
    Serial.print("&daya_T="); Serial.println(powerT);
    Serial.print("&daya_Total="); Serial.println(powerTotal);
    
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 152.195.416.242"); // Hostname
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("koneksi gagal!, cek dulu servernya");
    Serial.print("Connecting to ");
    Serial.println(ssid);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
       // delay(500);
        Serial.print(".");
        digitalWrite(buz,HIGH);
        delay(200);
        digitalWrite(buz,LOW);
        delay (800);
        digitalWrite(buz,HIGH);
        delay(200);
        digitalWrite(buz,LOW);
        delay(800);
        
        Serial.println ("Send data to mikro SD card");
        Sending_to_Arduino_Nano();
        lcd.setCursor(0, 0);
        lcd.print("Mengirim Data ke");
        lcd.setCursor(0, 1);
        lcd.print("Mikro SD card");
        delay(2000);
        lcd.clear();
        lcd.print("Mode Offline");     
        delay(296000);  
      }
      lcd.clear();
      Serial.println("");
      Serial.println("WiFi connected");
    }
   setData(); 
  }
}

void setData(){
  perangkat_id = 0;
  Vr = 0;
  Ir = 0;
  freqR = 0;
  pfr = 0;
  powerR = 0;
  Vs = 0;
  Is = 0;
  freqS = 0;
  pfs = 0;
  powerS = 0;  
  Vt = 0;
  It = 0;
  freqT = 0;
  pft = 0;
  powerT = 0;
  powerTotal = 0;
}

void Sending_to_Arduino_Nano(){
  String str2 = "*" + String(perangkat_id) + "," +  String(Vr) + "," + String(Ir) + "," + String(freqR) + "," + String(pfr) + "," + String(powerR) + "," + String(Vs) + "," + String(Is) + "," + String(freqS)+ "," + String(pfs) + "," + String(powerS) + "," + String(Vt)  + "," + String(It) + "," + String(freqT) + "," + String(pft) + "," + String(powerT) + "," + String(powerTotal) + '#';
  Serial.println(str2);
  Serial2.println(str2);
}
