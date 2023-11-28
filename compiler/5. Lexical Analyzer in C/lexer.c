#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]){
	char keywords[][10] = { "break", "case", "void", "int", "float", "const", "char", "if", "else" };
	
	for(int i=0; i<sizeof(keywords)/10; i++) {
		if(strcmp(keywords[i], buffer) == 0) {
			return 1;
		}
	}
	
	return 0;
}

int isOperator(char ch){
	char operators[] = {'+','-','*','/','%','='};

	for(int i=0; i<sizeof(operators); i++) {
		if(operators[i] == ch) {
			return 1;
		}
	}
	
	return 0;
}

int isSpace(char ch){
	if(ch==' ' || ch=='\n') {
		return 1;
	}

	return 0;
}


int main(){
	FILE *file = fopen("input.txt", "r");
	if(file == NULL){
		printf("Error while opening file\n");
		return 0;
	}
	
	char ch, lexeme[20];
	int index = 0;
	while( (ch=fgetc(file)) != EOF ){
		if(isOperator(ch)){
			printf("\n%c is an operator\n", ch);
		}
		
		if(isalnum(ch)){
			lexeme[index++]=ch;
		}
		
		if(isSpace(ch) && index!=0){
			lexeme[index] = '\0';
			index = 0;
			if(isKeyword(lexeme)) {
				printf("%s is a keyword\n", lexeme);
			}else{
				printf("%s is an identifier\n", lexeme);
			}
		}
	}
}
