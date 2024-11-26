#include<stdio.h>
int main() {
    float a, b, c;
    float SumLine1, SumLine2, SumLine3;

    printf("Please enter the lengths of the sides of your triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    SumLine1 = a + b;
    SumLine2 = b + c;
    SumLine3 = c + a;

    if (SumLine1 > c && SumLine2 > a && SumLine3 > b) { 
        if (a == b && b == c) {
            printf("This is an equilateral triangle \n");
        } else if (a == b || b == c || c == a) {
            printf("This is an isosceles triangle \n");
        } else {
            printf("This is a scalene triangle \n");
        }
    } else {
        printf("This is NOT a possible triangle \n");
    }

    return 0;
}

