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
    return (c >= 48 && c <= 57);
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

char peek(Stack *s)
{
    return s->elements[s->tos];
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
         if (c == '(')
        {
            push(stack, c);
        }
        else if (is_operator(c))
        {

            if (!compare(peek(stack), c))
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
        else if (c == ')')
        {
            while (peek(stack) != '(')
            {
                char ch = pop(stack);
                sprintf(postfix, "%s%c", postfix, ch);
            }
        }
    }

    while (stack->tos != -1)
    {
        char ch = pop(stack);
        if (ch != '(')
        {
            sprintf(postfix, "%s%c", postfix, ch);
        }
    }

    printf("Postfix expression is : %s \n", postfix);

    int result;


    printf("Postfix Evaluation is \n");

    for (size_t i = 0; i < strlen(postfix); i++)
    {
        if (is_number(postfix[i]))
        {
            push(stack, postfix[i] - '0');
        }
        if (is_operator(postfix[i]))
        {
            int op1 = pop(stack);
            int op2 = pop(stack);
            result = calculate(op1, op2, postfix[i]);
            printf(" %d %c %d = %d \n", op1, postfix[i], op2, result);
            push(stack, result);
        }
    }

    printf("Result is : %d \n", result);

    free(stack);

    return 0;
}