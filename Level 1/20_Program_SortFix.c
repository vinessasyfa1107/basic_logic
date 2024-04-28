#include <stdio.h>

void main(){
    int n,i;
    int menu;

    printf("Masukkan banyak array : ");
    scanf("%d", &n);

    char Arr[n];
    printf("Masukkan array : ");
    for(i=0;i<=n-1;i++){
    scanf("%s", &Arr[i]);
 }
    printf("DAFTAR MENU\n");
    printf("1. Bubble Sort Ascending\n");
    printf("2. Bubble Sort Descending\n");
    printf("3. Insertion Sort Ascending\n");
    printf("4. Insertion Sort Descending\n");
    printf("5. Selection Sort Ascending\n");
    printf("6. Selection Sort Descending\n");
    printf("Pilih Menu : ");
    scanf("%d", &menu);

    printf("Unsorted Array: \n");
    printArray(Arr, n);

switch (menu) {
       case 1 : bubbleSort_asc(Arr, n);
                printf("Sorted Array: \n");
                printArray(Arr, n);
                break;
       case 2 : bubbleSort_desc(Arr, n);
                printf("Sorted Array: \n");
                printArray(Arr, n);
                break;
       case 3 : insertionSort_asc(Arr, n);
                printf("Sorted Array: \n");
                printArray(Arr, n);
                break;
       case 4 : insertionSort_desc(Arr, n);
                printf("Sorted Array: \n");
                printArray(Arr, n);
                break;
       case 5 : selectionSort_asc(Arr, n);
                printf("Sorted Array: \n");
                printArray(Arr, n);
                break;
       case 6 : selectionSort_desc(Arr, n);
                printf("Sorted Array: \n");
                printArray(Arr, n);
                break;
    }

}

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort_desc(char Arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (Arr[j+1] > Arr[j]){
                swap(&Arr[j+1], &Arr[j]);
            }
        }
    }
}

void bubbleSort_asc(char Arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (Arr[j+1] < Arr[j]){
                swap(&Arr[j+1], &Arr[j]);
            }
        }
    }
}

void selectionSort_desc(char arr[], int n){
 int i, j, min_idx;
 for (i = 0; i < n-1; i++){
  min_idx = i;
  for (j = i+1; j < n; j++){
          if (arr[j] > arr[min_idx]){
              min_idx = j;
          }
  }
  swap(&arr[min_idx], &arr[i]);
 }
}

void selectionSort_asc(char arr[], int n){
 int i, j, min_idx;
 for (i = 0; i < n-1; i++){
  min_idx = i;
  for (j = i+1; j < n; j++){
          if (arr[j] < arr[min_idx]){
              min_idx = j;
          }
  }
  swap(&arr[min_idx], &arr[i]);
 }
}

void insertionSort_desc(char Arr[], int n){
 int i, key, j;
 for (i = 1; i < n; i++){
  key = Arr[i];
  j = i - 1;
  while (j >= 0 && Arr[j] < key) {
   Arr[j + 1] = Arr[j];
   j = j - 1;
  }
  Arr[j + 1] = key;
 }
}

void insertionSort_asc(char Arr[], int n){
 int i, key, j;
 for (i = 1; i < n; i++){
  key = Arr[i];
  j = i - 1;
  while (j >= 0 && Arr[j] > key) {
   Arr[j + 1] = Arr[j];
   j = j - 1;
  }
  Arr[j + 1] = key;
 }
}


