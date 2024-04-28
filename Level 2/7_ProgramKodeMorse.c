#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<unistd.h>
#include<time.h>

// Membuat tipe data bernama "data"
typedef struct {
    char alphabet;
    char morse[10];
}data;

// Membuat tipe data bernama "node"
typedef struct {
    data isiData;
    struct bst * right, * left;
}node;

// Membuat variabel global bernama root
node *root;

// Prosedur yang digunakan untuk memasukkan data pada tree
void insert(node ** tree, char val, char val2[]){
    node *temp = NULL;
    if(!(*tree)){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->isiData.alphabet=val;
        strcpy(temp->isiData.morse,val2);
        *tree = temp;
    }
    if(val < (*tree)->isiData.alphabet){
        insert(&(*tree)->left, val, val2);
    }
    else if(val > (*tree)->isiData.alphabet){
        insert(&(*tree)->right, val, val2);
    }
}

// Prosedur yang digunakan untuk mengkonversi huruf menjadi kode morse
int searchbyHuruf(node * tree, char cari){
    if(!tree){
        return 0;
    }if(cari < tree->isiData.alphabet){
        searchbyHuruf(tree->left, cari);
    }else if(cari > tree->isiData.alphabet){
        searchbyHuruf(tree->right, cari);
    }else if(cari == tree->isiData.alphabet){
        printf("%s", tree->isiData.morse);
    }
}

int searchJawabanKuis(node * tree, char cari, char *kunci[]){
    if(!tree){
        return 0;
    }if(cari < tree->isiData.alphabet){
        searchJawabanKuis(tree->left, cari, kunci);
    }else if(cari > tree->isiData.alphabet){
        searchJawabanKuis(tree->right, cari, kunci);
    }else if(cari == tree->isiData.alphabet){
        strcpy(kunci, tree->isiData.morse);
    }
}

// Prosedur yang digunakan untuk mengkonversi kata menjadi kode morse
void searchbyKata(node * tree){
    int jml, i;
    char cariKata[25];
    printf("Masukkan jumlah huruf dari kata anda : ");
    scanf("%d", &jml);
    printf("Masukkan kata yang akan dicari ke morse : ");
    fflush(stdin);
    gets(cariKata);
    for(i=0;i<jml;i++){
        searchbyHuruf(root, (toupper(cariKata[i])));
        printf("  ");
    }
}

void searchbyMorse(node * tree, char x[]){
    if(tree){
        searchbyMorse(tree->left, x);
        if(strcmpi(tree->isiData.morse, x) == 0){
        printf("%c ", tree->isiData.alphabet);
        }
        searchbyMorse(tree->right, x);
    }
}

// Prosedur yang digunakan untuk mengkonversi kata menjadi kode morse
void searchKataMorse(node * tree){
    int jml, i;
    printf("Masukkan jumlah huruf dari kode morse anda : ");
    scanf("%d", &jml);
    char cariKata[jml][25];
    for(i=0;i<jml;i++){
        printf("Masukkan huruf ke-%d dari kode morse anda : ", i+1);
        fflush(stdin);
        gets(cariKata[i]);
    }
    for(i=0;i<jml;i++){
        searchbyMorse(root, cariKata[i]);
        printf("  ");
    }
}

void print_inorder(node *tree){
    if (tree){
        print_inorder(tree->left);
        printf("Alphabet : %c\t\tMorse\t : %s\n",tree->isiData.alphabet,tree->isiData.morse);
        print_inorder(tree->right);
    }
}

void kuismorse(node * tree){
    printf("   +==========================+\n");
    printf("   |           KUIS           |\n");
    printf("   +==========================+\n");
    time_t t;
    int i;
    float jmlsoal, betul=0;
    char soal, ulang;
    char kunci[10], jawaban[10];
    printf("   Selamat datang di menu kuis!\n");
    printf("   Setelah mengerjakan kuis anda akan mendapatkan score sebagai tolak ukur kemampuan!\n");
    printf("   Masukkan jumlah soal yang anda inginkan : ");
    scanf("%f", &jmlsoal);
    for(i=0;i<jmlsoal;i++){
        /* Intializes random number generator */
        srand((unsigned) time(&t));
        soal = rand() % 26 + 'A';
        printf("\nSoal ke-%d\n", i+1);
        printf("Masukkan kode morse dari huruf berikut : %c\n", soal);
        printf("Jawaban : ");
        fflush(stdin);
        gets(jawaban);
        searchJawabanKuis(root, soal, &kunci);
        if(strcmp(kunci,jawaban)==0){
            printf("Selamat, jawaban anda benar!");
            betul++;
        }else{
            printf("Maaf, jawaban anda salah! ");
            printf("Jawaban yang benar untuk soal ini adalah : %s", kunci);
        }
        printf("\n\n");
    }
    float score;
    score =  100 * betul/jmlsoal;
    printf("\nJumlah benar : %.0f dari %.0f soal", betul, jmlsoal);
    printf("\nNilai anda : %.2f\n", score);

    printf("Kuis telah berakhir, apakah anda ingin melakukan kuis lagi? (masukkan y jika iya) : ");
    scanf("%c", &ulang);
    if(ulang == 'Y' || ulang == 'y'){
        system("cls");
        kuismorse(root);
    }
}

