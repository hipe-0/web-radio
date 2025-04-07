#include "Controls.h"

Controls::Controls(WiFiRadio& radio, TFTDisplay& display)
    : radio(radio), 
      display(display), 
      button(PIN_BUTTON),
      prevVolume(INIT_VOLUME) {
}

void Controls::begin() {
    pinMode(PIN_BUTTON, INPUT_PULLUP);
}

bool Controls::isBootButtonPressed() {
    button.loop();
    return button.getState() == 0;
}

void Controls::loop() {
    manageButton();
    manageVolumePotentiometer();
}

void Controls::manageButton() {
    button.loop();
    if (button.isReleased()) {
        radio.nextStation();
        display.clear();
    }
}

void Controls::manageVolumePotentiometer() {
    int val = analogRead(PIN_POTENTIOMETER_VOLUME);
    int volume = map(val, 0, MAX_ADC, 0, MAX_VOLUME);
    if (volume != prevVolume) {
        radio.setVolume(volume);
        Serial.print("val = ");
        Serial.print(val);
        Serial.print(" volume = ");
        Serial.println(volume);
    }
    prevVolume = volume;
}