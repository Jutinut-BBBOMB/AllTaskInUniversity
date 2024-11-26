///BusTicket


#include<stdio.h>
int main(){
	int N;
	scanf("%d", &N);
	
	int digital_root;
	digital_root = (N - 1) % 9 + 1;
	
	printf("%d", digital_root);
	
	
	return 0;
}
