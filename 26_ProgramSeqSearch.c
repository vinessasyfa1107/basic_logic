#include <stdio.h>

void SeqSearch(int arr[], int n, int x){
    int i=0;
    int ketemu=0;
    while(i<n){
        if(arr[i] == x){
            printf("Ada di index ke - %d\n", i);
            ketemu = 1;
        }
        i++;
    }
    if(ketemu==0){
        printf("Data tidak ditemukan");
    }
}

void main(){
    int n;
    printf("===== Program Mencari Angka =====");
    printf("\n--Masukan berapa array yang ingin diinput: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Masukan array ke %d : ", i);
        scanf("%d",&arr[i]);
    }
    int cari;
    printf("\n--Masukan array yang dicari : ");
    scanf("%d", &cari);
    SeqSearch(arr, n, cari);
}
