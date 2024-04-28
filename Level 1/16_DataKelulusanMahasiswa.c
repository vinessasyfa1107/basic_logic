#include <stdio.h>

void main (){
    int pilihan;

    printf("Pilih tugas yang anda ingin tampilkan (1 atau 2): ");
    scanf("%d", &pilihan);

    switch (pilihan){
    case 1: tugas1();
        break;
    case 2: tugas2();
        break;
    default:
        printf("Maaf tugas yang Anda pilih tidak tersedia");
        break;
    }
}

void tugas1(){
    int data_lulus[3][2];
    int i, j, total;
    total=0;
    printf("--Menampilkan Tugas 1--\n");
    data_lulus[0][0]=10;
    data_lulus[0][1]=20;
    data_lulus[1][0]=15;
    data_lulus[1][1]=25;
    data_lulus[2][0]=100;
    data_lulus[2][1]=300;
    printf("Menampilkan Data Kelulusan Mahasiswa \n\n");
    printf("\t\tTeknik Elektro\t\tTeknik Komputer \n");
    for (i=0; i<=2; i++){
        printf("Tahun ke- %d",i+1);
        for (j=0; j<=1; j++){
            printf("\t\t%d\t",data_lulus[i][j]);
            total=total+data_lulus[i][j];
        }
        printf("\n");
    }
    printf("\n");
    printf("Jumlah    = \t\t\t %d \n",total);
    printf("Rata-rata = \t\t\t %d \n",total/(i*j));
}
void tugas2(){
    int data[2][2];
    int i, j, tahun, total, rata1, rata2;
    tahun=2015;
    total=0;
    printf("--Menampilkan Tugas 2--\n");
    data[0][0]=40;
    data[0][1]=60;
    data[1][0]=50;
    data[1][1]=90;
    printf("Menampilkan Data Kelulusan Mahasiswa \n\n");
    printf("Tahun prodi\t\tTeknik Komputer\t\tTeknik Elektro\t\trata- rata kelulusan pertahun semua prodi \n");
        for (i=0; i<=1; i++){
        printf("%d\t\t",tahun+i);
        total=0;
            for (j=0; j<=1; j++){
                printf("\t\t%d\t",data[i][j]);
                total=total+data[i][j];
                }
                printf("\t\t\t%d", total/2);
                printf("\n");
            }
    rata1=(data[0][0]+data[1][0])/2;
    rata2=(data[0][1]+data[1][1])/2;
    printf("Rata-rata pertahun perprodi \t%d\t\t\t%d", rata1,rata2);

}
