#pragma once

#include "Audio.h"
#include "GlobalAudio.h"
#include <WiFi.h>
#include "Arduino.h"
#include "WiFiMulti.h"
#include <Preferences.h>

class WiFiRadio {
    Audio* audio;  // Non-static pointer to global audio
    static WiFiRadio* instance;
    int currentStation = 0;

public:
    WiFiRadio(const String& ssid, const String& password);
    void begin();
    void loop();
    void setVolume(int volume);
    void nextStation();
    long getCurrentStation() { return stationNr; }
    void setConnectionTimeout(int connectTimeout, int responseTimeout);
    
    static WiFiRadio* getInstance() { return instance; }
    static Audio* getAudio() { return &audioInstance; }  // Return pointer to global

private:
    WiFiMulti wifiMulti;
    Preferences pref;
    String ssid;
    String password;
    long stationNr;
    long max_stations;

    void connectWiFi();
    void setupAudio();
};