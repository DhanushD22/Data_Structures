#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *item;
	int top;
	int size;
}Stack;

// prototype declaration 
void init(Stack *, int );
void push(Stack *, int );
int pop(Stack *);
void deallocate(Stack *);
int getSize(Stack *);

void init(Stack *sp, int size){
	sp->top = -1;
	sp->item = (int *)malloc(sizeof(int)*size);
	if(sp->item == NULL){
		printf("Unable to allocate memory\n");
		exit(1);
	}
	sp->size = size;
	
}
void push(Stack *sp, int value){
	if(sp->top == sp->size - 1){
		int *temp;
        temp = (int *)malloc(sizeof(int)*(sp->size*2));
        if(temp == NULL){
            printf("Stack Overflow");
            return; 
        }
        int i;
        for(i = 0; i=sp->top;i++){
            temp[i] = sp->item[i];
        }
        free(sp->item);
        sp->item = temp;
        sp->size *= 2;
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

void deallocate(Stack *sp){
	if(sp->item !=NULL){
		free(sp->item);
	}
    sp->top = -1;
	sp->size = 0;
}

int getSize(Stack *sp){
    return sp->size;
}

void printBinary(unsigned int n){
    Stack s;
    int temp = n;
    const int BASE = 2;
    init(&s, 10);
    while(temp>0){
        int rem = temp % BASE;
        push(&s, rem);
        temp/=BASE;
    }
    printf("Binary Equivalent of %d is: \n", n);
    while(s.top!=-1){
        printf("%d", pop(&s));
    }
    deallocate(&s);
}
int main(){
	printBinary(255);
	return 0;
}
