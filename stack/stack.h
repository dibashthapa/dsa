#define MAX_SIZE 10
typedef struct Stack {
    char elements[MAX_SIZE];
    int tos;
} Stack;

Stack *initStack();
int is_full(Stack *s);
int is_empty(Stack *s);
void push(Stack *s, int element);
int pop(Stack *s);
void printStack(Stack *s);
void destroyStack(Stack *s);