void kuisfrommorse(node * tree){
    printf("   +==========================+\n");
    printf("   |           KUIS           |\n");
    printf("   +==========================+\n");
    time_t t;
    int i;
    float jmlsoal, betul=0;
    char ulang, huruf, jawaban;
    char soal[10];
    printf("   Selamat datang di menu kuis!\n");
    printf("   Setelah mengerjakan kuis anda akan mendapatkan score sebagai tolak ukur kemampuan!\n");
    printf("   Masukkan jumlah soal yang anda inginkan : ");
    scanf("%f", &jmlsoal);
    for(i=0;i<jmlsoal;i++){
        /* Intializes random number generator */
        srand((unsigned) time(&t));
        huruf = rand() % 26 + 'A';

        // Membuat huruf menjadi soal beruba morse
        searchJawabanKuis(root, huruf, &soal);
        printf("\nSoal ke-%d\n", i+1);
        printf("Masukkan kode morse dari huruf berikut : %s\n", soal);
        printf("Jawaban : ");
        fflush(stdin);
        scanf("%c", &jawaban);
        if(huruf == toupper(jawaban)){
            printf("Selamat, jawaban anda benar!");
            betul++;
        }else{
            printf("Maaf, jawaban anda salah! ");
            printf("Jawaban yang benar untuk soal ini adalah : %c", huruf);
        }
        printf("\n\n");
    }
    float score;
    score =  100 * betul/jmlsoal;
    printf("\nJumlah benar : %.0f dari %.0f soal", betul, jmlsoal);
    printf("\nNilai anda : %.2f\n", score);

    printf("Kuis telah berakhir, apakah anda ingin melakukan kuis lagi? (masukkan y jika iya) : ");
    fflush(stdin);
    scanf("%c", &ulang);
    if(ulang == 'Y' || ulang == 'y'){
        system("cls");
        kuisfrommorse(root);
    }
}

void kodemorse(){
    insert(&root,'A',".-");
    insert(&root,'B',"-...");
    insert(&root,'C',"-.-.");
    insert(&root,'D',"-..");
    insert(&root,'E',".");
    insert(&root,'F',"..-.");
    insert(&root,'G',"--.");
    insert(&root,'H',"....");
    insert(&root,'I',"..");
    insert(&root,'J',".---");
    insert(&root,'K',"-.-");
    insert(&root,'L',".-..");
    insert(&root,'M',"--");
    insert(&root,'N',"-.");
    insert(&root,'O',"---");
    insert(&root,'P',".--.");
    insert(&root,'Q',"--.-");
    insert(&root,'R',".-.");
    insert(&root,'S',"...");
    insert(&root,'T',"-");
    insert(&root,'U',"..-");
    insert(&root,'V',"...-");
    insert(&root,'W',".--");
    insert(&root,'X',"-..-");
    insert(&root,'Y',"-.--");
    insert(&root,'Z',"--..");
    insert(&root,'1',".----");
    insert(&root,'2',"..---");
    insert(&root,'3',"...--");
    insert(&root,'4',"....-");
    insert(&root,'5',".....");
    insert(&root,'6',"-....");
    insert(&root,'7',"--...");
    insert(&root,'8',"---..");
    insert(&root,'9',"----.");
    insert(&root,'0',"-----");
}

