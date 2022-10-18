#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    char c;
    char may;
    int n = 0;
    int totalV;

    do{
        n = read(STDIN_FILENO, &c, 1);
        may = toupper(c);
        if (may == 'A' ||may == 'E' ||may == 'I' ||may == 'O' ||may == 'U'){
            totalV += 1;
        }
    }while(n!=0);
    printf("El total de vocales  es %d\n", totalV);
    return 0;
}