#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char antreankafe[10];
    char nama[50];
    char pesanan[50];
}antreankafe;

typedef struct{
    int first;
    int last;
    antreankafe data[10];
}queue;

void createEmpty(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q){
    int hasil = 0;
    if(Q.first == -1){
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q){
    int hasil = 0;
    if(Q.last == 9){
        hasil = 1;
    }
    return hasil;
}

void add(queue *Q){
    if(isEmpty(*Q)==1){
        (*Q).first = 0;
        (*Q).last = 0;
        printf("Masukkan nomor pesanan pelanggan: ");
        fflush(stdin);
        gets((*Q).data[0].antreankafe);
        printf("Masukkan nama pelanggan : ");
        gets((*Q).data[0].nama);
        printf("Masukkan pesanan pelanggan : ");
        gets((*Q).data[0].pesanan);
        printf("Pesanan pelanggan berhasil dimasukan, mohon menunggu\n");
        printf("\n=======================================\n");
    }
    else{
        if(isFull(*Q)!=1){
            (*Q).last=(*Q).last+1;
            printf("Masukkan nomor pesanan pelanggan : ");
            fflush(stdin);
            gets((*Q).data[(*Q).last].antreankafe);
            printf("Masukkan nama pelanggan : ");
            gets((*Q).data[(*Q).last].nama);
            printf("Masukkan pesanan pelanggan : ");
            gets((*Q).data[(*Q).last].pesanan);
            printf("Pesanan pelanggan berhasil dimasukan, mohon menunggu\n");
            printf("\n=======================================\n");
        }
        else{
            printf("Antrian penuh\n");
        }
    }
}

void del(queue*Q){
    if((*Q).last==0){
        (*Q).first = -1;
        (*Q).last = -1;
        printf("Data pesanan terakhir telah dihapus dari antrean\n");
        printf("\n=======================================\n");
    }
    else{
        int i;
        for(i=((*Q).first+1);i<=(*Q).last;i++){
            strcpy((*Q).data[i-1].antreankafe,(*Q).data[i].antreankafe);
            strcpy((*Q).data[i-1].nama,(*Q).data[i].nama);
            strcpy((*Q).data[i-1].pesanan,(*Q).data[i].pesanan);
        }
        (*Q).last = (*Q).last-1;
        printf("Data pesanan terakhir telah dihapus dari antrean\n");
        printf("\n=======================================\n");
    }
}

void printQueue(queue Q){
    if(Q.first != -1){
        printf("======== Program Antrean Kopi Twobrucks ========\n");
        int i;
        for(i=Q.last;i>=Q.first;i--){
            printf("\n");
            printf("Antrian ke : %d \n", i+1);
            printf("Nomor pesanan : %s \n", Q.data[i].antreankafe);
            printf("Nama pelanggan : %s \n", Q.data[i].nama);
            printf("Pesanan : %s \n", Q.data[i].pesanan);
            printf("==================================\n");
        }
    }
    else{
        printf("Tidak ada data dalam antrean Kafe Twobrucks\n");
        printf("\n=======================================\n");
    }
}

int main(){
    queue Q;
    createEmpty(&Q);
    int pilihan;
    while(1){
        printf("=== Program Pelayanan Antrean di Kafe Twobrucks ===\n");
        printf("Pilihan: \n");
        printf("\n1. Tambah data dalam antrean Kafe Twobrucks\n");
        printf("2. Hapus data dalam antrean\n");
        printf("3. Menampilkan antrean sekarang\n");
        printf("4. Keluar\n\n");
        printf("Masukan pilihan anda : ");
        scanf("%d",&pilihan);
        switch(pilihan){
            case 1 :
                printf("--- Menambahkan data dalam antrean --- \n\n");
                add(&Q);
                break;
            case 2:
                printf("!!! Menghapus data dalam antrean !!!\n\n");
                del(&Q);
                break;
            case 3:
                printf("--- Antrean sekarang ---\n\n");
                printQueue(Q);
                printf("\n");
                break;
            case 4:
                exit(1);
            default:
                printf("\nMaaf pilihan tidak tersedia\n");
        }
    }
}
