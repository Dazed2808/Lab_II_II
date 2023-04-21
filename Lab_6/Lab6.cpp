#include <iostream>
#include <vector>

using namespace std;

class MyVector {
public:
    vector<int> arr;

    // Вывод размера списка
    void GetSize() {
        cout << "Array size : " << arr.size() << endl;
    }

    // Удаление диапазона (3-4) элементов из середины последовательности
    void DeleteRange() {
        if (arr.size() >= 5) {
            arr.erase(arr.begin() + 2, arr.begin() + 4);
        } else {
            cout << "Array is too short to remove the range." << endl;
        }
    }

    // Удаление всех элементов списка
    void DeleteAll() {
        arr.clear();
    }

    // Проверить, если список пуст, то вывести соответствующее сообщение и заполнить список
    void CheckEmpty() {
        if (arr.empty()) {
            cout << "Array is empty." << endl;
            for (int i = 0; i < 10; i++) {
                arr.push_back((i+1)*19); // Добавляем элементы, кратные 19
            }
            cout << "Array is filled with elements that are multiples of 19." << endl;
        } else {
            cout << "Array is not empty." << endl;
        }
    }

    // Дополнение списка до исходного размера, добавив элементы к началу списка
    void AddToFront() {
        while (arr.size() < 12) {
            arr.insert(arr.begin(), 0); // Добавляем элементы в начало
        }
    }

    // Вывод размера списка
    void GetSizeAgain() {
        cout << "Array size after padding: " << arr.size() << endl;
    }

    // Вставка элемента перед 8-м элементом списка
    void InsertBefore8() {
        if (arr.size() >= 8) {
            arr.insert(arr.begin() + 7, 999); // Вставляем элемент перед 8-м
        } else {
            cout << "Array is too short to insert an element before the 8th." << endl;
        }
    }

    // Вставить пять одинаковых элементов перед 3-м элементом
    void InsertFiveBefore3() {
        if (arr.size() >= 3) {
            for (int i = 0; i < 5; i++) {
                arr.insert(arr.begin() + 2, 777); // Вставляем 5 элементов перед 3-м
            }
        } else {
            cout << "The list is too short to insert 5 items before the 3rd." << endl;
        }
    }

    // Удаление последнего элемента списка
    void DeleteLast() {
        if (!arr.empty()) {
            arr.pop_back();
        } else {
            cout << "Array is empty, the last element cannot be deleted." << endl;
        }
    }

    // Удаление первого элемента списка
    void DeleteFirst() {
        if (!arr.empty()) {
            arr.erase(arr.begin());
        } else {
            cout << "Array is empty, the first element cannot be deleted." << endl;
        }
    }
};

int main() {
    MyVector myVector;

    myVector.GetSize();
    myVector.DeleteRange();
    myVector.DeleteAll();
    myVector.CheckEmpty();
    myVector.AddToFront();
    myVector.GetSizeAgain();
    myVector.InsertBefore8();
    myVector.InsertFiveBefore3();
    myVector.DeleteLast();
    myVector.DeleteFirst();


    myVector.DeleteAll();
    
    return 0;
}