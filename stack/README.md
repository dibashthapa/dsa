# Stack
<b>Stack</b> is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) 

<ul>
<li>push() : Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.</li>
<li>pop() : Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.</li>
</ul>

# Stack as an ADT


<ul>

<li>initStack() creates a new stack that is empty. It needs no parameters and returns an empty stack.
</li>
<li>push(stack, item) adds a new item to the top of the stack. It needs the stack and the item. It returns nothing.
</li>

<li> is_full(stack) tests to see whether the stack is full. It needs the stack and returns a boolean value.</li>

<li>pop(stack) removes the top item from the stack. It needs the stack and returns the item. The stack is modified.</li>
</ul>

# Stack Implementation in C 

## Structure of Stack
```c
// define the structure of Stack
#define MAXSIZE 10
typedef struct Stack
{
    int top;
    int array[MAXSIZE];
} Stack;
```

## Initilize Stack
```c
Stack* initStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack != NULL){
        stack->top = -1;
    }
    return stack;
}
```

## Check if stack is full
```c
int is_full(Stack* stack){
    if (stack->top == MAXSIZE - 1){
        return 1;
    }
    return 0;
}
```

## Check if stack is empty
```c
int is_empty(Stack* stack){
    if (stack->top == -1){
        return 1;
    }
    return 0;
}
```

## Push item to stack
```c

void push(Stack* stack, int item){
    if (is_full(stack)){
        printf("Stack is full\n");
    } else {
        stack->top++;
        stack->array[stack->top] = item;
    }
}
```

## Pop item from stack
```c
int pop(Stack* stack){
    if (is_empty(stack)){
        printf("Stack is empty\n");
        return -1;
    } else {
        int item = stack->array[stack->top];
        stack->top--;
        return item;
    }
}
```

## Print stack
```c
void print_stack(Stack* stack){
    if (is_empty(stack)){
        printf("Stack is empty\n");
    } else {
        for (int i = 0; i <= stack->top; i++){
            printf("%d ", stack->array[i]);
        }
        printf("\n");
    }
}
```

## Main function
```c
int main(){
    Stack* stack = initStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 10);
    pop(stack);
    pop(stack);
    print_stack(stack);
    pop(stack);
    return 0;
}
```
