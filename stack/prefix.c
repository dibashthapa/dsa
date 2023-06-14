#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Stack
{
    char elements[MAX_SIZE];
    int tos;
} Stack;

void push(Stack *s, char c)
{
    if (s->tos == MAX_SIZE - 1)
    {
        printf("STACK OVERFLOW");
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

char peek(Stack *s)
{
    return s->elements[s->tos];
}

int is_operand(char c)
{
    return (c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

int is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
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

char *reverse(Stack *stack, char *s)
{
    char *reversedString = (char *)malloc((strlen(s) + 1) * sizeof(char));
    reversedString[0] = '\0';
    for (int i = 0; i < strlen(s); i++)
    {
        push(stack, s[i]);
    }

    while (stack->tos != -1)
    {
        char c = pop(stack);
        sprintf(reversedString, "%s%c", reversedString, c);
    }

    return reversedString;
}

int main()
{
    Stack stack;
    stack.tos = -1;
    char *reversed_string = "";
    char infix[MAX_SIZE];

    printf("Enter the expression ?\n");
    scanf("%s", infix);

    reversed_string = reverse(&stack, infix);
    char prefix_string[MAX_SIZE] = "";

    for (size_t i = 0; i < strlen(reversed_string); i++)
    {
        char c = reversed_string[i];
        char tos = peek(&stack);
        if (c == ')')
        {
            push(&stack, c);
        }
        else if (is_operand(c))
        {
            sprintf(prefix_string, "%s%c", prefix_string, c);
        }
        else if (is_operator(c))
        {
            if (is_empty(&stack) || tos == ')' || compare(c, tos))
            {
                push(&stack, c);
            }
            else
            {
                char ch = pop(&stack);
                push(&stack, c);
                sprintf(prefix_string, "%s%c", prefix_string, ch);
            }
        }
        else if (c == '(')
        {
            while (peek(&stack) != ')')
            {
                char ch = pop(&stack);

                sprintf(prefix_string, "%s%c", prefix_string, ch);
            }
        }
    }

    while (stack.tos != -1)
    {
        char ch = pop(&stack);
        if (ch != ')')
        {
            sprintf(prefix_string, "%s%c", prefix_string, ch);
        }
    }
    printf("debug!: prefix  string  is %s \n", prefix_string);

    empty(&stack);

    printf("prefix expression is %s \n", reverse(&stack, prefix_string));
    free(reversed_string);
    return 0;
}
