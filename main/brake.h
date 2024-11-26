#pragma once
#include <FastLED.h>

#define BACKLIGHT_COLOR CRGB(0, 1, 0) // Dim green for the background
#define GLOBAL_BRIGHTNESS 255
#define MIN_BRAKE_BRIGHTNESS 50
#define MAX_BRAKE_BRIGHTNESS 255
#define FLASH_DELAY 50
#define BACKLIGHT_BRIGHTNESS 1
#define EMERGENCY_BRAKING_FLASH_LENGTH 25
#define INITIALIZE_BRAKING_FLASH_LENGTH 7
#define EMERGENCY_BRAKING_THRESHOLD 20 // note this is number of LEDs FROM THE CENTER
#define INITIAL_BRAKE_THRESHHOLD 0 // note this is number of LEDs FROM THE CENTER

class Brake {
private:
    CRGB *LEDStrip; // Pointer to the LED strip
    Brake *brake;
    bool flashON = false; // status while flashing
    unsigned long lastFlashTime = 0; // time of the last flash
    int numLEDs;
    int prevNumActiveLEDs = 0;

public:
    bool initializedBraking = false; // status of the braking
    bool initializedEmergencyBraking = false; // status of the emergency 
    byte active_brightness;
    bool accelerating = false;
    int flashCount = 0; // amount of times that the leds need to flash will be reduced by one each time by FlashRedLEDs
    int numActiveLEDs = 0;

    byte initializedBrakingNumFlashes = INITIALIZE_BRAKING_FLASH_LENGTH;
    byte emergencyBrakingNumFlashes = EMERGENCY_BRAKING_FLASH_LENGTH;

    byte emergencyBrakingThreshold = EMERGENCY_BRAKING_THRESHOLD;
    byte minGyroBrakeThreshold = INITIAL_BRAKE_THRESHHOLD;
    
    byte minBrakeBrightness = MIN_BRAKE_BRIGHTNESS;
    byte maxBrakeBrightness = MAX_BRAKE_BRIGHTNESS;

    Brake(CRGB *leds, int num_leds);
    void Update();
    void FlashRedLEDs();
    void UpdateBrakeLEDs();
    void SetSolid(CRGB color);
};
