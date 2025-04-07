// Web Radio by Hippolyte Mounier
// 2025-02-19
// for ESP32, compile with "Huge App" setting
//
// code largely copied from
// https://github.com/schreibfaul1/ESP32-audioI2S

#include "Arduino.h"
#include "WiFiMulti.h"

#include "Audio.h"
#define I2S_DOUT      25 // connects to DIN on PT8211
#define I2S_BCLK      27 // connects to BCK on PT8211
#define I2S_LRC       26 // connects to WS on PT8211


Audio audio;
WiFiMulti wifiMulti;
String ssid = "gex-59128";
String password = "FtRK-Qvxf-Y16A-cyKg";

#include "TFTDisplay.h"
TFTDisplay display;

#define PIN_POTENTIOMETER_VOLUME 36
#define MAX_VOLUME 21
#define INIT_VOLUME 6
#define MAX_ADC 4095

#include <ezButton.h>
#define PIN_BUTTON 22
ezButton button(PIN_BUTTON);

uint8_t max_stations = 0;  //will be set later
uint8_t stationNr = 0;     //current station(nr), will be set later

#include <Preferences.h>
Preferences pref;

#include "RadioURLs.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Start of Setup()");
  Serial.println("Web Radio by H.Mounier");
  display.init();

  pinMode(PIN_BUTTON, INPUT_PULLUP);
  max_stations = sizeof(stations) / sizeof(stations[0]);

  pref.begin("WebRadio", false);               // instance of preferences for defaults (station, volume ...)
  if (pref.getShort("station", 1000) == 1000)  // if that: pref was never been initialized
    pref.putShort("station", 0);
  else  // get the stored values
  {
    stationNr = pref.getShort("station");
    if (stationNr > max_stations)
      stationNr = 0;
  }

  button.loop();
  if (button.getState() == 0) {  // button is pressed when booting
    stationNr++;
    if (stationNr > max_stations)
      stationNr = 0;
    pref.putShort("station", stationNr);  // store the current station in nvs

    display.clear();
    display.printlnBig("Forcing station N+1");
    display.printlnBig(stations[stationNr]);

    delay(500);
  }


  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(ssid.c_str(), password.c_str());
  wifiMulti.run();
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.disconnect(true);
    wifiMulti.run();
  }

  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);

  audio.setVolume(INIT_VOLUME);

  audio.connecttohost(stations[stationNr]);
  Serial.println("End of Setup()");

  audio.setConnectionTimeout(4000, 8000);
}

/*
void printHeap() {
  const int N = 100;
  static int i = 1;
  if (i-- <= 0) {
    Serial.print("ESP.getFreeHeap() = ");
    Serial.print(ESP.getFreeHeap());
    Serial.print(" buffer = ");
    Serial.print(audio.inBufferFree());
    Serial.print(" / ");
    Serial.println(audio.inBufferSize());
    i = N;
  }
}*/

void manageButton() {
  button.loop();
  if (button.isReleased()) {
    if (stationNr < max_stations - 1)
      stationNr++;
    else
      stationNr = 0;

    pref.putShort("station", stationNr);  // store the current station in nvs


    display.clear();
    display.printlnBig(stations[stationNr]);
    audio.connecttohost(stations[stationNr]);
  }
}
/*
void manageNewStationViaSerial() {
  if (Serial.available()) {  // put streamURL in serial monitor
    audio.stopSong();
    String r = Serial.readString();
    r.trim();
    if (r.length() > 5) audio.connecttohost(r.c_str());
    log_i("free heap=%i", ESP.getFreeHeap());
  }
}*/


void manageVolumePotentiometer() {
  static int prevVolume = INIT_VOLUME;
  int val = analogRead(PIN_POTENTIOMETER_VOLUME);
  int volume = map(val, 0, MAX_ADC, 0, MAX_VOLUME);
  if (volume != prevVolume) {
    audio.setVolume(volume);
    Serial.print("val = ");
    Serial.print(val);
    Serial.print(" volume = ");
    Serial.println(volume);
  }
  prevVolume = volume;
}

void loop() {
  audio.loop();
  //printHeap();
  manageButton();
  manageVolumePotentiometer();
}

void audio_info(const char *info) {
  Serial.print("info        ");
  Serial.println(info);

  display.println(info);
}

void audio_showstreamtitle(const char *info) {
  Serial.print("streamtitle ");
  Serial.println(info);

  display.setTitle(info);
  display.displayTitle();
}

void audio_showstation(const char *info) {
  Serial.print("streamstation ");
  Serial.println(info);

  display.setStation(stationNr, info);
  display.displayTitle();
}


/*
//optional
void audio_id3data(const char *info) {  //id3 metadata
  Serial.print("id3data     ");
  Serial.println(info);
}
void audio_eof_mp3(const char *info) {  //end of file
  Serial.print("eof_mp3     ");
  Serial.println(info);
}
void audio_bitrate(const char *info) {
  Serial.print("bitrate     ");
  Serial.println(info);
}
void audio_commercial(const char *info) {  //duration in sec
  Serial.print("commercial  ");
  Serial.println(info);
}
void audio_icyurl(const char *info) {  //homepage
  Serial.print("icyurl      ");
  Serial.println(info);
}
void audio_lasthost(const char *info) {  //stream URL played
  Serial.print("lasthost    ");
  Serial.println(info);
}*/
