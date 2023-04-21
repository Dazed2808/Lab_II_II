/*#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    double price;
    Book* next;
};

class BookList {
private:
    Book* head;

public:
    BookList() {
        head = NULL;
    }

    ~BookList() {
        Book* current = head;
        while (current != NULL) {
            Book* next = current->next;
            delete current;
            current = next;
        }
    }

    void addBook(string title, string author, int year, double price) {
        Book* newBook = new Book;
        newBook->title = title;
        newBook->author = author;
        newBook->year = year;
        newBook->price = price;
        newBook->next = head;
        head = newBook;
    }

    void printAllBooks() {
        Book* current = head;
        while (current != NULL) {
            cout << "Title: " << current->title << endl;
            cout << "Author: " << current->author << endl;
            cout << "Year: " << current->year << endl;
            cout << "Price: " << current->price << endl;
            cout << endl;
            current = current->next;
        }
    }

    Book* searchByTitle(string title) {
        Book* current = head;
        while (current != NULL) {
            if (current->title == title) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    Book* searchByAuthor(string author) {
        Book* current = head;
        while (current != NULL) {
            if (current->author == author) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    Book* searchByYear(int year) {
        Book* current = head;
        while (current != NULL) {
            if (current->year == year) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    Book* searchByPrice(double price) {
        Book* current = head;
        while (current != NULL) {
            if (current->price == price) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    Book* searchByCriteria(string title, string author, int year, double price) {
        Book* current = head;
        while (current != NULL) {
            if (current->title == title && current->author == author && current->year == year && current->price == price) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    void insertBook(string title, string author, int year, double price, int position) {
        if (position == 0) {
            addBook(title, author, year, price);
            return;
        }

        Book* current = head;
        for (int i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) {
            return;
        }

        Book* newBook = new Book;
        newBook->title = title;
        newBook->author = author;
        newBook->year = year;
        newBook->price = price;
        newBook->next = current->next;
        current->next = newBook;
    }

    void deleteBook(Book* bookToDelete) {
        if (bookToDelete == head) {
            head = head->next;
            delete bookToDelete;
            return;
        }
        Book* current = head;
        while (current != NULL && current->next != bookToDelete) {
            current = current->next;
        }

        if (current == NULL) {
            return;
        }

        current->next = bookToDelete->next;
        delete bookToDelete;
    }

    void deleteByTitle(string title) {
        Book* bookToDelete = searchByTitle(title);
        if (bookToDelete != NULL) {
            deleteBook(bookToDelete);
        }
    }

    void deleteByAuthor(string author) {
        Book* bookToDelete = searchByAuthor(author);
        if (bookToDelete != NULL) {
            deleteBook(bookToDelete);
        }
    }

    void deleteByYear(int year) {
        Book* bookToDelete = searchByYear(year);
        if (bookToDelete != NULL) {
            deleteBook(bookToDelete);
        }
    }

    void deleteByPrice(double price) {
        Book* bookToDelete = searchByPrice(price);
        if (bookToDelete != NULL) {
            deleteBook(bookToDelete);
        }
    }
};

int main(){
    BookList book;
    bookList.addBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, 10.99);
    bookList.addBook("To Kill a Mockingbird", "Harper Lee", 1960, 9.99);
    bookList.addBook("1984", "George Orwell", 1949, 8.99);
    bookList.addBook("The Catcher in the Rye", "J.D. Salinger", 1951, 7.99);
    bookList.addBook("Pride and Prejudice", "Jane Austen", 1813, 6.99);

    cout << "All Books:" << endl;
    bookList.printAllBooks();
    cout << endl;

    Book* book = bookList.searchByTitle("1984");
    if (book != NULL) {
        cout << "Book found by title: " << book->title << endl;
        cout << endl;
    }

    book = bookList.searchByAuthor("Harper Lee");
    if (book != NULL) {
        cout << "Book found by author: " << book->title << endl;
        cout << endl;
    }

    book = bookList.searchByYear(1951);
    if (book != NULL) {
        cout << "Book found by year: " << book->title << endl;
        cout << endl;
    }

    book = bookList.searchByPrice(6.99);
    if (book != NULL) {
        cout << "Book found by price: " << book->title << endl;
        cout << endl;
    }

    book = bookList.searchByCriteria("Pride and Prejudice", "Jane Austen", 1813, 6.99);
    if (book != NULL) {
        cout << "Book found by criteria: " << book->title << endl;
        cout << endl;
    }

    bookList.insertBook("The Hobbit", "J.R.R. Tolkien", 1937, 12.99, 2);

    cout << "All Books after inserting The Hobbit at position 2:" << endl;
    bookList.printAllBooks();
    cout << endl;

    bookList.deleteByTitle("1984");

    cout << "All Books after deleting 1984:" << endl;
    bookList.printAllBooks();
    cout << endl;

    bookList.deleteByAuthor("F. Scott Fitzgerald");

    cout << "All Books after deleting F. Scott Fitzgerald:" << endl;
    bookList.printAllBooks();
    cout << endl;

    bookList.deleteByYear(1813);

    cout << "All Books after deleting 1813:" << endl;
    bookList.printAllBooks();
    cout << endl;

    bookList.deleteByPrice(10.99);

    cout << "All Books after deleting 10.99:" << endl;
    bookList.printAllBooks();
    cout << endl;

    return 0;


}*/
/*
#include <iostream>
#include <string>
using namespace std;

struct Book
{   
    int id;
    string title;
    string autor;
    int year;
    double price;
    Book* next;
};

class BookList
{
private:
    Book* head;
public:
    BookList()
    {
        head = nullptr;
    }

    ~BookList()
    {
        Book* temp = head;
        while (temp != nullptr)
        {
            Book* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
    
    void addBook(int id,string title, string autor, int year, double price)
    {
        Book* newBook = new Book();
        newBook->id = id;
        newBook->title = title;
        newBook->autor = autor;
        newBook->year = year;
        newBook->price = price;
        newBook->next = nullptr;

        if(head = nullptr)
        {
            head = newBook;
        }
        else
        {
            Book* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newBook;
        }
    }

    void display()
    {
        if(head == nullptr)
            cout << "No books in list" << endl;
        else{
            Book* temp = head;
            while (temp != nullptr)
            {
                cout << "ID: " << temp->id << endl;
                cout << "Title: " << temp->title << endl;
                cout << "Autor: " << temp->autor << endl;
                cout << "Year: " << temp->year << endl;
                cout << "Price: " << temp->price << endl;
                temp = temp->next;
            }  
        }
    }

    void searchById(int id)
    {
        Book* temp = head;
        while (temp != nullptr)
        {
            if (temp->id == id)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void searchByTitle(string title)
    {
        Book* temp = head;
        while (temp != nullptr)
        {
            if (temp->title == title)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void searchByAutor(string autor)
    {
        Book* temp = head;
        while (temp != nullptr)
        {
            if (temp->autor == autor)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void searchByYear(int year)
    {
        Book* temp = head;
        while (temp != nullptr)
        {
            if (temp->year == year)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void removeBookById(int id)
    {
        if(head == nullptr) return;

        if(head->id == id)
        {
            Book* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Book* temp = head;

        while (temp->next != nullptr)
        {
            if(temp->next->id == id)
            {
                Book* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }

    void removeBookByTitle(string title)
    {
        if(head == nullptr) return;

        if(head->title == title)
        {
            Book* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Book* temp = head;

        while (temp->next != nullptr)
        {
            if(temp->next->title == title)
            {
                Book* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }

    void removeBookByAutor(string autor)
    {
        if(head == nullptr) return;

        if(head->autor == autor)
        {
            Book* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Book* temp = head;

        while (temp->next != nullptr)
        {
            if(temp->next->autor == autor)
            {
                Book* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }

    void sortBookByTitle()
    {
        if(head == nullptr) return;
        bool swapped = true;

        while (swapped)
        {
            Book* temp = head;
            while (temp->next != nullptr)
            {
                if(temp->title > temp->next->title)
                {
                    swap(temp, temp->next);
                    swapped = true;
                }
                temp = temp->next;
            }
        }
    }

    void sortBookById()
    {
        if(head == nullptr) return;
        bool swapped = true;

        while (swapped)
        {
            Book* temp = head;
            while (temp->next != nullptr)
            {
                if(temp->id > temp->next->id)
                {
                    swap(temp, temp->next);
                    swapped = true;
                }
                temp = temp->next;
            }
        }
    }    

    void sortBookByYear()
    {
        if(head == nullptr) return;
        bool swapped = true;

        while (swapped)
        {
            Book* temp = head;
            while (temp->next != nullptr)
            {
                if(temp->year > temp->next->year)
                {
                    swap(temp, temp->next);
                    swapped = true;
                }
                temp = temp->next;
            }
        }
    }

private:
void swap(Book* a, Book* b)
{
    int id = a->id;
    string title = a->title;
    string autor = a->autor;
    int year = a->year;
    double price = a->price;

    a->id = b->id;
    a->title = b->title;
    a->autor = b->autor;
    a->year = b->year;
    a->price = b->price;

    b->id = id;
    b->title = title;
    b->autor = autor;
    b->year = year;
    b->price = price;
}
};

int main()
{
    BookList books;
    books.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald", 1925, 12.99);
    books.addBook(2, "To Kill a Mockingbird", "Harper Lee", 1960, 10.99);
    books.addBook(3, "Pride and Prejudice", "Jane Austen", 1813, 9.99);
    books.addBook(4, "1984", "George Orwell", 1949, 11.99);
    books.addBook(5, "Brave New World", "Aldous Huxley", 1932, 10.99);

    while (true)
    {
        cout << endl << "Please choose an action:" << endl;
        cout << "1. Display a books" << endl;
        cout << "2. Add a book" << endl;
        cout << "3. Remove by id" << endl;
        cout << "4. Remove by title" << endl;
        cout << "5. Sort by title" << endl;
        cout << "6. Sort by id" << endl;
        cout << "8. Find by id" << endl;
        cout << "9. Find by title" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            books.display();
            break;
        case 2:
            string title, author;
            int id,year;
            double price;
            cout << "Enter book id: ";
            cin >> id;
            cout << "Enter book title: ";
            cin >> title;
            cout << "Enter book author: ";
            cin >> author;
            cout << "Enter book year: ";
            cin >> year;
            cout << "Enter book price: ";
            cin >> price;
            books.addBook(id, title, author, year, price);
            break;
        case 3:
            int id;
            cout << "Enter book id: ";
            cin >> id;
            books.removeBookById(id);
            break;
        case 4:
            string title;
            cout << "Enter book title: ";
            cin >> title;
            books.removeBookByTitle(title);
            break;
        case 5:
            books.sortBookByTitle();
            break;
        case 6:
            books.sortBookById();
            break;
        case 7:
            break;
        case 8:
            int id;
            cout << "Enter book id: ";
            cin >> id;
            books.searchById();
            break;
        case 9:
            string title;
            cout << "Enter book title: ";
            cin >> title;
            books.searchByTitle();
            break;
        case 0:
            cout << "Exiting program";
            return 0;

        default:
            break;
        }
    }
}

*/



