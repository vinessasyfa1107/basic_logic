#include <stdio.h>

int matriks[20][20]; //untuk jumlah maksimum verteksnya adalah 20

void displayMatrix(int v){
    int i, j;
    for(i = 1; i<= v; i++){
        for(j = 1; j <= v; j++){
            printf("%d -> ", matriks[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int u, int v){
    matriks[u][v] = 1;
}

int main(){
    int n, m, asal, tujuan;
    printf("Masukan jumlah simpul: ");
    scanf("%d", &n);
    printf("Masukan jumlah sisi: ");
    scanf("%d", &m);

    //insialisasi matriks dengan 0
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            matriks [i][j]=0;
        }
    }

    //membuat hubungan
    for (int i=1; i<=m; i++){
        printf("simpul asal: ");
        scanf("%d", &asal);
        printf("simpul tujuan: ");
        scanf("%d", &tujuan);
        add_edge(asal, tujuan);
    }
    displayMatrix(n);
    return 0;
}
