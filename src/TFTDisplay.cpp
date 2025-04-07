#include "TFTDisplay.h"

TFTDisplay::TFTDisplay() 
    : tft(TFT_CS, TFT_DC, TFT_RST) {
}

void TFTDisplay::init() {
    tft.init(SCREEN_WIDTH, SCREEN_HEIGHT);
    tft.setRotation(0);
    tft.fillScreen(COLOR_BLACK);
    tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
    tft.setTextSize(1);
    tft.println("initializing..."); 
}

void TFTDisplay::clear() {
    tft.fillScreen(COLOR_BLACK);
    tft.setCursor(0, 0);
}

void TFTDisplay::println(const char* text) {
    tft.println(text);
}

void TFTDisplay::printlnBig(const char* text) {
    tft.setTextSize(2);
    tft.println(text);
    tft.setTextSize(1);
}

void TFTDisplay::setTitle(const char* title) {
    currentTitle = String(title);
}

void TFTDisplay::setStation(long stationNr, const char* stationName) {
    currentStation = "Station " + String(stationNr) + ": " + String(stationName);
}

void TFTDisplay::displayTitle() {
    clear();
    tft.setTextSize(2);
    tft.println(currentStation);
    tft.setTextSize(1);
    tft.println("");
    tft.println(currentTitle);
}