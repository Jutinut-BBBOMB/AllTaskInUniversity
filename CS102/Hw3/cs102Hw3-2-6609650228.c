//Jutinut Ratanamongkonkul 6609650228

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int is_palindrome(char str[], int length) {
	int i;
    for (i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main(){

	char str[51];
	char ch;  
	int consonants = 0, vowels = 0 , uppercase = 0, lowercase = 0;
	int length,i;
	
	scanf("%50s", str);
	
	
	length = strlen(str);
	for(i=0;i<length;i++){
		ch = str[i];
		
		if(isupper(ch)){
			uppercase++;
		}else if(islower(ch)){
			lowercase++;
		}
		
		ch = tolower(ch);
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
			vowels++;
		}else if(ch >='a' && ch <= 'z'){
			consonants++;
		}
		
	}
	
	printf("Size of input string is %d\n", length);
	printf("#Consonants: %d\n", consonants);
	printf("#Vowels: %d\n", vowels);
	printf("#Upper-case letters: %d\n", uppercase);
	printf("#Lower-case letters: %d\n", lowercase);
	
	if (is_palindrome(str, length) == 1) { 
        printf("Is a palindrome string: Yes\n");
    } else {
        printf("Is a palindrome string: No\n");
    }
	
	
	return 0;
}