#include <iostream>
#include <string>

using namespace std;


struct Book {
    int id;
    string title;
    string author;
    int year;
    double price;
    Book* next;
};


class BookList {
private:
    Book* head;
    int size;

public:
    BookList() {
        head = NULL;
        size = 0;
    }

    
    void addBook(int id, string title, string author, int year, double price) {
        Book* newBook = new Book;
        newBook->id = id;
        newBook->title = title;
        newBook->author = author;
        newBook->year = year;
        newBook->price = price;
        newBook->next = NULL;
        if (head == NULL) {
            head = newBook;
        }
        else {
            Book* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newBook;
        }
        size++;
    }

    
    void displayList() {
        Book* current = head;
        while (current != NULL) {
            cout << "ID: " << current->id << endl;
            cout << "Title: " << current->title << endl;
            cout << "Author: " << current->author << endl;
            cout << "Year: " << current->year << endl;
            cout << "Price: " << current->price << endl;
            cout << endl;
            current = current->next;
        }
    }

    
    void searchBooksByAuthor(string author) {
        Book* current = head;
        while (current != NULL) {
            if (current->author == author) {
                cout << "ID: " << current->id << endl;
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "Year: " << current->year << endl;
                cout << "Price: " << current->price << endl;
                cout << endl;
            }
            current = current->next;
        }
    }

    
    void searchBooksByYear(int year) {
        Book* current = head;
        while (current != NULL) {
            if (current->year == year) {
                cout << "ID: " << current->id << endl;
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "Year: " << current->year << endl;
                cout << "Price: " << current->price << endl;
                cout << endl;
            }
            current = current->next;
        }
    }

