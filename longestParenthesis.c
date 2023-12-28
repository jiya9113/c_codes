#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    int *arr;
    int size;
    int capacity;
};

bool isEmpty(struct Stack* stack) {
    return (stack->size == 0);
}

void push(struct Stack* stack, int x) {
    if (stack->size >= stack->capacity) {
        stack->capacity *= 2;
        int *temp = malloc(stack->capacity * sizeof(int));
        for (int i = 0; i < stack->size; i++) {
            temp[i] = stack->arr[i];
        }
        stack->arr = temp;
    }
    stack->arr[stack->size++] = x;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) return -1;
    return stack->arr[--stack->size];
}

void initialize(struct Stack *stack) {
    stack->size = 0;
    stack->capacity = 1;
    stack->arr = malloc(sizeof(int));
}

void empty(struct Stack *stack) {
    stack->size = 0;
}

int top(struct Stack *stack) {
    return stack->arr[stack->size - 1];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char* s) {
    int n = strlen(s);
    struct Stack *stack = malloc(sizeof(struct Stack));
    initialize(stack);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            push(stack, i);
        } else {
            if (!isEmpty(stack)) {
                if (s[top(stack)] == '(') {
                    pop(stack);
                } else {
                    push(stack, i);
                }
            } else {
                push(stack, i);
            }
        }
    }
    int ans = 0;
    int a = 0;
    int b = n - 1;
    if (isEmpty(stack)) return n;
    while (!isEmpty(stack)) {
        a = top(stack);
        ans = max(b - a, ans);
        pop(stack);
        b = a - 1;
    }
    a = -1;
    ans = max(b - a, ans);
    return ans;
}
