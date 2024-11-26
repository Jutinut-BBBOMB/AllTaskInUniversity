//Jutinut Ratanamongkonkul 6609650228

#include <stdio.h>
void readSquare(int arr[8][8] , int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d", &arr[i][j]);
		}
	}
}

int findMagicNumber(int arr[8][8] , int N){
	int sum = 0, j,i;
	
	for(j=0;j<N;j++){
		sum = sum + arr[0][j];
	}
	
	for (i = 1; i < N; i++) {
        int rowSum = 0;
        for (j = 0; j < N; j++) {
        	rowSum = rowSum + arr[i][j];
		}
        if (rowSum != sum) 
		return -1;
    }

    
    for (i = 0; i < N; i++) {
        int colSum = 0;
        for (j = 0; j < N; j++){
        	colSum = colSum + arr[j][i];
		} 
        if (colSum != sum) 
		return -1;
    }
    
    int diagonal1 = 0, diagonal2 = 0;
    for (i = 0; i < N; i++) {
        diagonal1 = diagonal1 + arr[i][i];
        diagonal2 = diagonal2 + arr[i][N - 1 - i];
    }
    if (diagonal1 != sum || diagonal2 != sum)
	return -1;
	
	return sum;
}

int main(){

    int arr[8][8];
    int N;

    scanf("%d", &N);
    readSquare(arr, N);

    int magicNumber = findMagicNumber(arr, N);

    if (magicNumber == -1) {
        printf("Your square is NOT a magic square.");
    } else {
        printf("Your square is a magic square!! with the magic constant = %d.", magicNumber);
    }

    return 0;
}
