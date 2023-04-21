#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class Stack {
private:
    Node* top;  
public:
    
    Stack() {
        top = NULL;
    }

    
    void push(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    
    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;  
    int choice, x;

    do {
        cout << "1. Add element in stack" << endl;
        cout << "2. Remove an element from the stack" << endl;
        cout << "3. Output the elements of the stack" << endl;
        cout << "4. Quit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invailid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
