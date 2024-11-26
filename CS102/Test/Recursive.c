////6609650228 Jutinut Ratanamongkonkul
#include <stdio.h>

int pow(int b, int e) {
    if (e == 0) {
        return 1;  
    } else {
        return b * pow(b, e - 1);
    }
}

int main() {
    int base, exponent;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    int result = pow(base, exponent);

    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}

