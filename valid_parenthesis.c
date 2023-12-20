#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack{
    int top;
    int capacity;
    char* arr;
};

void construct(struct stack* s,int capacity){
    s->capacity=capacity;
    s->arr=(char*)malloc(capacity * sizeof(char));
    s->top=-1;
}

bool empty(struct stack *s){
    return (s->top==-1);
}

bool full(struct stack* s){
    return (s->top==s->capacity-1);
}

void push(struct stack* s,char ch){
    if(full(s)){
        return;
    }
    s->arr[++s->top]=ch;
}

char pop(struct stack* s){
    if(empty(s)){
        return '\0';
    }
    return s->arr[s->top--];
}

char top(struct stack* s){
    if(empty(s)){
        return '\0';
    }
    return s->arr[s->top];
}

bool validParenthesis(char s[]){
    struct stack st;
    int n=strlen(s);
    construct(&st,n);
        
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            push(&st,s[i]);
        }
        else{
            if(empty(&st)){
                return false;
            }
            if((s[i]==')' && top(&st)!='(') || (s[i]=='}' && top(&st)!='{') || (s[i]==']' && top(&st)!='[')){
                return false;
            }
            pop(&st);
        }
    }
    if(empty(&st)){
        return true;
    }
    return false;
}

int main(){
    char str[100];
    printf("input\n");
    scanf("%s",str);
    bool ans=validParenthesis(str);
    if(ans){
        printf("valid");
    }
    else{
        printf("not valid");
    }
    return 0;
}