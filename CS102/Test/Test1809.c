#include<stdio.h>
int main(){
	int N,i;
	scanf("%i" , &N);
	
	double sum = 0;
	int tmp;
	for(i=0;i<N;i++){
		scanf("%i" ,&tmp);
		sum = sum + tmp;	
	}
	printf("The avg is %f \n", sum/N);
	
	return 0;
}
