#include <stdio.h>

int main() {
    // Declare variables for the three sides of the triangle
    int a, b, c;

    // Input the sides of the triangle
    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    // Check if it is a valid triangle
    if (a + b <= c || a + c <= b || b + c <= a) {
        // Not a valid triangle
        printf("0\n");
    } else if (a == b && b == c) {
        // Equilateral triangle
        printf("1\n");
    } else if (a == b || b == c || a == c) {
        // Isosceles triangle
        printf("2\n");
    } else {
        // Scalene triangle
        printf("3\n");
    }

    return 0;
}

