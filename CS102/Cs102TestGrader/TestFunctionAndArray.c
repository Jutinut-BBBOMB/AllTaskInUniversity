#include <stdio.h>

void printArray(int arr[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[4] = {10, 20, 30, 40};
    printArray(data, 4);
    return 0;
}