    // Удаление книг по заданному критерию
    void deleteBooksByCriteria(double price) {
        Book* current = head;
        Book* prev = NULL;

        while (current != NULL) {
            if (current->price == price) {
                if (current == head) {
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                size--;
            }
            else {
                prev = current;
            }
            current = prev->next;
        }
    }

    
    void sortBooksByPriceAsc() {
        bool swapped = true;
        while (swapped) {
            swapped = false;
            Book* current = head;
            while (current != NULL && current->next != NULL) {
                if (current->price > current->next->price) {
                    
                    int tempId = current->id;
                    string tempTitle = current->title;
                    string tempAuthor = current->author;
                    int tempYear = current->year;
                    double tempPrice = current->price;

                    current->id = current->next->id;
                    current->title = current->next->title;
                    current->author = current->next->author;
                    current->year = current->next->year;
                    current->price = current->next->price;

                    current->next->id = tempId;
                    current->next->title = tempTitle;
                    current->next->author = tempAuthor;
                    current->next->year = tempYear;
                    current->next->price = tempPrice;

                    swapped = true;
                }
                current = current->next;
            }
        }
    }

    
    void insertBook(int pos, int id, string title, string author, int year, double price) {
        if (pos <= 0 || pos > size + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        Book* newBook = new Book;
        newBook->id = id;
        newBook->title = title;
        newBook->author = author;
        newBook->year = year;
        newBook->price = price;
        newBook->next = NULL;
        if (pos == 1) {
            newBook->next = head;
            head = newBook;
        }
        else {
            Book* current = head;
            for (int i = 1; i < pos - 1; i++) {
                current = current->next;
            }
            newBook->next = current->next;
            current->next = newBook;
        }
        size++;
    }
};

int main() {
    BookList bookList;
    bookList.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald", 1925, 10.50);
    bookList.addBook(2, "To Kill a Mockingbird", "Harper Lee", 1960, 8.99);
    bookList.addBook(3, "1984", "George Orwell", 1949, 12.95);
    bookList.addBook(4, "Pride and Prejudice", "Jane Austen", 1813, 7.99);
    bookList.addBook(5, "Animal Farm", "George Orwell", 1945, 9.99);
    bookList.addBook(6, "Brave New World", "Aldous Huxley", 1932, 11.25);

    int choice = 0;
    while (true) {
        cout << "Choose an action:" << endl;
        cout << "1. Add a new book to the list" << endl;
        cout << "2. Display the list of books" << endl;
        cout << "3. Search books by author" << endl;
        cout << "4. Search books by year" << endl;
        cout << "5. Delete books by criteria (price)" << endl;
        cout << "6. Sort books by price in ascending order" << endl;
        cout << "7. Insert a new book to the list at a given position" << endl;
        cout << "8. Exit" << endl;

        cin >> choice;

        if (choice == 1) {
            int id, year;
            double price;
            string title, author;
            cout << "Enter book ID: ";
            cin >> id;
            cout << "Enter book title: ";
            cin >> title;
            cout << "Enter book author: ";
            cin >> author;
            cout << "Enter book year: ";
            cin >> year;
            cout << "Enter book price: ";
            cin >> price;
            bookList.addBook(id, title, author, year, price);
        }
        else if (choice == 2) {
            bookList.displayList();
        }
        else if (choice == 3) {
            string author;
            cout << "Enter author name: ";
            cin >> author;
            bookList.searchBooksByAuthor(author);
        }
        else if (choice == 4) {
            int year;
            cout << "Enter year: ";
            cin >> year;
            bookList.searchBooksByYear(year);
        }
        else if (choice == 5) {
            double price;
            cout << "Enter price: ";
            cin >> price;
            bookList.deleteBooksByCriteria(price);
        }
        else if (choice == 6) {
            bookList.sortBooksByPriceAsc();
        }
        else if (choice == 7) {
            int pos, id, year;
            double price;
            string title, author;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter book ID: ";
            cin >> id;
            cout << "Enter book title: ";
            cin >> title;
            cout << "Enter book author: ";
            cin >> author;
            cout << "Enter book year: ";
            cin >> year;
            cout << "Enter book price: ";
            cin >> price;
            bookList.insertBook(pos, id, title, author, year, price);
        }
        else if (choice == 8) {
            break;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

return 0;
    /*
    while (true) {
        
        cout << "Choose an action:" << endl;
        cout << "1. Add a new book to the list" << endl;
        cout << "2. Display the list of books" << endl;
        cout << "3. Search books by author" << endl;
        cout << "4. Search books by year" << endl;
        cout << "5. Delete books by criteria (price)" << endl;
        cout << "6. Sort books by price in ascending order" << endl;
        cout << "7. Insert a new book to the list at a given position" << endl;
        cout << "8. Exit" << endl;

        cin >> choice;
        switch (choice)
        {
            case 1:
                int id, year;
                double price;
                string title, author;
                cout << "Enter book ID: ";
                cin >> id;
                cout << "Enter book title: ";
                cin >> title;
                cout << "Enter book author: ";
                cin >> author;
                cout << "Enter book year: ";
                cin >> year;
                cout << "Enter book price: ";
                cin >> price;
                bookList.addBook(id, title, author, year, price);
                break;
            case 2:
                bookList.displayList();
                break;
            case 3:
                string author;
                cout << "Enter author name: ";
                cin >> author;
                bookList.searchBooksByAuthor(author);
                break;
            case 4:
                int year;
                cout << "Enter year: ";
                cin >> year;
                bookList.searchBooksByYear(year);
            case 5:
                double price;
                cout << "Enter price: ";
                cin >> price;
                bookList.deleteBooksByCriteria(price);
                break;
            case 6:
                bookList.sortBooksByPriceAsc();
                break;
            case 7:
                int pos, id, year;
                double price;
                string title, author;
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter book ID: ";
                cin >> id;
                cout << "Enter book title: ";
                cin >> title;
                cout << "Enter book author: ";
                cin >> author;
                cout << "Enter book year: ";
                cin >> year;
                cout << "Enter book price: ";
                cin >> price;
                bookList.insertBook(pos, id, title, author, year, price);
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }*/
}