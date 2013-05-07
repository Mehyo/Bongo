#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack create_stack(int val)
{
	Stack s = malloc(sizeof(*s));

	s->val = val;
	s->next = NULL;
	
	return s;
}

void push(int val, Stack *s)
{
	Stack new_s = create_stack(val);	
	
	if(s != NULL)
		new_s->next = *s;
	
	*s = new_s;
}

int pop(Stack *s)
{
	Stack tmp = *s;
	int val = tmp->val;
	*s = tmp->next;
	free(tmp);

	return val;
}
