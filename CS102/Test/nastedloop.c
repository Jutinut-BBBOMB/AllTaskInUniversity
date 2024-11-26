#include <stdio.h>

int main() {
    int n,i,j;
    scanf("%d", &n);  
    
    for ( i = 1; i <= n; i++) {
        int start = i % 5;  
        
        for ( j = 0; j < i; j++) {
            if (start == 0) {
                printf("4 ");
            } else {
                printf("%d ", start);
            }
            
            
            start = (start - 1 + 5) % 5;
        }
        printf("\n"); 
    }
    
    return 0;
}

