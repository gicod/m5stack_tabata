#pragma once
// #include <WiFi.h>
// #include <HTTPClient.h>
#include "config.h"

class WiFiManager {
public:
    void connect() {
        // WiFi.begin(WIFI_SSID, WIFI_PASS);
        
        // uint8_t attempts = 0;
        // while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        //     delay(500);
        //     attempts++;
        // }
        
        // if (WiFi.status() == WL_CONNECTED) {
        //     connected = true;
        // }
    }
    
    bool isConnected() const {
        return connected;
    }

private:
    bool connected = false;
};