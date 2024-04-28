#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pegawai{
    char nama[50];
    char NIP[20];
};

typedef struct pegawai employee;
    employee a[50]; //pegawai a di main

void namabubbleSort_asc(int x){
    int i, j;
    employee tmp;
    for(i = 0; i < x; i++){
        for(j=0; j < x; j++){
            if(strcmp(a[i].nama,a[j].nama)<0){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void namabubbleSort_desc(int x){
    int i, j;
    employee tmp;
    for(i = 0; i < x; i++){
        for(j=0; j < x; j++){
            if(strcmp(a[i].nama,a[j].nama)>0){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void NIPbubbleSort_asc(int x){
    int m, n;
    employee tmp;
    for(m = 0; m < x; m++){
        for(n=0; n < x; n++){
            if(strcmp(a[m].NIP,a[n].NIP)<0){
                tmp = a[m];
                a[m] = a[n];
                a[n] = tmp;
            }
        }
    }
}

void NIPbubbleSort_desc(int x){
    int m, n;
    employee tmp;
    for(m = 0; m < x; m++){
        for(n=0; n < x; n++){
            if(strcmp(a[m].NIP,a[n].NIP)>0){
                tmp = a[m];
                a[m] = a[n];
                a[n] = tmp;
            }
        }
    }
}

void printArray1(int size){
    int i;
    for (i=0; i < size; i++){
        printf("\nNama pegawai: %s ", a[i].nama);
        printf("\nNIP: %s ", a[i].NIP);
    }
    printf("\n");
}

void printArray2(int size){
    int i;
    for (i=0; i < size; i++){
        printf("\nNama pegawai: %s ", a[i].NIP);
        printf("\nNIP: %s ", a[i].nama);
    }
    printf("\n");
}

int main(){
    int choose;
    int nama[50], NIP[20], x, y;
    printf("Masukan data yang diinginkan: ");
    scanf("%d", &x);

    //struct pegawai a[x]; --> pindah ke atas
    for(y = 0; y < x; y++){
        printf("\n=================================================");
        printf("\nNama pegawai: "); scanf("%s", &a[y].nama);
        printf("\nNIP pegawai: "); scanf("%s", &a[y].NIP);
    }

    while(1){
        printf("\nProgram Menambahkan Data Pegawai dengan Metode Bubble Sort");
        printf("\nApa yang ingin Anda lakukan?");
        printf("\n1. Mengurutkan data berdasarkan Nama ascending");
        printf("\n2. Mengurutkan data berdasarkan Nama descending");
        printf("\n3. Mengurutkan data berdasarkan NIP ascending");
        printf("\n4. Mengurutkan data berdasarkan NIP descending");
        printf("\n5. Keluar");
        printf("\n---> "); scanf("%d", &choose);

        switch(choose){
        case 1:
        namabubbleSort_asc(x);
        printf("--- Menampilkan Data berdasarkan Nama ascending ---");
        printArray1(x);
        break;
        case 2:
        namabubbleSort_desc(x);
        printf("--- Menampilkan Data berdasarkan Nama descending ---");
        printArray1(x);
        break;
        case 3:
        NIPbubbleSort_asc(x);
        printf("--- Menampilkan Data berdasarkan NIP ascending ---");
        printArray2(x);
        break;
        case 4:
        NIPbubbleSort_desc(x);
        printf("--- Menampilkan Data berdasarkan NIP descending ---");
        printArray2(x);
        break;
        case 5:
        exit(1);
        break;
        default:
        printf("Coba tekan yang lain!!");
        break;
        }
    }
}

