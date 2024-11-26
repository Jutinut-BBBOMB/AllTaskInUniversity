/*Jutinut Ratanamongkonkul 6609650228*/

#include<stdio.h>
#include<string.h>

	struct person {
		int id;
		char name[50];
		int age;
		float income;
	};
	
	const int MAX = 100;
	
	void add(struct person people[], int *count){
		if(*count >= MAX){
			return;
		}
		
		printf("Enter ID: ");
		scanf("%d", &people[*count].id);
		
		printf("Enter Name: ");
		getchar();
		fgets(people[*count].name, sizeof(people[*count].name), stdin);
    
    	people[*count].name[strcspn(people[*count].name, "\n")] = '\0';
		
		printf("Enter Age: ");
    	scanf("%d", &people[*count].age);
    	
    	printf("Enter Monthly Income: ");
    	scanf("%f", &people[*count].income);
    	
    	(*count)++;
    	printf("Person registered successfully.\n");
    	printf("==\n");
    	
		
	}

	void display(struct person people[], int count){
		if(count == 0){
			printf("No registered persons to display.");
			return;
		}
		
		printf("ID\tName\t\t\tAge\tMonthly Income\n");
		
		int i;
		for (i = 0; i < count; i++) {
        printf("%d\t%-20s\t%d\t%.2f\n", people[i].id, people[i].name, people[i].age, people[i].income);
        
    }
    	printf("==\n");
		
	}


int main(){
	
	int count = 0 , num ;
	struct person people[MAX];
	
	do{
		printf("Poverty Registration System\n");
		printf("1.Register New Person\n");
		printf("2.Display All Registered Persons\n");
		printf("3.Exit\n");
		printf("==\n");
	
		printf("Enter your choice: ");
		scanf("%d", &num);
		
		switch(num){
			
			case 1: add(people, &count);
			break;
			
			case 2: display(people , count);
			break;
			
			case 3: printf("Exiting program.\n");
			break;
			
			default: printf("Invalid choice. Please try again.\n");
        }
			
		}
		while (num != 3);
		
	
	return 0;
}