void main(){
    int menuawal,menukuis;
    char cari, cariKata[25];
    // Memasukkan data kode morse
    kodemorse();
    mainmenu:
    while(1){
        system("cls");
        printf("\n\n");
        printf("   +=================================================+\n");
        printf("   |                                                 |\n");
        printf("   |          Selamat datang di program              |\n");
        printf("   |                                                 |\n");
        printf("   +=================================================+\n");
        printf("   |                                                 |\n");
        printf("   |                       MENU                      |\n");
        printf("   |                                                 |\n");
        printf("   | 1 <- Melihat Daftar Kode Morse       Kuis  -> 6 |\n");
        printf("   |                                                 |\n");
        printf("   | 2 <- Konversi Huruf ke Kode Morse               |\n");
        printf("   |                                                 |\n");
        printf("   | 3 <- Konversi Kata ke Kode Morse                |\n");
        printf("   |                                                 |\n");
        printf("   | 4 <- Konversi Kode morse ke Huruf               |\n");
        printf("   |                                                 |\n");
        printf("   | 5 <- Konversi Kode morse ke Kata                |\n");
        printf("   |                                                 |\n");
        printf("   |                                     KELUAR -> 7 |\n");
        printf("   |                                                 |\n");
        printf("   +-------------------------------------------------+\n");
        printf("   Masukkan pilihan menu anda : ");
        scanf("%d", &menuawal);
        system("cls");
        switch(menuawal){
        case 1:
            system("cls");
            printf("   +=================================================+\n");
            printf("   |                   TABEL MORSE                   |\n");
            printf("   +=================================================+\n");
            print_inorder(root);
            printf("Tekan enter untuk kembali ke menu awal");
            getch();
            break;
        case 2:
            printf("   +=================================================+\n");
            printf("   |          Menu Konversi Huruf ke Morse           |\n");
            printf("   +=================================================+\n");
            printf("Masukkan huruf yang akan diubah ke morse : ");
            fflush(stdin);
            scanf("%c", &cari);
            printf("Morse dari huruf yang anda cari : ");
            searchbyHuruf(root, toupper(cari));
            printf("\nTekan enter untuk kembali ke menu awal");
            getch();
            break;
        case 3:
            printf("   +=================================================+\n");
            printf("   |           Menu Konversi Kata ke Morse           |\n");
            printf("   +=================================================+\n");
            searchbyKata(root);
            printf("\nTekan enter untuk kembali ke menu awal");
            getch();
            break;
        case 4:
            printf("   +=================================================+\n");
            printf("   |           Menu Konversi Morse ke Huruf          |\n");
            printf("   +=================================================+\n");
            printf("Masukkan morse yang akan diubah ke huruf : ");
            scanf("%s", &cariKata);
            printf("huruf dari morse yang anda cari : ");
            searchbyMorse(root, cariKata);
            printf("\nTekan enter untuk kembali ke menu awal");
            getch();
            break;
        case 5:
            printf("   +=================================================+\n");
            printf("   |           Menu Konversi Morse ke Kata           |\n");
            printf("   +=================================================+\n");
            searchKataMorse(root);
            printf("\nTekan enter untuk kembali ke menu awal");
            getch();
            break;
        case 6:
            while(1){
                system("cls");
                printf("\n\n   +=================================================+\n");
                printf("   |                    Menu Kuis                    |\n");
                printf("   +=================================================+\n");
                printf("   |  Pilih jenis kuis :                             |\n");
                printf("   |                                                 |\n");
                printf("   |  1 <- Pertanyaan berupa huruf                   |\n");
                printf("   |                                                 |\n");
                printf("   |  2 <- Pertanyaan berupa morse                   |\n");
                printf("   |                                                 |\n");
                printf("   |  3 <- Kembali ke menu sebelumnya                |\n");
                printf("   |                                                 |\n");
                printf("   +-------------------------------------------------+\n");
                printf("    Masukkan pilihan anda : ");
                scanf("%d", &menukuis);
                switch(menukuis){
                    case 1:
                        system("cls");
                        kuismorse(root);
                        break;
                    case 2:
                        system("cls");
                        kuisfrommorse(root);
                        break;
                    case 3:
                        goto mainmenu;
                        break;
                    default:
                        printf("\n  +----------------------+\n");
                        printf("  |   INPUT MENU SALAH   |\n");
                        printf("  |   SILAKAN COBA LAGI  |\n");
                        printf("  +----------------------+\n");
                        sleep(3);
                        break;
                }
            }
            break;
        case 7:
            printf("\n  +----------------------+\n");
            printf("  |       Exiting...     |\n");
            printf("  |   SAMPAI JUMPA LAGI  |\n");
            printf("  +----------------------+\n");
            sleep(3);
            exit(0);
            break;
        default:
            printf("\n  +----------------------+\n");
            printf("  |   INPUT MENU SALAH   |\n");
            printf("  |   SILAKAN COBA LAGI  |\n");
            printf("  +----------------------+\n");
            sleep(3);
        }
    }
}
