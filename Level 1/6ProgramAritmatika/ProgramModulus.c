#include <stdio.h>

int main () {
    printf("Program Modulus Bilangan\n");
    int r,s,t;
    printf("Masukkan bilangan pertama =\n");
    scanf("%d",&r);
    printf("Masukkan bilangan kedua =\n");
    scanf("%d",&s);
    t=r%s;
    printf("t = %d \n", t);
    return 0;

}
