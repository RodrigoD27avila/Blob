#include <stdio.h>
#include <stdlib.h>

struct stack {
	int data[100];
	int top;
};

struct stack *stack_new(void)
{
	struct stack s = malloc(sizeof(struct stack));
	s->top = 0;
	return s;
}

int stack_push(struct stack *s, int data)
{
	if (stack->top >= 10) {
		return -1;
	}

	s->data[top++] = data;
	return 0;
}

int stack_pop(struct stack *s)
{
	if (s->top <= 0) {
		return -1;
	}

	return 0;
}

int stack_top(struct stack *s)
{
	return s->data[s->top];
}

int main()
{
	struct stack *s = stack_new();
	int i;
	for (i=0; stack_push(s, i) > 0; i++);;

	int r = stack_top();
	while (stack_pop())
}
