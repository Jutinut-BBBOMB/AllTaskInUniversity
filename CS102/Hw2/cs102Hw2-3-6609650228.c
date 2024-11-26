#include<stdio.h>
	int main(){
		char size;
		int a,b,c;
		
		
		printf("Do you want to find smallest or largest number? <S/L>: ");
		scanf("%c", &size );
		
		
		printf("Enter 3 integers: ");
		scanf("%d %d %",&a,&b,&c );
				
				
		if(size == 'S'|| size =='s'){
			int small = a;
			
			if(b < small){
				small = b;
				
			}if(b < small){
				small = c;
				
			}
				printf("Smallest number: %d\n", small);		
		
		} else if(size == 'L' || size =='l'){
			int big = a;
			
			if(b > big){
				big = b;
				
			}if(c > big){
				big = c;
				
			}
				printf("Largest number: %d\n", big);
		}

		return 0;
	}
