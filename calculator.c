/*
 * calculator.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "ctype.h"


stack* add(stack *head) {
	
	if(head == NULL) {
		printf("STACK ERROR \n");
		return head;
	}

	int firstNumer = head->numerator;
	int firstDenom = head->denominator;

	stack *next;	
	next = pop(head);

	if(next == NULL) {
		head = push(next, firstNumer, firstDenom);
		printf("STACK ERROR: Only one number on stack \n");
		return head;
	}

	int secondNumer = next->numerator;
	int secondDenom = next->denominator;

	stack *removed = pop(next);

	//
	int GCDivisor = gcdRecursive(firstDenom, secondDenom);
	int LCMultiple = (firstDenom * secondDenom) / GCDivisor;
	int resultNumerator = (firstNumer * secondDenom) + (secondNumer * firstDenom);

	stack *result = push(removed, resultNumerator , LCMultiple);

	return result;
}

stack* subtract(stack *head) {
	
	if(head == NULL) {
		printf("STACK ERROR \n");
		return head;
	}

	int firstNumer = head->numerator;
	int firstDenom = head->denominator;

	stack *next;	
	next = pop(head)
	;
	if(next == NULL) {
		head = push(next, firstNumer, firstDenom);
		printf("STACK ERROR: Only one number on stack \n");
		return head;
	}

	int secondNumer = next->numerator;
	int secondDenom = next->denominator;

	stack *removed;
	removed = pop(next);

	int GCDivisor = gcdRecursive(firstDenom, secondDenom);
	int LCMultiple = (firstDenom * secondDenom) / GCDivisor;
	int resultNumerator = (firstNumer * secondDenom) - (secondNumer * firstDenom);

	stack *result = push(removed, resultNumerator , LCMultiple);
	return result;
}

stack* mulitply(stack *head) {
	
	if(head == NULL) {
		printf("STACK ERROR \n");
		return head;
	}
	int firstNumer = head->numerator;
	int firstDenom = head->denominator;

	stack *next;	
	next = pop(head)
	;
	if(next == NULL) {
		head = push(next, firstNumer, firstDenom);
		printf("STACK ERROR: Only one number on stack \n");
		return head;
	}
	int secondNumer = next->numerator;
	int secondDenom = next->denominator;

	stack *removed;
	removed = pop(next);

	
	int resultNumerator = (firstNumer * secondNumer);
	int resultDenominator = (secondDenom * firstDenom);
	int GCDivisor = gcdRecursive(resultNumerator, resultDenominator);
	int reducedResultNumerator = resultNumerator / GCDivisor;
	int reducedResultDenominator = resultDenominator / GCDivisor;

	stack *result = push(removed, reducedResultNumerator , reducedResultDenominator);

	return result;
}

stack* divide(stack *head) {
	
	if(head == NULL) {
		printf("STACK ERROR \n");
		return head;
	}

	int firstNumer = head->numerator;
	int firstDenom = head->denominator;

	stack *next = pop(head)
	;
	if(next == NULL) {
		head = push(next, firstNumer, firstDenom);
		printf("STACK ERROR: Only one number on stack \n");
		return head;
	}
	int secondNumer = next->numerator;
	int secondDenom = next->denominator;

	if(firstNumer == 0 || firstDenom == 0) {
		printf("DIVIDE BY ZERO ERROR\n");
		head = push(next, firstNumer, firstDenom);
		return head;
	}

	stack *removed = pop(next);

	
	int resultNumerator = (firstNumer * secondDenom);
	int resultDenominator = (secondNumer * firstDenom);
	int GCDivisor;
	if(resultNumerator > resultDenominator)
	{
		GCDivisor = gcdRecursive(resultNumerator, resultDenominator);
	}
	else 
	{
		GCDivisor = gcdRecursive(resultDenominator , resultNumerator);
	}
	int reducedResultNumerator = resultNumerator / GCDivisor;
	int reducedResultDenominator = resultDenominator / GCDivisor;
	
	stack *result = push(removed, reducedResultNumerator , reducedResultDenominator);

	return result;
}



stack* swap(stack *head) 
{
	if(head && head->next) 
		{
  	 	int firstNumer = head->numerator;
  	 	int firstDenom = head->denominator;

  	 	stack *savedNext = pop(head);

  	 	int secondNumer = savedNext->numerator;
  	 	int secondDenom = savedNext->denominator;

  	 	stack *next = pop(savedNext);

  	 	head = push(next , firstNumer, firstDenom);
  	 	head = push(head, secondNumer, secondDenom);


  	 	printf("%d/%d \n", head->numerator , head->denominator);
  	 	}
  	 	else 
  	 	{
  	 			printf("Not enough values on the stack\n");
  	 	}
  	 	return head;
}

stack* dup(stack *head) 

{
  	 if(head) 
  	 {
  	 	head = push(head, head->numerator, head->denominator);
  	 	printf("%d/%d \n", head->numerator , head->denominator);
  	 }
  	 else 
  	 {
  	 	printf("No values on the stack\n");
  	 }
  	 return head;
}


int gcdRecursive(int a , int b) 
{
	if(a == 0) {
		return b;
	}

	return gcdRecursive(b % a, a);
}


int main ()

{
  char input[100];
  char extra[100];
  char operand;
  char command[100];
  int number;
  stack *head = NULL;

  while(1) 
  {

  	printf ("Enter a number or operand : \n");
    fgets (input, sizeof input, stdin);

    if((sscanf(input , "%s %s", command, extra) == 2) || (sscanf(input , "%d %s", &number, extra) == 2)) {
    		printf ("INVALID COMMAND\n");
    }

    else {

     if (sscanf (input, "%d", &number) == 1) {
  		printf("You entered a number!\n");
  		head = push( head , number , 1);
  		printf("%d/%d \n", head->numerator , head->denominator);
  		}
  	else {

  	 if (sscanf (input, "%s", command) == 1) {
  	 	int i;
  	 	for(i = 0; i < strlen(command); i++) {
  	 		command[i] = tolower(command[i]);
  	 	}

  	 	if(strlen(command) == 1) {
  	 		sscanf(input , "%c" , &operand);
  	 		switch(operand) {
  	 			case '+': 
  	 					head = add(head); 
  	 					if(head) {
  	 					printf("%d/%d \n", head->numerator , head->denominator);
  	 					}
  						break;

  	 			case '-': 	
  	 					head = subtract(head); 
  	 					if(head) {
  	 					printf("%d/%d \n", head->numerator , head->denominator);
  	 					}
  						break;
  	 			case '*': 	
  	 					head = mulitply(head); 
  	 					if(head) {
  	 					printf("%d/%d \n", head->numerator , head->denominator);
  	 					}

  	 					break; 
  	 			case '/': 	
  	 					head = divide(head); 
  	 					if(head) {
  	 					printf("%d/%d \n", head->numerator , head->denominator);
  	 					}
  	 					break;
  	 		}	

  	 	}

  	 	else if(strcmp(command , "quit") == 0) {
  	 			printStack(head);
  	 			printf("\n");
  	 			head = clearStack(head);
  	 			return 0;
  	 		}
  	 	else if(strcmp(command , "dup") == 0) {
  	 		head = dup(head);
  	 	}

  	 	else if(strcmp(command , "swap") == 0) {
  	 		head = swap(head);
  	 	}
  	 	else {
  	 		printf ("INVALID COMMAND\n");
  	 	}


  	 	}
  	 }
  	}
  }

return 0;
}
