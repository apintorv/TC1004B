#include <stdio.h>
#include <unistd.h>

int main(){
    int pid = fork();

    if (pid ==0){
        printf("Soy el proceso hijo\n");
        sleep(10);
        printf("Ya terminé");
    }
    else{
        printf("Soy el proceso padre\n");
    }
    return 0;
}