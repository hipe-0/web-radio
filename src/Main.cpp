// Web Radio by Hippolyte Mounier
// 2025-02-19
// for ESP32
//
// code largely copied from
// https://github.com/schreibfaul1/ESP32-audioI2S

#include "Arduino.h"
#include "WiFiRadio.h"
#include "TFTDisplay.h"
#include "Controls.h"
#include "RadioURLs.h"
#include "RadioCallbacks.h"

String ssid = "gex-59128";
String password = "FtRK-Qvxf-Y16A-cyKg";

WiFiRadio radio(ssid, password);
TFTDisplay display;
Controls controls(radio, display);
RadioCallbacks callbacks(radio, display);

void setup() {
    Serial.begin(115200);
    Serial.println("Start of Setup()");
    Serial.println("Web Radio by H.Mounier");
    
    display.init();
    controls.begin();

    // Set global references for callbacks
    g_radio = &radio;
    g_display = &display;

    if (controls.isBootButtonPressed()) {
        radio.nextStation();
        display.clear();
        display.printlnBig("Forcing station N+1");
        delay(500);
    }

    radio.begin();
    radio.setConnectionTimeout(4000, 8000);
}

void loop() {
    radio.loop();
    controls.loop();
}

