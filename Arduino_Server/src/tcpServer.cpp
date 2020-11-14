#include "tcpServer.hpp"

namespace ARRC{
    void TCP::Init(WiFiServer* mainServer, const char* id, const char* pwd){
        EAP_USERNAME = id;
        EAP_PASSWORD = pwd;
        WiFi.disconnect(true);
        WiFi.mode(WIFI_STA);
        esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
        esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_USERNAME, strlen(EAP_USERNAME)); 
        esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); 
        esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
        esp_wifi_sta_wpa2_ent_enable(&config);
        WiFi.begin(ssid);
        delay(1000);
        int count=0;
        while(WiFi.status() != WL_CONNECTED){
            delay(500);
            Serial.print(".");
            count++;
            if(count>=30){
                Serial.println("Time out, ESP will restart.");
                ESP.restart();
            }
        }
        Serial.println("");
        Serial.println("Connection Established!");
        Serial.print("IP address set:  ");
        Serial.print(WiFi.localIP());
        server = mainServer;
        server->begin();
    }

    double TCP::read(){
        String msg = "";
        double rdata;
        while(1){
            char c = client.read();
            if(c == 'x'){
                client.println("rec");
                break;
            }else if((int)c == 255){
                continue;
            }else{
                msg += c;
            }
        }
        rdata = msg.toFloat();
        return rdata;
    }
}