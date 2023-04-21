#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void addFront(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeFront() {
        if (head == NULL) {
            std::cout << "List is empty\n";
        }
        else if (head == tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void removeEnd() {
        if (tail == NULL) {
            std::cout << "List is empty\n";
        }
        else if (head == tail) {
            delete tail;
            head = tail = NULL;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    void print() const {
        if (head == NULL) {
            std::cout << "List is empty\n";
        }
        else {
            Node* current = head;
            while (current != NULL) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << '\n';
        }
    }

    ~DoublyLinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.addFront(10);
    list.addEnd(20);
    list.addFront(5);

    list.print();   

    list.removeFront();
    list.removeEnd();

    list.print();   

    return 0;
}