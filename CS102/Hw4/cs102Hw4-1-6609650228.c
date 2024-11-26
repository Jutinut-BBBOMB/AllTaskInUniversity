/*Jutinut Ratanamongkonkul 6609650228*/

#include<stdio.h>

void swap_elements(int *arr, int pos1, int pos2){
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}


int main(){
	
	int num,i,pos1,pos2;
	
	printf("Enter the number of elements (max 100): ");
	scanf("%d", &num);
	
	int arr[num];
	
	printf("Enter %d numbers: ", num);
	
	for(i=0;i<num;i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Enter first position to swap (0-%d): ", num-1);
	scanf("%d" , &pos1);
	
	printf("Enter second position to swap (0-%d): ", num-1);
	scanf("%d" , &pos2);
	
	swap_elements(arr,pos1,pos2);
	
	printf("After swapping elements at positions %d and %d : ", pos1,pos2);
	for(i=0;i<num;i++){
		printf("%d ", arr[i]);
	}
	
	
	
	return 0;
}
