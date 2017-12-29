/*
 * stack.h : Declares functions used to implement a LIFO stack
 */


typedef struct stack_tag {
   int numerator;
   int denominator;   
  struct stack_tag *next;
} stack;

stack *push (stack *head, int numerator, int denominator);
stack *pop (stack *head);
stack* clearStack(stack *head);
void printStack(stack *head);