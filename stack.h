#ifndef _STACK_H_
#define _STACK_H_

struct stack
{
  int val;
  struct stack* next;
};

typedef struct stack* Stack;

Stack stack_operator;
Stack stack_number;

Stack create_stack(int val);

void push(int val, Stack *s);

int pop(Stack *s);

#endif