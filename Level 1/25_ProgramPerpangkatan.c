#include<stdio.h>

int perpangkatan(int bilangan, int N){
    if(N==0){
        return 1;
    }
    else{
        return bilangan * perpangkatan(bilangan,N-1);
    }
}

main(){
    int bilangan,N;
    printf("Masukkan bilangan yang akan dipangkatkan: ");
    scanf("%d", &bilangan);
    printf("Masukkan pangkatnya: ");
    scanf("%d", &N);
    printf("%d pangkat %d = %d", bilangan, N, perpangkatan(bilangan,N));
return 0;
}
