#include <stdio.h>

int main (){
    int bilangan1;
    int bilangan2;
    int menu;
    int hasil;

    printf("Switch_Case_Menu\n");
    printf("\n");
    printf("\n");

    printf("Masukkan bilangan1= \n");
    scanf("%d",&bilangan1);
    printf("Masukkan bilangan2= \n");
    scanf("%d",&bilangan2);
    printf("\n");

    printf("pilih menu= \n");
    scanf("%d", &menu);
    printf("\n");

    switch (menu){
case 1:
    hasil= bilangan1+bilangan2;
    printf("hasil = %d", &hasil);
    break;
case 2:
    hasil= bilangan1*bilangan2;
    printf("hasil = %d", &hasil);
    break;
case 3:
    hasil= bilangan1-bilangan2;
    printf("hasil= %d", &hasil);
    break;
}
    return 0;

}
