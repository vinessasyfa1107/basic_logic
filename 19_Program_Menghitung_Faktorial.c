#include <stdio.h>

int main (){
    int bilangan,hasil=1;
    int i=1;
    printf("---Berapa bilangannya = ---\n");
    scanf("%d",&bilangan);
    for(i=1;i<=bilangan;i++){
        hasil = i*hasil;
    }
    printf("faktorial dari %d! adalah = %d \n",bilangan,hasil);
    return 0;
}
