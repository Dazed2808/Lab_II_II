#include <iostream>


class MyClass
{
private:
    double x, y, z;
public:
    MyClass(double _x = 0, double _y = 0, double _z = 0){
        x = _x; y = _y; z = _z;
    }

    MyClass operator+(const MyClass& other) const{
        return MyClass(x + other.x, y + other.y, z + other.z);
    }

    MyClass operator-(const MyClass& other) const{
        return MyClass(x - other.x, y - other.y, z - other.z);
    }

    MyClass operator-(const double& num) const{
        return MyClass(x - num, y - num, z - num);
    }

    MyClass operator+(const double& num) const{
        return MyClass(x + num, y + num, z + num);
    }

    MyClass operator/(const double& num) const{
        return MyClass(x / num, y / num, z / num);
    }

    MyClass operator*(const double& num) const{
        return MyClass(x * num, y * num, z * num);
    }

    MyClass operator++(){
        x++;y++;z++;
        return *this;
    }

    MyClass operator--(){
        --x;--y;--z;
        return *this;
    }

    void print(){
        std::cout << "( " << x << " , " << y << " , " << z << " )" << std::endl;
    }
};

int main(){
    double ob1_1, ob1_2, ob1_3, ob2_1, ob2_2, ob2_3, m;

    std::cout << "ob1_1 = "; std::cin >> ob1_1;
    std::cout << "ob1_2 = "; std::cin >> ob1_2;
    std::cout << "ob1_3 = "; std::cin >> ob1_3;

    std::cout << "ob2_1 = "; std::cin >> ob2_1;
    std::cout << "ob2_2 = "; std::cin >> ob2_2;
    std::cout << "ob3_2 = "; std::cin >> ob2_3;

    MyClass ob1(ob1_1, ob1_2, ob1_3);
    MyClass ob2(ob2_1, ob2_2, ob2_3);

    std:: cout << "m = "; std::cin >> m;

    std::cout << "ob1: ";
    ob1.print();

    std::cout << "ob2: ";
    ob2.print();

    std::cout << "ob1 + ob2: ";
    (ob1 + ob2).print();

    std::cout << "ob1 - ob2: ";
    (ob1 - ob2).print();

    std::cout << "ob1 - m: ";
    (ob1 - m).print();

    std::cout << "ob1 + m: ";
    (ob1 + m).print();

    std::cout << "ob1 / m: ";
    (ob1 / m).print();

    std::cout << "ob1 * m: ";
    (ob1 * m).print();

    std::cout << "ob1++: ";
    (++ob1).print();

    std::cout << "ob1--: ";
    (--ob1).print();

    return 0;
}
