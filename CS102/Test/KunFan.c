#include<stdio.h>

int calculate_cost(int weight) {
    if (weight > 2000) {
        return -1;
    } else if (weight >= 1000) {
        return 100;
    } else if (weight >= 300) {
        return 50;
    } else if (weight >= 200) {
        return 40;
    } else if (weight >= 100) {
        return 25;
    } else {
        return 15;
    }
}

int main(){
	int num_packages,weight,i,cost;
	
	
	printf("Enter the number of packages (up to 5): ");
    scanf("%d", &num_packages);
    
    if(num_packages > 5){
    	printf("You can enter a maximum of 5 packages only.\n");
    	return 1;
	}
	
	for(i=0;i<num_packages;i++){
		printf("Enter the weight of package %d (in grams): ", i + 1);
        scanf("%d", &weight);
        
        cost = calculate_cost(weight);

        if (cost == -1) {
            printf("Package %d weight exceeds 2000 grams and cannot be shipped.\n", i + 1);
        } else {
            printf("The shipping cost for package %d is: %d baht\n", i + 1, cost);
        }
    }
	
	return 0;
}
