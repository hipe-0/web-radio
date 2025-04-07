#include "WiFiRadio.h"
#include "RadioURLs.h"
#include "GlobalAudio.h"

#define I2S_DOUT      25
#define I2S_BCLK      27
#define I2S_LRC       26
#define INIT_VOLUME   6

WiFiRadio* WiFiRadio::instance = nullptr;

WiFiRadio::WiFiRadio(const String& ssid, const String& password) 
    : ssid(ssid), password(password), stationNr(0), max_stations(0) {
    instance = this;
    audio = &audioInstance;
}

void WiFiRadio::begin() {
    max_stations = getStationsCount();
    
    pref.begin("WebRadio", false);
    if (pref.getShort("station", 1000) == 1000) {
        pref.putShort("station", 0);
    } else {
        stationNr = pref.getShort("station");
        if (stationNr >= max_stations)
            stationNr = 0;
    }

    connectWiFi();
    setupAudio();
}

void WiFiRadio::connectWiFi() {
    WiFi.mode(WIFI_STA);
    wifiMulti.addAP(ssid.c_str(), password.c_str());
    wifiMulti.run();
    if (WiFi.status() != WL_CONNECTED) {
        WiFi.disconnect(true);
        wifiMulti.run();
    }
}

void WiFiRadio::setupAudio() {
    audio->setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio->setVolume(INIT_VOLUME);
    audio->connecttohost(stations[stationNr]);
}

void WiFiRadio::loop() {
    audio->loop();
}

void WiFiRadio::setVolume(int volume) {
    audio->setVolume(volume);
}

void WiFiRadio::nextStation() {
    if (stationNr < max_stations - 1)
        stationNr++;
    else
        stationNr = 0;

    Serial.println("Switching to station " + String(stationNr) + ": " + stations[stationNr]);
    audio->stopSong();
    pref.putShort("station", stationNr);
    audio->connecttohost(stations[stationNr]);
}

void WiFiRadio::setConnectionTimeout(int connectTimeout, int responseTimeout) {
    audio->setConnectionTimeout(connectTimeout, responseTimeout);
}