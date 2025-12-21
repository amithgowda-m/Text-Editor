#include "stack.h"
#include "save.h"

static Stack undoStack, redoStack;

void init() {
    initStack(&undoStack);
    initStack(&redoStack);
}

void push_undo(const char* text) {
    push(&undoStack, text);
}

void push_redo(const char* text) {
    push(&redoStack, text);
}

int undo_action(char* text) {
    return pop(&undoStack, text);
}

int redo_action(char* text) {
    return pop(&redoStack, text);
}

void save(const char* file, const char* text) {
    save_to_file(file, text);
}
