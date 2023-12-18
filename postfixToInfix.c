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

void postfixToInfix(char postfix[], char infix[]) {
    Stack stack;
    initialize(&stack);

    int length = strlen(postfix);
    for (int i = 0; i < length; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            // Operand
            push(&stack, ch);
        } else if (isOperator(ch)) {
            // Operator
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);
            snprintf(infix + strlen(infix), MAX_SIZE - strlen(infix), "(%c%c%c)", operand1, ch, operand2);
            push(&stack, infix[strlen(infix) - 1]);
        }
    }

    if (!isEmpty(&stack)) {
        // Invalid postfix expression
        printf("Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    char infix[MAX_SIZE];
    infix[0] = '\0';

    postfixToInfix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
