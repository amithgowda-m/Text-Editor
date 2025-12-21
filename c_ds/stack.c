#include "stack.h"
#include <string.h>

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, const char* text) {
    if (s->top < MAX - 1) {
        s->top++;
        strcpy(s->data[s->top], text);
    }
}

int pop(Stack* s, char* text) {
    if (s->top >= 0) {
        strcpy(text, s->data[s->top]);
        s->top--;
        return 1;
    }
    return 0;
}
