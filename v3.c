#include <stdio.h>
#include <stdlib.h>

//If compiling on Windows use following functions
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

//readline sub for windows:
char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	//Set aside some space for where the input will live
	char* cpy = malloc(strlen(buffer)+1);
	//place contents of buffer into address located in cpy
	strcpy(cpy, buffer);
	//Denote the end of the input string
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

//add_history for windows:
void add_history(char* unused) {}

//Otherwise include the editline headers
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {
	//Print version name
	puts("Lisp Version 0.0.0.0.1");
	puts("Press Ctrl-c to Exit\n");
	
	while(1) {
		
		//show prompt and catch input
		char* input = readline("lisp> ");
		
		//add input to history
		add_history(input);
		
		//echo input
		printf("lisp> %s\n", input);
		
		//free input
		free(input);
	}
	//Should compile on windows now
	return 0;
}
