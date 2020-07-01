#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

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
	
	return(0);
}
