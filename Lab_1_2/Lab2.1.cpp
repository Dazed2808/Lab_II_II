#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;
public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        this->data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            this->data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                this->data[i][j] = 0;
            }
        }
    }
    
    Matrix(const Matrix& other) {
        this->rows = other.rows;
        this->cols = other.cols;
        this->data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            this->data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                this->data[i][j] = other.data[i][j];
            }
        }
    }
    
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
            this->rows = other.rows;
            this->cols = other.cols;
            this->data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                this->data[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    this->data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }
    
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
        Matrix result(lhs.rows, lhs.cols);
        for (int i = 0; i < lhs.rows; i++) {
            for (int j = 0; j < lhs.cols; j++) {
                result.data[i][j] = lhs.data[i][j] + rhs.data[i][j];
            }
        }
        return result;
    }
    
    friend Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
        Matrix result(lhs.rows, lhs.cols);
        for (int i = 0; i < lhs.rows; i++) {
            for (int j = 0; j < lhs.cols; j++) {
                result.data[i][j] = lhs.data[i][j] - rhs.data[i][j];
            }
        }
        return result;
    }
    
    friend Matrix operator+(const Matrix& lhs, int rhs) {
        Matrix result(lhs.rows, lhs.cols);
        for (int i = 0; i < lhs.rows; i++) {
            for (int j = 0; j < lhs.cols; j++) {
                result.data[i][j] = lhs.data[i][j] + rhs;
            }
        }
        return result;
    }
    friend Matrix operator+(int lhs, const Matrix& rhs) {
    return rhs + lhs;
    }
    
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
        cout << endl;
        }
    }

    void set(int i, int j, int value) {
        data[i][j] = value;
    }
};

int main() {
    Matrix m1(2, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);
    Matrix m2(2, 2);
    m2.set(0, 0, 5);
    m2.set(0, 1, 6);
    m2.set(1, 0, 7);
    m2.set(1, 1, 8);
    Matrix m3 = m1 + m2;
    Matrix m4 = m1 - m2;
    Matrix m5 = 2 + m2;
    Matrix m6 = m2 + 2;
    cout << "m1:" << endl;
    m1.print();
    cout << "m2:" << endl;
    m2.print();
    cout << "m1 + m2:" << endl;
    m3.print();
    cout << "m1 - m2:" << endl;
    m4.print();
    cout << "2 + m2:" << endl;
    m5.print();
    cout << "m2 + 2:" << endl;
    m6.print();
    return 0;
}

