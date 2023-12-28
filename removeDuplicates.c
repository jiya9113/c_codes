#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    int *array;
    int size;
    int capacity;
};

bool isStackEmpty(struct Stack* stack) {
    return (stack->size == 0);
}

void pushToStack(struct Stack* stack, int value) {
    if (stack->size >= stack->capacity) {
        stack->capacity *= 2;
        int *temp = malloc(stack->capacity * sizeof(int));
        for (int i = 0; i < stack->size; i++) {
            temp[i] = stack->array[i];
        }
        stack->array = temp;
    }
    stack->array[stack->size++] = value;
}

int popFromStack(struct Stack *stack) {
    if (isStackEmpty(stack)) return -1;
    return stack->array[--stack->size];
}

void initializeStack(struct Stack *stack) {
    stack->size = 0;
    stack->capacity = 1;
    stack->array = malloc(sizeof(int));
}

void emptyStack(struct Stack *stack) {
    stack->size = 0;
}

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

bool compareStrings(const char *stringA, const char *stringB) {
    return stringA[0] - stringB[0];
}

char* removeDuplicateLetters(char* inputString) {
    int length = strlen(inputString);
    struct Stack *stack = malloc(sizeof(struct Stack));
    initializeStack(stack);
    int *frequency = calloc(26, sizeof(int));
    bool *hasOccurred = calloc(26, sizeof(bool));

    for (int i = 0; i < length; i++) {
        frequency[inputString[i] - 'a']++;
    }

    for (int i = 0; i < length; i++) {
        if (isStackEmpty(stack)) {
            hasOccurred[inputString[i] - 'a'] = true;
            pushToStack(stack, inputString[i]);
        } else {
            if (hasOccurred[inputString[i] - 'a'] == true) {
                frequency[inputString[i] - 'a']--;
                continue;
            }
            char topElement = stack->array[stack->size - 1];
            while (frequency[topElement - 'a'] != 0 && topElement > inputString[i]) {
                popFromStack(stack);
                hasOccurred[topElement - 'a'] = false;
                if (isStackEmpty(stack)) break;
                topElement = stack->array[stack->size - 1];
            }
            pushToStack(stack, inputString[i]);
            hasOccurred[inputString[i] - 'a'] = true;
        }
        frequency[inputString[i] - 'a']--;
    }

    int elements = stack->size;
    char *result = malloc(sizeof(char) * (elements + 1));
    int index = elements - 1;
    result[elements] = '\0';

    while (!isStackEmpty(stack)) {
        result[index] = stack->array[stack->size - 1];
        popFromStack(stack);
        index--;
    }

    return result;
}
