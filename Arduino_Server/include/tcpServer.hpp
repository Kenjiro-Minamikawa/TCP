#ifndef rec_UDP_LIB_h
#define rec_UDP_LIB_h

#include <Arduino.h>
#include <WiFi.h> //Wifi library
#include <esp_wpa2.h> //wpa2 library for connections to Enterprise networks
#include <string.h>

namespace ARRC{
    class TCP{
        public:
            void Init(WiFiServer* mainServer, const char* id, const char* pwd);
            double read();
            WiFiClient client;        
        private:
            WiFiServer* server;
            const char* EAP_IDENTITY="NO";
            const char* EAP_USERNAME;
            const char* EAP_PASSWORD;
            const char* ssid = "ANCT-K";
            const char* hostAddr = "172.16.18.113";

    };
};

#endif