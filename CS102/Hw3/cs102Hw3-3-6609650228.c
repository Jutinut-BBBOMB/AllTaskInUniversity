//Jutinut Ratanamongkonkul 6609650228
#include <stdio.h>

int isMagicSquare(int matrix[8][8], int N) {
    int sum = 0, i,j;
    for (i = 0; i < N; i++) 
	sum = sum + matrix[0][i];

    
    for (i = 1; i < N; i++) {
        int rowSum = 0;
        for (j = 0; j < N; j++) rowSum = rowSum + matrix[i][j];
        if (rowSum != sum) 
		return 0;
    }

    
    for (i = 0; i < N; i++) {
        int colSum = 0;
        for (j = 0; j < N; j++) colSum = colSum + matrix[j][i];
        if (colSum != sum) 
		return 0;
    }

    
    int diagonal1 = 0, diagonal2 = 0;
    for (i = 0; i < N; i++) {
        diagonal1 = diagonal1 + matrix[i][i];
        diagonal2 = diagonal2 + matrix[i][N - 1 - i];
    }
    if (diagonal1 != sum || diagonal2 != sum)
	return 0;

    return 1;
}

int main() {
    int N,i,j;
    scanf("%d", &N);
    
    int matrix[8][8];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isMagicSquare(matrix, N)) {
        printf("This is a magic square!\n");
    } else {
        printf("This is NOT a magic square!\n");
    }

    return 0;
}

