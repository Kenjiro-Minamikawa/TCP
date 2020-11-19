#include<tcpServer.hpp>


ARRC::TCP tcp;
WiFiServer server(54321);
double data;

void setup(){
  Serial.begin(115200);
  tcp.Init(&server, "student-id", "password");
}

void loop(){
  if(tcp.clientFind()){
    Serial.println("client found");
    while(tcp.connected()){
      if(tcp.available()){
        data = tcp.read();
        Serial.println(data);
      }
    }
    Serial.println("connection closed");
  }
}

