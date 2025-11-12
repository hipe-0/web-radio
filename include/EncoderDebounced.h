#ifndef ENCODER_DEBOUNCED_H
#define ENCODER_DEBOUNCED_H

#include <Arduino.h>
#include <Encoder.h> // by P.Stoffregen

#define ENCODER_STEPS_PER_DETENT 4 // Number of steps per detent for the encoder

// Class to read a rotary encoder with software debounce filtering
class EncoderDebounced {
public:
  /**
   * Initialize the debounced encoder with two input pins and a debounce delay.
   * @param pinA First encoder pin
   * @param pinB Second encoder pin
   * @param debounceDelayMs Time in milliseconds to confirm a stable position
   */
  void begin(uint8_t pinA, uint8_t pinB, uint16_t debounceDelayMs);
  int read(); // This reads the actual encoder position
  bool hasNewPosition();  // New method to check if there's a new position
  void write(long value); // Set the encoder position to a specific value

private:
  Encoder* enc_;                // Pointer to the PJRC Encoder instance
  uint16_t debounceDelay_;     // Debounce delay in milliseconds
  long lastRawPosition_ = -999; // Most recent raw encoder reading
  long stablePosition_ = -999;  // Last confirmed (debounced) position
  unsigned long lastDebounceTime_ = 0; // Timestamp of last raw change

  /**
   * Read the current raw encoder value, divided by 4 and rounded.
   * Used internally for debounce logic.
   * @return Raw encoder value
   */
  long readRaw_();
};

#endif
