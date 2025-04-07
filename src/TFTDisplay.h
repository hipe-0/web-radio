#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS 15
#define TFT_DC 5
#define TFT_MOSI 23  // Data out
#define TFT_SCLK 18  // Clock out
#define TFT_RST -1

class TFTDisplay {
private:
  Adafruit_ST7789 tft_;
  char station_[50] = "-";
  char title_[50] = "-";
  int nr_ = 0;

public:
  TFTDisplay()
    : tft_(TFT_CS, TFT_DC, TFT_RST) {
  }

  void init() {
    tft_.init(240, 240);  // Init ST7789 240x240

    tft_.fillScreen(ST77XX_BLACK);
    tft_.setCursor(0, 0);
    tft_.setTextSize(2);

    tft_.setTextColor(ST77XX_WHITE);
    tft_.setTextWrap(true);
    tft_.println("Radio will now initialize...");
    tft_.println();
    //delay(4000);
  }

  void print(const char* text) {
    tft_.setTextSize(1);
    tft_.print(text);
  }

  void println(const char* text) {
    tft_.setTextSize(1);
    tft_.println(text);
  }

  void printlnBig(const char* text) {
    tft_.setTextSize(2);
    tft_.println(text);
  }

  void clear() {
    tft_.fillScreen(ST77XX_BLACK);
    tft_.setCursor(0, 0);
  }

  void setStation(int number, const char* title) {
    snprintf(station_, sizeof(station_), "%s", title);
    nr_ = number;
  }
  void setTitle(const char* t) {
    snprintf(title_, sizeof(station_), "%s", t);
  }

  void displayTitle() {
    tft_.fillScreen(ST77XX_BLUE);

    tft_.setCursor(0, 0);
    tft_.setTextWrap(true);

    // displays the station
    tft_.setTextSize(1);
    tft_.setTextColor(ST77XX_WHITE);
    tft_.println("Station");

    tft_.setTextSize(2);
    tft_.setTextColor(ST77XX_YELLOW);
    tft_.print(nr_);
    tft_.print(". ");
    tft_.println(station_);
    tft_.println();

    // displays the title
    tft_.setTextSize(1);
    tft_.setTextColor(ST77XX_WHITE);
    tft_.println("Title");

    tft_.setTextSize(2);
    tft_.setTextColor(ST77XX_MAGENTA);
    tft_.println(title_);
    tft_.println("");
  }
};