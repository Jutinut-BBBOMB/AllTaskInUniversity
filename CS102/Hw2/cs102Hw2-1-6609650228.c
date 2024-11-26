#include<stdio.h>
	int main(){
		float hMa, hFa, Avg;
		float hChildFa,hChildMa;
		
		printf("Enter the height of the mother (centimeters): ");
		scanf("%f",&hMa);
		printf("Enter the height of the father (centimeters): ");
		scanf("%f",&hFa);
		
		Avg = (hMa + hFa)/2;
		
		hChildMa = Avg - 13.5;
		hChildFa = Avg + 13.5;
		
		printf("The possible height of the child is between %.2f to %.2f centimeters.", hChildMa,hChildFa);
		
		return 0;
	}
