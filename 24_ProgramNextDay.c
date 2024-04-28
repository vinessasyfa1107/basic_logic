#include <stdio.h>

void nextday(int hari){
    switch (hari){
    case 1 :
        printf("Selasa");
        break;
    case 2 :
        printf("Rabu");
        break;
    case 3 :
        printf("Kamis");
        break;
    case 4 :
        printf("Jumat");
        break;
    case 5 :
        printf("Sabtu");
        break;
    case 6 :
        printf("Minggu");
        break;
    case 7 :
        printf("Senin");
        break;
    }
}

void main(){
    int hari;
    printf("Program Nextday \n");
    printf("Masukan hari ini sesuai dengan angka pada hari \n");
    printf("Senin  (1)\nSelasa (2)\nRabu   (3)\nKamis  (4)\nJumat  (5)\nSabtu  (6)\nMinggu (7)\n");
    printf("Masukkan Hari = ");
    scanf("%d",&hari);
    printf("Maka hari berikutnya adalah "); nextday(hari);
}
