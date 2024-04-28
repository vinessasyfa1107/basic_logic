#include <stdio.h>

int main () {
    printf("Program_Mutu_Nilai\n");
    int NA=0;
    printf("Masukkan NA= \n");
    scanf("%d",&NA);
    if (NA>=80 && NA<=100){
        printf("A");
    }
    else if(NA>=68 && NA<80){
        printf("B");
    }
    else if(NA>=56 && NA<68){
        printf("C");
    }
    else if(NA>=45 && NA<56){
        printf("D");
    }
    else if(NA<45){
        printf("E");
    }

    return 0;
}
