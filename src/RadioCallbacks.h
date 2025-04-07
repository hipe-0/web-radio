#pragma once
#include "WiFiRadio.h"
#include "TFTDisplay.h"
#include <Arduino.h>

// Global references to be set in setup
extern WiFiRadio* g_radio;
extern TFTDisplay* g_display;

class RadioCallbacks {
public:
    RadioCallbacks(WiFiRadio& radio, TFTDisplay& display);
};

// Simple static callback functions
void radio_info(const char* info);
void radio_streamTitle(const char* info);
void radio_station(const char* info);