#include "mpc.h"
//find from current directory
#ifdef _WIN32

static char buffer[2048];

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {

	//Create a parser
	mpc_parser_t* Number = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr = mpc_new("expr");
	mpc_parser_t* Lisp = mpc_new("lisp");
	
	//Define the language structures using Regex
	mpca_lang(MPCA_LANG_DEFAULT,
	"															\
		number		:/-?[0-9]+/;								\
		operator	:'+'|'-'|'*'|'/';							\
		expr		:<number> | '(' <operator> <expr>+ ')';		\
		lisp		:/^/ <operator> <expr>+ /$/;				\
	",
	Number, Operator, Expr, Lisp);
	
	puts("Lisp Version 0.0.0.0.2");
	puts("Press Ctrl-c to Exit \n");
	
	while(1) {
		char *input = readline("lisp> ");
		add_history(input);
		
		//Attempt to parse the user input
		
		mpc_result_t r;
		
		if(mpc_parse("<stdin>", input, Lisp, &r)) {
			//On success print and delete the AST
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		} else {
			//Otherwise, print and delete the error
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}
		free(input);
	}
	//Undefine and delete parsers
	mpc_cleanup(4, Number, Operator, Expr, Lisp);
	return 0;
	//Compile instuructions
	//Linux & Mac: gcc -std=c99 -Wall v4.c mpc.c -ledit -lm -o parse-exam
	//Windows: gcc -std=c99 -Wall v4.c mpc.c -o parse-exam
}
