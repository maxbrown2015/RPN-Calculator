/*
 * stack.c
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


/*
* method pushes new head onto stack
*/ 

stack *push (stack *head , int numer, int denom) 
{
	stack *next;

	next = malloc (sizeof(*next));

  if (next == NULL) {
    printf ("Couldn't allocate a new element\n");
    exit (1);
  }

  next->numerator = numer;
  next->denominator = denom;
  next->next = head;

  return next;
}

stack *pop(stack *head) 
{
	stack *next;
	
	if(head == NULL) {
		return head; 
	}

	next = head->next;
	head->next = NULL;
	free(head);

	return next;

}

stack* clearStack(stack *head) {
	while(head) {
		head = pop(head);
	}
	return head;
}

void printStack(stack* head) {
	while(head) {
		printf("%d/%d \n", head->numerator , head->denominator);
		head = head->next;
	}
}

