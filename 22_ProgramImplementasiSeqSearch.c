#include <stdio.h>

void main (){
    int i,n;
    printf("=== Program Mencari Ganjil dan Genap ===");
    printf("\n--Masukan berapa array yang ingin diinput: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Masukan array ke %d : ", i);
        scanf("%d",&arr[i]);
    }
    SeqSearch(arr, n);
}

void SeqSearch(int arr[], int n){
    int i=0;
    int ganjil=0;
    int genap=0;
    while(i<n){
        if(arr[i]%2 == 0){
            printf("angka %d = bilangan ganjil\n", arr[i]);
            ganjil++;
        }
        else{
            printf("angka %d = bilangan genap\n", arr[i]);
            genap++;
        }
        i++;
    }
    if(ganjil == 0){
        printf("Tidak ada bilangan ganjil!");
    }
    if(genap == 0){
        printf("Tidak ada bilangan genap!");
    }
    printf("Jumlah bilangan ganjil ada: %d\nJumlah bilangan genap ada: %d", ganjil, genap);
}
