#include<stdio.h>
#define SIZE 10

typedef struct{
	int item[SIZE];
	int top;
}Stack;

// prototype declaration 
void init(Stack *);
void push(Stack *, int );
int pop(Stack *);

void init(Stack *sp){
	sp->top = -1;
}
void push(Stack *sp, int value){
	if(sp->top == SIZE - 1){
		printf("Stack Overflow");
		return;
	}
	sp->top++;
	sp->item[sp->top] = value;
}

int pop(Stack *sp){
	if(sp->top == -1){
		printf("Stack underflow");
		return -9999;
	}
	int value;
	value = sp->item[sp->top];
	sp->top--;
	return value;
}

int main(){
	Stack s1, s2; // Two stacks with an array and index pointer(top)
	// initializing top for both the stacks(mandatory)
	init(&s1);
	init(&s2);
	push(&s1, 100);
	push(&s1, 200);

	push(&s2, 10);
	push(&s2, 20);

	printf("Deleted from s1: %d \n", pop(&s1));
	printf("Deleted from s1: %d \n", pop(&s1));

	printf("Deleted from s2: %d \n", pop(&s2));
	printf("Deleted from s2: %d \n", pop(&s2));






	return 0;
}
