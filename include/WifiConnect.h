#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <esp_wps.h>
#include <vector>
#include <Preferences.h>
#include "TFTDisplay.h"

class WifiConnect {
public:
    WifiConnect(TFTDisplay& display, Preferences& preferences);
    void begin();
    bool connect();
    void startWPS();
    bool isConnected() { return WiFi.status() == WL_CONNECTED; }
    void loop();

private:
    static const int MAX_NETWORKS = 5;
    struct NetworkCredentials {
        String ssid;
        String password;
    };

    TFTDisplay& display;
    Preferences& pref;
    std::vector<NetworkCredentials> networks;
    esp_wps_config_t wps_config;
    bool wpsMode = false;
    unsigned long wpsStartTime = 0;

    void loadStoredNetworks();
    void saveNetwork(const String& ssid, const String& password);
    void wpsInitConfig();
    
    static WifiConnect* instance;
    static void ARDUINO_ISR_ATTR onWiFiEvent(WiFiEvent_t event);
    void handleWiFiEvent(WiFiEvent_t event);
};