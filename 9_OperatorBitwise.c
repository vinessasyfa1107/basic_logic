#include <stdio.h>

int main () {
    int a = 4;
    int b = 2;

    // operator AND
    printf("a & b = %d\n", a & b);

    // operator OR
    printf("a || b = %d\n", a || b);

    // operator XOR
    printf("a ^ b = %d\n", a ^ b);

    // operator NOT/komplemen
    printf("~a = %d\n", ~a);

    // operator left shift
    printf("a << b = %d\n", a << b);

    // operator right shift
    printf("a >> b = %d\n", a >> b);

    return 0;

}
