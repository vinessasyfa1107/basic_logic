#include <stdio.h>

int main (){
    int biaya;
    int harga;
    int metode;

    printf("Program_Harga_Motor\n");
    printf("\n");
    printf("\n");

    printf("Metode pembayaran= \n");
    scanf("%d",&metode);
    printf("Harga motor= \n");
    scanf("%d",&harga);
    if(metode==1){
        biaya=harga*95/100;
        printf("Harga motor yang harus dibayarkan adalah= %d\n");
    }
    else if(metode==2){
        biaya=harga*120/100;
        printf("Harga motor yang harus dibayarkan adalah= %d\n");
    }
    return 0;
}
