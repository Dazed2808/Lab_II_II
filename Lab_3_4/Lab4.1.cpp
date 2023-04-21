#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};


class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    
    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;
    }

    
    void addNodeAtBeginning(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        if (tail == NULL) {
            tail = head;
        }
    }

    
    void addNodeAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    void addNodeInMiddle(int data, int position) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            int i = 1;
            while (i < position && current->next != NULL) {
                current = current->next;
                i++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    
    void deleteNodeAtBeginning() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            if (head == NULL) {
                tail = NULL;
            }
            delete temp;
        }
    }

    
    void deleteNodeAtEnd() {
        if (tail != NULL) {
            if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            } else {
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = NULL;
            }
        }
    }

    
    void deleteNodeInMiddle(int position) {
        if (head != NULL) {
            Node* current = head;
            Node* previous = NULL;
            int i = 1;
            while (i < position && current->next != NULL) {
                previous = current;
                current = current->next;
                       }
        if (i == position) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            if (current == tail) {
                tail = previous;
            }
            delete current;
        }
    }
}


void display() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
};

int main() {
    LinkedList list;
    int choice, data, position, n;
    do {
        cout << "1. Add a node to the top of the list" << endl;
        cout << "2. Add a node to the end of the list" << endl;
        cout << "3. Add a node to the middle of the list" << endl;
        cout << "4. Remove the node from the beginning of the list" << endl;
        cout << "5. Remove the node from the end of the list" << endl;
        cout << "6. Remove a node from the middle of the list" << endl;
        cout << "7. Display the list on the screen" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the node value: ";
                cin >> data;
                list.addNodeAtBeginning(data);
                break;
            case 2:
                cout << "Enter the node value: ";
                cin >> data;
                list.addNodeAtEnd(data);    
                break;
            case 3:
                cout << "Enter the node value:: ";
                cin >> data;
                cout << "Enter the position: ";
                cin >> position;
                list.addNodeInMiddle(data, position);
                break;
            case 4:
                list.deleteNodeAtBeginning();
                break;
            case 5:
                list.deleteNodeAtEnd();
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> position;
                list.deleteNodeInMiddle(position);
                break;
            case 7:
                list.display();
                break;
            case 0:
                break;
            default:
                cout << "Incorect choice" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}




