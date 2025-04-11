#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

Node *top = NULL;

void push(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = top;
    char data = temp->data;
    top = top->next;
    free(temp);
    return data;
}

char peek() {
    if (top == NULL) {
        return -1;
    }
    return top->data;
}

bool isEmpty() {
    return top == NULL;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return -1;
}

void reverse(char* expr) {
    int i = 0, j = strlen(expr) - 1;
    while (i < j) {
        char temp = expr[i];
        expr[i] = expr[j];
        expr[j] = temp;
        i++;
        j--;
    }
}

void infixtopostfix(char *infix, char *postfix) {
    int j = 0, i = 0;
    char symbol;
    while (infix[i] != '\0') {
        symbol = infix[i];
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
        else if (isOperator(symbol)) {
            while (!isEmpty() && peek() != '(' && 
                  ( precedence(peek()) > precedence(symbol) ||
                   (precedence(peek()) == precedence(symbol) && symbol != '^') ))
            {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        i++;
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void infixtoprefix(char *infix, char *prefix) {
    char revinfix[100], revpostfix[100];
    int i = 0, j = 0;
    strcpy(revinfix, infix);
    reverse(revinfix);
    for (int n = 0; revinfix[n] != '\0'; n++) {
        if (revinfix[n] == '(')
            revinfix[n] = ')';
        else if (revinfix[n] == ')')
            revinfix[n] = '(';
    }
    while (!isEmpty())
        pop();
        
    while (revinfix[i] != '\0') {
        char symbol = revinfix[i];
        if (isalnum(symbol)) {
            revpostfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (!isEmpty() && peek() != '(') {
                revpostfix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(symbol)) {
            while (!isEmpty() && peek() != '(' && 
                  ( precedence(peek()) > precedence(symbol) ||
                   (precedence(peek()) == precedence(symbol) && symbol == '^') ))
            {
                revpostfix[j++] = pop();
            }
            push(symbol);
        }
        i++;
    }
    while (!isEmpty()) {
        revpostfix[j++] = pop();
    }
    revpostfix[j] = '\0'; 
    reverse(revpostfix);
    strcpy(prefix, revpostfix);
}

int main() {
    char infix[100], prefix[100], postfix[100];
    printf("ENTER AN INFIX EXPRESSION\n");
    scanf("%s", infix);
    while (!isEmpty())
        pop();
    infixtoprefix(infix, prefix);
    printf("PREFIX EXPRESSION: %s \n", prefix);
    
    while (!isEmpty())
    pop();
    infixtopostfix(infix, postfix);
    printf("POSTFIX EXPRESSION: %s\n", postfix);
    
    return 0;
}
