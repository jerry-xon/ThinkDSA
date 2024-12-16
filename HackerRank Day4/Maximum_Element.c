#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack
typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    return stack->arr[stack->top--];
}

// Function to get the top element of the stack
int peek(Stack* stack) {
    return stack->arr[stack->top];
}

int main() {
    int n;
    scanf("%d", &n);

    Stack* main_stack = createStack(n);
    Stack* max_stack = createStack(n);

    for (int i = 0; i < n; i++) {
        int query_type;
        scanf("%d\n", &query_type);

        if (query_type == 1) {
            // Push element x
            int x;
            scanf("%d", &x);
            push(main_stack, x);
            if (isEmpty(max_stack) || x >= peek(max_stack)) {
                push(max_stack, x); // Update max_stack
            }
        } else if (query_type == 2) {
            // Delete the top element
            if (!isEmpty(main_stack)) {
                int popped = pop(main_stack);
                if (popped == peek(max_stack)) {
                    pop(max_stack); // Remove from max_stack if it's the maximum
                }
            }
        } else if (query_type == 3) {
            // Print the maximum element
            if (!isEmpty(max_stack)) {
                printf("%d\n", peek(max_stack));
            }
        }
    }

    // Free memory
    free(main_stack->arr);
    free(max_stack->arr);
    free(main_stack);
    free(max_stack);

    return 0;
}

