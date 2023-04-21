#include <iostream>
#include <string>
using namespace std;


struct Node {
    char data;
    Node* next;
};


void push(Node** top, char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}


char pop(Node** top) {
    if (*top == NULL) {
        cout << "Stack is empty!" << endl;
        return '\0';
    }
    char value = (*top)->data;
    Node* temp = *top;
    *top = (*top)->next;
    delete temp;
    return value;
}


bool checkBrackets(string expression) {
    Node* stackTop = NULL;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            push(&stackTop, '(');
        }
        else if (expression[i] == ')') {
            if (pop(&stackTop) != '(') {
                return false;
            }
        }
    }
    if (stackTop != NULL) {
        return false;
    }
    return true;
}

int main() {
    string expression;
    cout << "Enter a mathematical expression with parentheses: ";
    getline(cin, expression);
    if (checkBrackets(expression)) {
        cout << "Brackets are placed correctly!" << endl;
    }
    else {
        cout << "Brackets are placed incorrectly!" << endl;
    }
    return 0;
}
