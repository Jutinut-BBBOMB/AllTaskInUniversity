#include<stdio.h>
	int main(){
		int i,j;
		int prime = 1; 
		while(prime){
		
		printf("Please enter an integer <between 2 to 9999999>: ");
		scanf("%d", &i);
		if(i < 2 || i >9999999){
			printf("%d is not between 2 to 9999999,please re-enter.\n", i);
		}else{
			if(i == 2){
				prime = 1;
			}else{
				for (j = 2;j*j <= i;j++){
					if(i % j == 0){
						prime = 0;
						break;
					}
				}
			}
		
		if(prime){
			printf("%d is a prime number.\n", i);
		}else {
			printf("%d is not a prime number.\n", i);
		}
		break;
	}
}
		
	
		return 0;
	}
