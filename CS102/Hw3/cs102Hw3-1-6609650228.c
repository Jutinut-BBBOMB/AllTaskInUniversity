//Jutinut Ratanamongkonkul 6609650228

#include<stdio.h>
int main(){
	int N,i;
	scanf("%d", &N);
	
	float number[N];
	for (i=0;i<N;i++){
		scanf("%f", &number[i]);
	}
	
	float max , min;
	int maxIndex , minIndex;
	max = number[0] , min = number[0];
	maxIndex = 0 , minIndex = 0;
	
	for(i=1;i<N;i++){
		if(number[i] > max ) {
			max = number[i];
			maxIndex = i;
		}
		if(number[i] < min) {
			min = number[i];
			minIndex = i;
		}
	}
	
	float sum;
	sum = 0;
	for (i=0;i<N;i++){
		sum += number[i];
	}
	float Avg = sum / N;
	
	
	printf("Maximum value: %.2f\n", max);
	printf("Minimum value: %.2f\n", min);
	printf("Maximum index: %d\n", maxIndex);
	printf("Minimum index: %d\n", minIndex);
	printf("Average: %.2f\n", Avg);
	printf("Reverse order: ");
	
	for (i = N - 1; i >= 0; i--) {
        printf("%.2f ", number[i]);
    }
    printf("\n");
    
	printf("Above average list: ");
	for (i = 0; i < N; i++) {
        if (number[i] >= Avg) {
            printf("%.2f ", number[i]);
        }
    }
    printf("\n");
    
    int j;
	printf("Negative coordinates: ");
    for (i = 0; i < N; i++) {
        if (number[i] < 0) {
        	for(j=i+1;j<N;j++){
        		if(number[j]<0){
        			printf("(%.2f, %.2f) ", number[i], number[j]);
				}
			}
            
        }
    }
    printf("\n");
	
	return 0;
}
