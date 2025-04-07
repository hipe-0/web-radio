#pragma once
#include <ezButton.h>
#include "WiFiRadio.h"
#include "TFTDisplay.h"

class Controls {
public:
    Controls(WiFiRadio& radio, TFTDisplay& display);
    void begin();
    void loop();
    bool isBootButtonPressed();

private:
    static const uint8_t PIN_POTENTIOMETER_VOLUME = 36;
    static const uint8_t PIN_BUTTON = 22;
    static const uint8_t MAX_VOLUME = 21;
    static const uint8_t INIT_VOLUME = 6;
    static const uint16_t MAX_ADC = 4095;

    WiFiRadio& radio;
    TFTDisplay& display;
    ezButton button;
    int prevVolume;

    void manageButton();
    void manageVolumePotentiometer();
};