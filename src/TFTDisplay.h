#pragma once
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS    15
#define TFT_DC     5
#define TFT_MOSI  23  // Data out
#define TFT_SCLK  18  // Clock out
#define TFT_RST   -1

// Display dimensions
#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 240

// Colors
#define COLOR_BLACK 0x0000
#define COLOR_WHITE 0xFFFF

class TFTDisplay {
public:
    TFTDisplay();
    void init();
    void clear();
    void println(const char* text);
    void printlnBig(const char* text);
    void setTitle(const char* title);
    void setStation(long stationNr, const char* stationName);
    void displayTitle();

private:
    Adafruit_ST7789 tft;
    String currentTitle;
    String currentStation;
    void setupDisplay();
};
