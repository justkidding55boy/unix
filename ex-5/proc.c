#include "my.h"
void print_buf(struct ftpmsg buf)
{
    struct commands *pt;
    for (pt = cmdtbl; pt->desc; pt++) {
        if  (pt->typenum == buf.type) 
            if  (pt->codenum == buf.code || pt->codenum == -1) 
                break;
    }
    printf("type 0x%x, " ,buf.type);
    printf("code 0x%x, (%s), datalen %d\n", buf.code, pt->desc, buf.datalen);
    printf("data:%s\n", buf.data);


    fprintf(stderr, "*****************************\n\n\n");
}

void send_msg(int dstSocket, uint8_t type, uint8_t code, char  *data)
{
        struct ftpmsg msg;
        memset(&msg, 0, sizeof msg);
        msg.type = type;
        msg.code  = code;
        sprintf(msg.data, data);
        msg.datalen = strlen(msg.data);
        if (send(dstSocket, &msg, sizeof msg, 0) < 0) {
            perror("send");
            exit(1);
        }
        print_buf(msg);

}

void time_init()
{
    struct itimerval ttltimer;
    ttltimer.it_value.tv_sec = 1;
    ttltimer.it_value.tv_usec = 0;
    ttltimer.it_interval.tv_sec = 1;
    ttltimer.it_interval.tv_usec = 0;
    if (setitimer(ITIMER_REAL, &ttltimer, NULL) < 0) {
        perror("setitimer");
        exit(1);
    }
    printf("time_init\n");

}