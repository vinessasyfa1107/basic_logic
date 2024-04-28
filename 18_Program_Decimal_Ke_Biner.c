#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bilangan,i=1, a;
    int b;
    int biner[10];
    printf("--Masukkan bilangan--\n");
    scanf("%d",&bilangan);
    while(bilangan>0){
        biner[i]=bilangan%2;
         bilangan=bilangan/2;


         i=i+1;
         a=i;

    }
    for(b=a-1;b>0;b--)
        {
        printf("hasil biner = %d \n",biner[b]);
    }

}
