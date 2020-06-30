#include <stdio.h>

//Func declaration occurs at the top
int add_together(float x, float y) {
	float z = x + y;
	return z;
}

//Struct Declarations appear at the top
typedef struct {
	float x;
	float y;
} point;

//Standard main syntax
int main(int argc, char** argv) {
	
	//Declare variable
	point p;
	
	 p.x = 1.0;
	 p.y = 2.0;
	 
	 //Declare variable in one line
	float z = add_together(p.x, p.y); 
	
	//Prints line with newline char at end
	puts("Hello the answer is:");
	
	//Prints formatted string
	printf("%f" , z);
	
	//To compile run: gcc -o <application name>
	//To run app: ./<application name>
	return 0;
}
