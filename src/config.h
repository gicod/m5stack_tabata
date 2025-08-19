#pragma once

// WiFi credentials
const char* const WIFI_SSID = "Xiaomi_217C";
const char* const WIFI_PASS = "9264300695";

// Tabata settings
constexpr uint8_t TABATA_ROUNDS = 8;
constexpr uint16_t WORK_TIME_MS = 20000;    // 20 sec
constexpr uint16_t REST_TIME_MS = 10000;     // 10 sec

// Display settings
constexpr uint16_t BACKGROUND_COLOR = BLACK;
constexpr uint16_t TEXT_COLOR = WHITE;
constexpr uint16_t WORK_COLOR = RED;
constexpr uint16_t REST_COLOR = GREEN;

// Buzzer
constexpr uint8_t BUZZER_PIN = 2;
constexpr uint16_t BUZZER_FREQ = 2000;
constexpr uint16_t BUZZER_DURATION = 200;