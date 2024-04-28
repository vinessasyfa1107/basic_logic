#include <stdio.h>

void konsonan(char arr[], int n)
{
    int j=0, k=0, i;
    for(i=0; i<n; i++){
        printf("%c", arr[i]);
    }
    for(i=0; i<n; i++){
        if(arr[i]=='a' || arr[i]=='A' || arr[i]=='i' || arr[i]=='I' || arr[i]=='u' || arr[i]=='U' || arr[i]=='e' || arr[i]=='E' || arr[i]=='o' || arr[i]=='O'){
            j++;
        }
        else{
            k++;
        }
    }
    printf("\nBanyak huruf vokal: %d\n", j);
    for(i=0; i<n; i++){
        if(arr[i]=='a' || arr[i]=='A' || arr[i]=='i' || arr[i]=='I' || arr[i]=='u' || arr[i]=='U' || arr[i]=='e' || arr[i]=='E' || arr[i]=='o' || arr[i]=='O'){
            printf("%c ", arr[i]);
        }
    }
    printf("\nBanyak huruf konsonan: %d\n", k);
    for(i=0; i<n; i++){
        if(arr[i]=='a' || arr[i]=='A' || arr[i]=='i' || arr[i]=='I' || arr[i]=='u' || arr[i]=='U' || arr[i]=='e' || arr[i]=='E' || arr[i]=='o' || arr[i]=='O'){
        }
        else{
            printf("%c", arr[i]);
        }
    }
}
void SeqSearch(char arr[], int n, char search){
    int i=0, l=0;
    for(i=0; i<n; i++){
        if(arr[i]==search){
            printf("Huruf '%c' ada di index ke-%d\n", search, i);
            l=1;
        }
    }
    if(l==0){
        printf("Coba cari huruf yang lain!\n");
    }
}
void main(){
    int n, m;

    printf("=== Program Pencarian Huruf Pada Array ===\n\n");
    printf("Masukan jumlah index array: ");
    scanf("%d", &n);

    char arr[n];

    printf("Masukan kata/kalimat: ");
    scanf("%s", &arr);

    konsonan(arr, n);
    char search;

    printf("\nMasukan array yang dicari: ");
    scanf(" %c", &search);
    SeqSearch(arr, n, search);
}
