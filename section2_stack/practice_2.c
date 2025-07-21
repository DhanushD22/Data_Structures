// Dynamic stack with menu options:

#include <stdio.h>
#include <stdlib.h>


// Stack Structure
typedef struct
{
    int *item;
    int top;
    int size;
} Stack;

// prototypes
void init(Stack *, int);
void del(Stack *);
int IsOverflow(Stack *);
int IsUnderflow(Stack *);
void push(Stack *, int);
int pop(Stack *);

// Function Definitions
void init(Stack *sp, int size)
{
    sp->top = -1;
    sp->item = (int *)malloc(sizeof(int)*sp->size);
    if(sp->item == NULL){
        printf("Memory allocation unsuccessful ");
        exit(1);
    }
    
    sp->size = size;
}

int IsOverflow(Stack *sp)
{
    return (sp->top == sp->size - 1);
    // or
//  (sp->top == sp->size - 1)?1:0;
}

int IsUnderflow(Stack *sp)
{
    return (sp->top == -1);
    //  (sp->top == -1)?1:0;
}

void push(Stack *sp, int value)
{
    if (IsOverflow(sp))
    {
        printf("Stack Overflow");
        return;
    }
    sp->top++;
    sp->item[sp->top] = value;
    printf("Pushed Item: %d\n", value);
}

int pop(Stack *sp)
{
    if (IsUnderflow(sp))
    {
        printf("Stack Underflow");
        return -1;
    }
    int value = sp->item[sp->top];
    sp->top--;
    return value;
}
void del(Stack *sp){
    if(sp->item !=NULL){
        free(sp->item);
    }
    sp->top = -1;
    sp->size = 0;
}

int main()
{
    Stack s1;
    printf("Stack Operations:\n");
    printf("1. Push \n2. Pop \n3. Exit\n");
    init(&s1, 3);
    printf("Entering While Loop \n");
    while(1){
        printf("Inside While\n");
        int usr_choice;
        printf("Enter your choice: ");
        scanf("%d", &usr_choice);
        switch (usr_choice){
        case 1:{
            printf("Enter Value: ");
            int value;
            scanf("%d", &value);
            push(&s1, value);
            break;
        }
        case 2:{
            int popped_value;
            popped_value = pop(&s1);
            if(popped_value != -1){
                printf("Popped Value: %d\n", popped_value);
            }
            break;
        }
        case 3:{
            printf("Exit");
            del(&s1);
            exit(0);
        }

        default:
            printf("Not supported");
        }
    }
    return 0;
}
