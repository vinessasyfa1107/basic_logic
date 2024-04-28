#include <stdio.h>

void main(){
    char A[] = {'g', 'a', 'b', 'b', 'y'};
    int panjangkata = sizeof(A) / sizeof(*A);
    char reverse[panjangkata];

    for (int i = 0; i < panjangkata; i++)
    {
        int x;
        x = A[panjangkata - i - 1];
        reverse[i] = x;
    }

    printf("kata yang belum dibalik : ");

    for (int i = 0; i < panjangkata; i++)
    {
        printf("%3c", A[i]);
    }
    printf("\n");
    printf("\nkata yang sudah dibalik : ");

    for (int i = 0; i < panjangkata; i++){
        printf("%3c", reverse[i]);
    } printf("\n");

}
