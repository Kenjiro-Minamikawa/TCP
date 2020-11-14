#include<tcpServer.hpp>


ARRC::TCP tcp;
WiFiServer server(54321);
double data;

void setup(){
  Serial.begin(115200);
  tcp.Init(&server, "e1838", "S5s6y11mkk@");
}

void loop(){
  tcp.client = server.available();
  if(tcp.client){
    Serial.println("client found");
    while(tcp.client.connected()){
      if(tcp.client.available()){
        data = tcp.read();
        Serial.println(data);
      }
    }
    
  }
}

/*
const char* EAP_USERNAME = "e1838";
const char* EAP_PASSWORD = "S5s6y11mkk@";
const char* ssid = "ANCT-K";
const char* EAP_IDENTITY="NO";

WiFiServer server(54321);

double readVal();

void setup()
{
    Serial.begin(115200);
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

    server.begin();
}

WiFiClient client;
double data;

void loop(){
  client = server.available();
  if(client){
    Serial.println("Client found");

    while(client.connected()){
      if(client.available()){
        data = readVal(); 
        Serial.println(data);
      }
    } 
  client.stop();
  Serial.println("Client Disconnected.");
  }
}

double readVal(){
  String msg = "";
  double rdata;
  while(1){
    char c = client.read();
    if(c == 'x'){
      client.println("");
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
*/