#include<stdio.h>
/*
InPairs: WriteaCprogram that acts asa simple
calculator with modular functions: add,subtract
andmmlltipyy Each operation will beimplemented
asaseparate function. Once the user entersan
equalsign, theywill see the right answer.

Note: play differentroles- one writes, theother
reviews*/////////////////////

// Function declarations
float add(float x, float y);
float subtract(float x, float y);
float multiply(float x, float y);


int main(void){
    float num1, num2, result;
    char op;

    
    printf("Enter an expression (e.g 5 + 5 =):");
    scanf("%f" "%c" "%f",  &num1, &op, &num2);

    
    switch (op){
	case('+'):
	  result = add(num1, num2);
	  break;
        case('-'):
          result = subtract(num1, num2);
       	  break;
        case('*'):
          result = multiply(num1, num2);
          break;
	default:
	  printf("Invalid operator!\n");
	  return 1;

   }

    printf("= %.3f\n", result);
    
    return 0;
}

// Function definitions
float add(float x, float y){return x+y; }
float subtract(float x, float y){return x-y; }
float multiply(float x, float y){return x*y; }

    
