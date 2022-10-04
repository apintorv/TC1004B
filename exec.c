#include <stdio.h>
#include <unistd.h>

int main(){
    int pid = fork();

    if (pid ==0){
        printf("Soy el proceso hijo y me voy a convertir en ls\n");
        execl("/workspace/TC1004B/hola", "holamundo", NULL);
        printf("Eso no debe ejecutarse");
    }
    else{
        printf("Soy el proceso padre\n");
    }
    return 0;
}