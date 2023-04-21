#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
        Node* front;
        Node* rear;
    public:
        Queue() {
            front = NULL;
            rear = NULL;
        }

        void enqueue(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            if (front == NULL && rear == NULL) {
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }

        void dequeue() {
            Node* temp = front;
            if (front == NULL) {
                cout << "Queue is empty." << endl;
                return;
            }
            if (front == rear) {
                front = rear = NULL;
            }
            else {
                front = front->next;
            }
            delete temp;
        }

        void display() {
            if (front == NULL) {
                cout << "Queue is empty." << endl;
                return;
            }
            Node* temp = front;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
