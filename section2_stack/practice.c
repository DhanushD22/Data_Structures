// Static stack with menu options:

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Stack Structure
typedef struct
{
    int item[SIZE];
    int top;
    // int size;
} Stack;

// prototypes
void init(Stack *);
int IsOverflow(Stack *);
int IsUnderflow(Stack *);
void push(Stack *, int);
int pop(Stack *);

// Function Definitions
void init(Stack *sp)
{
    sp->top = -1;
}

int IsOverflow(Stack *sp)
{
    return (sp->top == SIZE - 1);
    // or
//  (sp->top == SIZE - 1)?1:0;
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
    printf("Popped Value: %d\n", value);
    return value;
}

int main()
{
    Stack s1;
    printf("Stack Operations:");
    printf("1. Push \n2. Pop \n3. Exit\n");
    init(&s1);
    while (1)
    {
        int usr_choice;
        printf("Enter your choice: ");
        scanf("%d", &usr_choice);
        switch (usr_choice)
        {
        case 1:
        {
            printf("Enter Value: ");
            int value;
            scanf("%d", &value);
            push(&s1, value);
            break;
        }
        case 2:
        {
            int popped_value;
            popped_value = pop(&s1);
            break;
        }
        case 3:
        {
            printf("Exit");
            exit(0);
        }

        default:
            printf("Not supported");
        }
    }
    return 0;
}
