#include"tcpSend.h"
#include"iostream"

using namespace ARRC;

int main(){
    TCP tcp("172.16.93.227");
    double data = 0.0;
    for(int i=0;i<15;i++){
        tcp.send(data);
        data += 0.3;
    }
    return 0;
}
