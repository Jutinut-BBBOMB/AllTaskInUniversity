#include<stdio.h>
#include<ctype.h>
int main (){
	char str[100];
	int vowel = 0  , letters = 0;
	char vo[5]={'a','e','i','o','u'};
	int i,j;
	
	scanf("%99s" , str);
	
	for (i=0; str[i] != '\0'; i++){
		char ch = tolower(str[i]);
		if( ch >= 'a' && ch <= 'z'){
			letters++;
		for(j=0;j<5;j++){
			if(ch == vo[j]){
				vowel++;
			}
		}
		
	}
	
}
	printf("letters:%d\n  vowel:%d" , letters , vowel);

	
	return 0;
}
