#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 40
typedef struct Stack
{
    char elements[MAX_SIZE];
    int tos;
} Stack;

Stack *initStack()
{
    Stack *s = malloc(sizeof(Stack));
    if (s != NULL)
    {
        s->tos = -1;
    }

    return s;
}

void push(Stack *s, char c)
{
    if (s->tos == MAX_SIZE - 1)
    {
        printf("STACK OVERFLOW");
        exit(1);
    }
    else
    {
        s->tos += 1;
        s->elements[s->tos] = c;
    }
}

int is_empty(Stack *s)
{
    return s->tos == -1;
}

char pop(Stack *s)
{
    if (!is_empty(s))
    {
        s->tos -= 1;
    }

    return s->elements[s->tos + 1];
}

void empty(Stack *s)
{
    while (s->tos != -1)
    {
        pop(s);
    }
}
int is_number(char c)
{
    return c >= 48 && c <= 57;
}

int is_operand(char c)
{
    return   (c >= 48 && c <= 57);
}

int is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int calculate(int op1, int op2, char c)
{
    switch (c)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 + op2;
    default:
        return 0;
    }
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

int compare(char tos, char c)
{
    return precedence(tos) >= precedence(c);
}



int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    printf("Enter the expression ?\n");
    scanf("%s", infix);

    printf("Input : %s \n", infix);

    Stack *stack = initStack();


    int length = strlen(infix);

    for (size_t i = 0; i < length; i++)
    {
        char c = infix[i];
        if (is_operator(c))
        {

            if (!compare(stack->elements[stack->tos], c))
            {
                push(stack, c);
            }
            else
            {
                char ch = pop(stack);
                push(stack, c);
                sprintf(postfix, "%s%c", postfix, ch);
            }
        }
        else if (is_operand(c))
        {
            sprintf(postfix, "%s%c", postfix, c);
        }
    }

    while (stack->tos != -1)
    {
        sprintf(postfix, "%s%c", postfix, pop(stack));
    }

    empty(stack);

    printf("Postfix expression is : %s \n", postfix);

    int result;

    for (size_t i=0; i < strlen(postfix); i++){
        if (is_number(postfix[i])){
            push(stack, postfix[i]);
        } else if (is_operator(postfix[i])){
            int op1 = (int)pop(stack) - 48;
            int op2 = (int)pop(stack) - 48;
            result = calculate(op1, op2, postfix[i]);
            push(stack, (char)result+48);
        }
    }

    printf("Result is : %d \n", result);

    free(stack);

    return 0;
}