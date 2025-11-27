#pragma once
#include <M5Stack.h>

// WiFi credentials
const char *const WIFI_SSID = "Xiaomi_217C";
const char *const WIFI_PASS = "9264300695";

// Tabata settings
int TABATA_ROUNDS = 5;
int WORK_TIME_S = 8;
int RELAX_TIME_S = 4;

// Display settings
constexpr uint16_t BACKGROUND_COLOR = BLACK;
constexpr uint16_t FUNNY_COLOR = ORANGE;
constexpr uint16_t TEXT_COLOR = DARKGREY;
constexpr uint16_t WORK_COLOR = GREEN;
constexpr uint16_t RELAX_COLOR = RED;

// Buzzer
constexpr uint8_t BUZZER_PIN = 2;
constexpr uint16_t BUZZER_FREQ = 2000;
constexpr uint16_t BUZZER_DURATION = 200;