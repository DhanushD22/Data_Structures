#include<stdio.h>
#include<stdlib.h>
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

	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Exit\n");
	int choice, value;

	while(1){
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter Value: ");
				scanf("%d", &value);
				push(&s1, value);
				break;
			case 2: value = pop(&s1);
				if(value != -9999){
					printf("Popped data: %d\n", value);
				}
				break;
			case 3: exit(0);
			default: printf("Invalid Choice\n");
		}
	
	}
	return 0;
}
