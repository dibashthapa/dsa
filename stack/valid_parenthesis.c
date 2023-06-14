#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Stack
{
    char elements[100];
    int tos;
} Stack;

void push(Stack *s, char c)
{
    s->tos += 1;
    s->elements[s->tos] = c;
}

char pop(Stack *s)
{
    if (s->tos != -1)
    {
        s->tos -= 1;
    }
    return s->elements[s->tos + 1];
}

int isValid(char *s)
{
    Stack stack;

    bool is_valid = false;
    stack.tos = -1;

    for (size_t i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            push(&stack, c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (stack.tos == -1)
                return false;

            char topChar = pop(&stack);

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '['))
            {
                return false;
            }
        }
    }

    return stack.tos == -1;
}

int main()
{
    printf("%s\n", isValid("()") ? "true" : "false");
    printf("%s\n", isValid("(]") ? "true" : "false");
    printf("%s\n", isValid("{[}") ? "true" : "false");
    return 0;
}
