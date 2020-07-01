#include <stdio.h>

// Declare a buffer of size 2048
static char input[2048];

int main(int argc, char** argv) {
	//Print version name
	puts("Lisp Version 0.0.0.0.1");
	puts("Press Ctrl-c to Exit\n");
	
	//In a never ending loop...
	while(1){
		
		//Output prompt
		fputs("lisp> ", stdout);
		
		/* Read line up to input max
		 * <container>, <read in size> <where to read from>
		 */
		fgets(input, 2048, stdin);
		
		//Echo input back to user
		printf("lisp> %s", input);
	}
}
