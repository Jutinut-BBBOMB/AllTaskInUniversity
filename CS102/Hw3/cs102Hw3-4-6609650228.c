//Jutinut Ratanamongkonkul 6609650228

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i,j;
    float *numbers, sum = 0, Avg, min, max;
    int minIndex = 0, maxIndex = 0;

    
    scanf("%d", &N);
    numbers = (float *)malloc(N * sizeof(float)); 

    
    for (i = 0; i < N; i++) {
        scanf("%f", numbers + i);  
        sum = sum + *(numbers + i);      
        if (i == 0 || *(numbers + i) < min) {
            min = *(numbers + i);
            minIndex = i;
        }
        if (i == 0 || *(numbers + i) > max) {
            max = *(numbers + i);
            maxIndex = i;
        }
    }

    Avg = sum / N;
    printf("Maximum value: %.2f\n", max);
	printf("Minimum value: %.2f\n", min);
    printf("Maximum: index %d\n", maxIndex);
    printf("Minimum: index %d\n", minIndex);
    printf("Average: %.2f\n", Avg);

    
    printf("Reverse order: ");
    for (i = N - 1; i >= 0; i--) {
        printf("%.2f ", *(numbers + i));
    }
    printf("\n");

    
    printf("Above average: ");
    for (i = 0; i < N; i++) {
        if (*(numbers + i) > Avg) printf("%.2f ", *(numbers + i));
    }
    printf("\n");

    
    printf("Negative coordinates: ");
    for (i = 0; i < N; i++) {
        for ( j = i + 1; j < N; j++) {
            if (*(numbers + i) < 0 && *(numbers + j) < 0) {
                printf("(%.2f, %.2f), ", *(numbers + i), *(numbers + j));
            }
        }
    }
    printf("\n");

    return 0;
}

