#include <common.h>
#define MESSAGE_SIZE 102400
void send_date(int sockfd){
    char *query;
    query = malloc(MESSAGE_SIZE + 1);
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        query[i] = 'a';
    }
}