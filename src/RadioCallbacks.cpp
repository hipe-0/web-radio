#include "RadioCallbacks.h"

// Global variables for callback access
WiFiRadio* g_radio = nullptr;
TFTDisplay* g_display = nullptr;

RadioCallbacks::RadioCallbacks(WiFiRadio& radio, TFTDisplay& display) {
    g_radio = &radio;
    g_display = &display;
}

void radio_info(const char* info) {
    Serial.print("info        ");
    Serial.println(info);
    if (g_display) {
        g_display->println(info);
    }
}

void radio_streamTitle(const char* info) {
    Serial.print("streamtitle ");
    Serial.println(info);
    if (g_display) {
        g_display->setTitle(info);
        g_display->displayTitle();
    }
}

void radio_station(const char* info) {
    Serial.print("streamstation ");
    Serial.println(info);
    if (g_display && g_radio) {
        g_display->setStation(g_radio->getCurrentStation(), info);
        g_display->displayTitle();
    }
}