#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void prefixToInfix(char prefix[], char infix[]) {
    Stack stack;
    initialize(&stack);

    int length = strlen(prefix);
    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isalnum(ch)) {
            // Operand
            push(&stack, ch);
        } else if (isOperator(ch)) {
            // Operator
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);
            snprintf(infix + strlen(infix), MAX_SIZE - strlen(infix), "(%c%c%c)", operand1, ch, operand2);
            push(&stack, infix[strlen(infix) - 1]);
        }
    }

    if (!isEmpty(&stack)) {
        // Invalid prefix expression
        printf("Invalid prefix expression\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char prefix[MAX_SIZE];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    char infix[MAX_SIZE];
    infix[0] = '\0';

    prefixToInfix(prefix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
