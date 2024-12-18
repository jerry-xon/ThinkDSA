#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generatePrimes(int primes[], int q, int maxLimit) {
    int* isPrime = (int*)malloc((maxLimit + 1) * sizeof(int));
    for (int i = 0; i <= maxLimit; i++) {
        isPrime[i] = 1; 
    }
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= maxLimit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxLimit; j += i) {
                isPrime[j] = 0; 
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= maxLimit && count < q; i++) {
        if (isPrime[i]) {
            primes[count++] = i; 
        }
    }
    free(isPrime);
}


typedef struct Stack {
    int* data;
    int top;
    int size;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}


void push(Stack* stack, int value) {
    stack->data[++stack->top] = value;
}


int pop(Stack* stack) {
    return stack->data[stack->top--];
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}


void waiter(int* numbers, int n, int q) {
    
    int primes[q];
    generatePrimes(primes, q, 10000); 

    
    Stack* currentStack = createStack(n);
    Stack* divisibleStack = createStack(n);

    for (int i = 0; i < n; i++) {
        push(currentStack, numbers[i]);
    }

    for (int i = 0; i < q; i++) {
        Stack* nextStack = createStack(n);

        while (!isEmpty(currentStack)) {
            int num = pop(currentStack);
            if (num % primes[i] == 0) {
                push(divisibleStack, num);
            } else {
                push(nextStack, num); 
            }
        }


        while (!isEmpty(divisibleStack)) {
            printf("%d\n", pop(divisibleStack));
        }

        freeStack(currentStack);
        currentStack = nextStack; 
    }

 
    while (!isEmpty(currentStack)) {
        printf("%d\n", pop(currentStack));
    }

 
    freeStack(currentStack);
    freeStack(divisibleStack);
}


int main() {
    int n, q;

    scanf("%d %d", &n, &q);
    int* numbers = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }


    waiter(numbers, n, q);

    free(numbers);
    return 0;
}
