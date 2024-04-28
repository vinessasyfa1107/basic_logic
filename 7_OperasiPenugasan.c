#include <stdio.h>

int main () {
    int a,b;

    // pengisian nilai dengan operator =
    a = 15;
    b = 5;

    // pengisian nilai
    b = a;
    printf("Hasil b = a adalah %d\n",b);

    // pengisian dan penambahan
    b += a;
    printf("Hasil b += a adalah %d\n",b);

    // pengisian dan pengurangan
    b -= a;
    printf("Hasil b -= a adalah %d\n",b);

    // pengisian dan perkalian
    b *= a;
    printf("Hasil b *= a adalah %d\n",b);

    // pengisian dan pembagian
    b /= a;
    printf("Hasil b /= a adalah %d\n",b);

    // pengisian dan sisa bagi
    b %= a;
    printf("Hasil b %= a adalah %d\n",b);
    return 0;

}
