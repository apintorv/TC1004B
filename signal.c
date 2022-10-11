#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static int ton;

void holaMundo(int signalNumber){
    if(signalNumber == 10){
        printf("Es la señal 10.\n");
        ton = 0;

    }else{
        printf("Es otra señal.\n");
    }
}

void nomeMatas(int sig){
    printf("jaja, no me matas \n");
}

int main(){
    signal(12, holaMundo); // signal(que señal,nombre de función a ejecutar)
    signal(10, holaMundo);
    signal(2, nomeMatas);

    ton = 1;
    while(ton == 1){
        printf("Estoy trabajando\n");
        sleep(1);
    }
    printf("Nunca llega \n");
    return 0;
}