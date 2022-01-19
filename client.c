
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int
main()
{
 struct sockaddr_in server;
 int sock;
 char buf[32];
 int n;

 /* ソケットの作成 */
 sock = socket(AF_INET, SOCK_STREAM, 0);

 /* 接続先指定用構造体の準備 */
 server.sin_family = AF_INET;
 server.sin_port = htons(80);
 server.sin_addr.s_addr = inet_addr("192.168.0.32");

 /* サーバに接続 */
 connect(sock, (struct sockaddr *)&server, sizeof(server));

 /* サーバからデータを受信 */
 //memset(buf, 0, sizeof(buf));
 //n = read(sock, buf, sizeof(buf));

 //printf("%d, %s\n", n, buf);

 for(int i=0; i<3; i++){
     int a;
     scanf("%d", &a);
     write(sock, "HELLO", 5);
    //memset(buf, 0, sizeof(buf));
    //n = read(sock, buf, sizeof(buf));

    //printf("receive data : %d, %s\n", n, buf);
 }

 /* socketの終了 */
 close(sock);

 return 0;
}
