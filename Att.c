#include <stdio.h>

int main() {
    int c = 0;
    float a, b;

    printf("Enter the value of a: ");
    scanf("%f", &a);

    printf("Enter the value of b: ");
    scanf("%f", &b);

    while (1) {
        if ((a / b) < 0.70) {
            c += 1;
            a += 1;
            b += 1;
        } else {
            break;
        }
    }

    printf("c = %d\n", c);
    printf("a/b = %f\n", a / b);

    return 0;
}
