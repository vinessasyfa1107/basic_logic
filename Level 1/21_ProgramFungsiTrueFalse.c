#include <stdio.h>

int apakah_a(char huruf){
    if(huruf == 'a'){
        printf("true");
        return 1;
    }
    else{
        printf("false");
        return 0;
    }
}

void main(){
    char karakter;
    printf("Masukkan karakter : ");
    scanf("%c",&karakter);
    apakah_a(karakter);
}