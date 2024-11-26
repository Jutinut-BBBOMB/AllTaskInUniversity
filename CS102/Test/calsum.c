#include<stdio.h>
int main(){
	int sum = 0, i, N;
	
	scanf("%d", &N);
	
	for(i=0;i<=N;i++){
		sum = sum + i;
	}
	
	printf("%d", sum);
	
	return 0;
}
