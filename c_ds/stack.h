#ifndef STACK_H
#define STACK_H

#define MAX 1000
#define TEXT_SIZE 10000

typedef struct {
    char data[MAX][TEXT_SIZE];
    int top;
} Stack;

void initStack(Stack* s);
void push(Stack* s, const char* text);
int pop(Stack* s, char* text);

#endif
