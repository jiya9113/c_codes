#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int *arr;
    int size;
    int capacity;
};

bool isEmpty(struct Stack* s) {
    return (s->size == 0);
}

void push(struct Stack* s, int x) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        int *temp = malloc(s->capacity * sizeof(int));
        for (int i = 0; i < s->size; i++) {
            temp[i] = s->arr[i];
        }
        s->arr = temp;
    }
    s->arr[s->size++] = x;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) return -1;
    return s->arr[--s->size];
}

void initialize(struct Stack *s) {
    s->size = 0;
    s->capacity = 1;
    s->arr = malloc(sizeof(int) * s->capacity);
}

void empty(struct Stack *s) {
    s->size = 0;
}

int top(struct Stack *s) {
    return s->arr[s->size - 1];
}

int operation(int n1, int n2, char opr) {
    if (opr == '+') return n1 + n2;
    else if (opr == '-') return n2 - n1;
    else if (opr == '*') return n1 * n2;
    return n2 / n1;
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();

    while (t != 0) {
        char s[10000];
        fgets(s, sizeof(s), stdin);
        int n = strlen(s);

        struct Stack* stack = malloc(sizeof(struct Stack));
        initialize(stack);
        char temp[10000];

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') break;
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int n1 = top(stack);
                pop(stack);
                int n2 = top(stack);
                pop(stack);
                push(stack, operation(n1, n2, s[i]));
                i = i + 1;
            } else {
                int j = i;
                while (j < n - 1 && s[j] != ' ') j++;
                temp[j - i] = '\0';
                for (int p = i; p < j; p++) temp[p - i] = s[p];
                int no = atoi(temp);
                push(stack, no);
                i = j;
            }
        }
        printf("%d\n", top(stack));
        t--;
    }
    return 0;
}
