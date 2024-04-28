//Vinessa Gabby Asyfa
//2110512121
//S1 Sistem Informasi

#include <stdio.h>
int main () {
    printf("Program Menghitung Luas Bangun Trapesium\n");
    float alas,atap,tinggi,luas;
    printf("Masukkan alas =\n");
    scanf("%f",&alas);
    printf("Masukkan atap =\n");
    scanf("%f",&atap);
    printf("Masukkan tinggi=\n");
    scanf("%f",&tinggi);
    luas=0.5*(alas+atap)*tinggi;
    printf("Luas Bangun Trapesium = %.01f \n", luas);
    return 0;

}
