/*Jutinut Ratanamongkonkul 6609650228*/

#include<stdio.h>
#include<string.h>

	struct person {
		int accountNumber;
		char name[50];
		float balance;
	};
	
	const int MAX = 100;
	
	void addCustomer(struct person people[], int *count){
		if(*count >= MAX){
			return;
		}
		
		printf("Enter account number: ");
		scanf("%d", &people[*count].accountNumber);
		
		printf("Enter customer Name: ");
		getchar();
		fgets(people[*count].name, sizeof(people[*count].name), stdin);
    
    	people[*count].name[strcspn(people[*count].name, "\n")] = '\0';
		
    	
    	printf("Enter initial balance: ");
    	scanf("%f", &people[*count].balance);
    	
    	(*count)++;
    	printf("Customer added successfully.\n");
    	
		
	}

	void displayCustomer(struct person people[], int count){
		if(count == 0){
			printf("No registered persons to display.");
			return;
		}
		
		int i;
		for (i = 0; i < count; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", people[i].accountNumber, people[i].name, people[i].balance);
        
    }
		
	}

	void deposit(struct person people[], int count){
		
		int account,i;
		float total;
		
		printf("Enter account number for deposit: ");
		scanf("%d" , &account);
		
		printf("Enter amount to deposit: ");
		scanf("%f" , &total);
		
		for(i=0;i<count;i++){
			if(people[i].accountNumber == account){
				people[i].balance += total;
				
				printf("Deposit successful. New balance: %.2f\n", people[i].balance);
            	return;
			}
		}
		
		
	}

	void withdraw(struct person people[], int count){
		
		int account,i;
		float total;
		
		printf("Enter account number for withdrawal: ");
		scanf("%d" , &account);
		
		printf("Enter amount to withdraw: ");
		scanf("%f" , &total);
		
		for(i=0;i<count;i++){
			if(people[i].accountNumber == account){
				if(people[i].balance >= account){
					people[i].balance -= total;
				
				printf("Withdrawal successful. New balance: %.2f\n", people[i].balance);
            	return;
				}
				
			}
		}
}

int main(){
	
	int count = 0 , num ;
	struct person people[MAX];
	
	do{
		printf("\nBank Management System\n");
		printf("1. Add New Customer\n");
		printf("2. Deposit Money\n");
		printf("3. Withdraw Money\n");
		printf("4. Display All Customers\n");
		printf("5. Exit\n");
	
		printf("Enter your choice: ");
		scanf("%d", &num);
		
		switch(num){
			
			case 1: addCustomer(people, &count);
			break;
			
			case 2: deposit(people, count);
			break;
			
			case 3: withdraw(people, count);
			break;
			
			case 4: displayCustomer(people , count);
			break;
			
			case 5: printf("Exiting program.\n");
			break;
			
			default: printf("Invalid choice. Please try again.\n");
        }
			
		}
		while (num != 5);
		
	
	return 0;
}
