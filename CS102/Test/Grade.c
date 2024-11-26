#include<stdio.h>
int main(){
	int i, r1, r2, r3, r4, r5, r6;
	int ratingWin = 0;
	int ratingLose = 0;
	
	scanf("%d %d %d", &r1 , &r2,&r3);
	scanf("%d %d %d", &r4 , &r5,&r6);
	
	if(r1>r4){
		ratingWin++;
	}else if(r4>r1){
		ratingLose++;
	}
	
	if(r2>r5){
		ratingWin++;
	}else if(r2>r5){
		ratingLose++;
	}
	
	if(r3>r6){
		ratingWin++;
	}else if(r3>r6){
		ratingLose++;
	}
	
	printf("%d %d",ratingWin,ratingLose);
	
	return 0;
}
