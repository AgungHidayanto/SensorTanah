/*
  Make sure your Firebase project's '.read' and '.write' rules are set to 'true'. 
  Ignoring this will prevent the MCU from communicating with the database. 
  For more details- https://github.com/Rupakpoddar/ESP8266Firebase 
*/

#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>


// Konfigurasi WiFi
#define _SSID "Hidayanto"
#define _PASSWORD "agung123"

// Konfigurasi Firebase
#define REFERENCE_URL "https://esp8266-790f0-default-rtdb.asia-southeast1.firebasedatabase.app/"
Firebase firebase(REFERENCE_URL);

int value;
unsigned long previousMillis = 0;  // Waktu terakhir kali data dikirim
const long interval = 100L;        // Interval waktu (dalam milidetik)

void sendSensor() {
  value = analogRead(A0);
  value = map(value, 400, 1023, 100, 0);
  
  // Kirim data ke Firebase
  firebase.setInt("sensor/kelembapan_tanah", value);
  
  Serial.print("Soil Moisture : ");
  Serial.println(value);
}

void setup() {
  Serial.begin(115200);

  // Mulai koneksi ke WiFi
  WiFi.begin(_SSID, _PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();  // Ambil waktu saat ini
  
  // Periksa apakah sudah waktunya untuk mengirim data
  if (currentMillis - previousMillis >= interval) {
    // Simpan waktu saat ini
    previousMillis = currentMillis;
    
    // Panggil fungsi untuk mengirim data
    sendSensor();
  }
  
  // Selalu berikan sedikit delay agar loop tidak berjalan terlalu cepat
  delay(10);
}
