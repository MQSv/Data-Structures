#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct StackStruct {
    unsigned* elements;
    unsigned maxSize, top;
};

typedef struct StackStruct* Stack;

Stack createStack (unsigned stackSize) {
    Stack newStack = (Stack) malloc(sizeof(struct StackStruct));
    unsigned* vector = (unsigned*) malloc(stackSize * sizeof(unsigned));

    newStack -> elements = vector;
    newStack -> maxSize = stackSize;
    newStack -> top = 0;

    return newStack;
}

unsigned peek (Stack stack) {
    return stack -> elements[stack -> top];
}

void push (Stack stack, unsigned element) {
    if (stack -> top == stack -> maxSize) return;

    stack -> elements[stack -> top++] = element;
}

void pop (Stack stack) {
    if (stack -> top == 0) return;

    stack -> top--;
}

bool isEmpty (Stack stack) {
    return stack -> top == 0;
}

void printElements (Stack stack) {
    for (unsigned i = 0; i < stack -> top; i++)
        printf("%d ", stack -> elements[i]);
}

int main (void) {
    return 0;
}
