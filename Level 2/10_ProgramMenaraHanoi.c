#include <stdio.h>

int arrayK[3]={100, 75, 50}, arrayL[3], arrayM[3];
int topA =2,topB=-1,topC=-1;

void popA(){
    topA=topA-1;
}

void popB(){
    topB=topA-1;
}

void popC(){
    topC=topC-1;
}

void pushA(int batu){
    topA=topA+1;
    arrayK[topA]=batu;
}

void pushB(int batu){
    topB=topB+1;
    arrayL[topB]=batu;
}

void pushC(int batu){
    topC = topC + 1;
    arrayM[topC] = batu;
}

void menarahanoi(){
    printf("Menara A : ");
    for(int i=0; i<=topA; i++){
        printf(" %d  ", arrayK[i]);
    }

    printf("\nMenara B : ");
    for(int i=0; i<=topB; i++){
        printf(" %d  ", arrayL[i]);
    }

    printf("\nMenara C : ");
    for(int i=0; i<=topC; i++){
        printf(" %d  ", arrayM[i]);
    }

}

int main(){
    printf("+++ Program Bermain Menara Hanoi +++\n");
    printf("\n+++ Kondisi Awal Menara Hanoi +++\n");
    menarahanoi();

    printf("\n== 1 Memindah batu 50 dari A ke C\n");
    popA();
    pushC(50);
    menarahanoi();

    printf("\n== 2 Memindah batu 75 dari A ke C\n");
    popA();
    pushC(75);
    menarahanoi();

    printf("\n== 3 Memindah batu 100 dari A ke B\n");
    popA();
    pushB(100);
    menarahanoi();

    printf("\n== 4 Memindah batu 75 dari C ke B\n");
    popC();
    pushB(75);
    menarahanoi();

    printf("\n== 5 Memindah batu 50 dari C ke B\n");
    popC();
    pushB(50);
    menarahanoi();

}
