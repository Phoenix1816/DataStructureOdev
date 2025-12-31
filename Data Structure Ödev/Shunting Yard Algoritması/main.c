#include <stdio.h>
#include <ctype.h>   // isalnum
#include <string.h>

#define MAX 100

// --------- STACK TANIMI ---------
typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

// --------- ÖNCELÝK FONKSÝYONU ---------
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Operatör mü?
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// --------- SHUNTING YARD: INFIX -> POSTFIX ---------
void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    init(&s);
    int k = 0; // postfix index

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // Boþluklarý atla
        if (c == ' ' || c == '\t')
            continue;

        // Operand ise direk postfix'e ekle
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // '(' ise stack'e at
        else if (c == '(') {
            push(&s, c);
        }
        // ')' ise '(' görene kadar stack'i boþalt
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            // '(''i stack'ten at ama postfix'e EKLEME
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s);
            }
        }
        // Operatör ise
        else if (isOperator(c)) {
            // Stack'te daha yüksek veya eþit öncelikli operatör olduðu sürece postfix'e at
            // (Burada ^ operatörünü left-associative kabul ettik basitlik için)
            while (!isEmpty(&s) && isOperator(peek(&s)) &&
                   precedence(peek(&s)) >= precedence(c)) {
                postfix[k++] = pop(&s);
            }
            // Sonra yeni operatörü stack'e at
            push(&s, c);
        }
    }

    // Ýfade bitti, stack'te kalan operatörleri postfix'e at
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0'; // string sonu
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    // Örnek: (A+B)*C-D/E
    printf("Infix ifade gir (ör: (A+B)*C-D/E ) : ");
    fgets(infix, MAX, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}
