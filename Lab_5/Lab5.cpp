#include <iostream>
#include <cmath>

class GeometricFigure {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void printCoordinates() const = 0;
};

class Quadrilateral : public GeometricFigure {
protected:
    double sideA, sideB, sideC, sideD;

public:
    Quadrilateral(double a, double b, double c, double d)
        : sideA(a), sideB(b), sideC(c), sideD(d) {}

    double getPerimeter() const {
        return sideA + sideB + sideC + sideD;
    }
};

class Circle : public GeometricFigure {
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const{
        return M_PI * radius * radius;
    }

    double getPerimeter() const{
        return 2 * M_PI * radius;
    }

    void printCoordinates() const {
        std::cout << "Center: (0, 0)\nRadius: " << radius << '\n';
    }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(double a, double b) : Quadrilateral(a, b, a, b) {}

    double getArea() const {
        return sideA * sideB / 2;
    }

    void printCoordinates() const {
        std::cout << "Coordinates: (0, " << sideB / 2
                  << "), (" << sideA / 2 << ", 0), (0, " << -sideB / 2
                  << "), (" << -sideA / 2 << ", 0)\n";
    }
};

class Square : public Quadrilateral {
public:
    Square(double a) : Quadrilateral(a, a, a, a) {}

    double getArea() const {
        return sideA * sideA;
    }

    void printCoordinates() const {
        std::cout << "Coordinates: (" << -sideA / 2 << ", " << sideA / 2
                  << "), (" << sideA / 2 << ", " << sideA / 2
                  << "), (" << sideA / 2 << ", " << -sideA / 2
                  << "), (" << -sideA / 2 << ", " << -sideA / 2 << ")\n";
    }
};

int main() {
    GeometricFigure* shapes[] = {
        new Rhombus(4, 6),
        new Square(5),
        new Circle(3)
    };
    const int SHAPE_COUNT = sizeof(shapes) / sizeof(*shapes);

    for (int i = 0; i < SHAPE_COUNT; ++i) {
        std::cout << "Shape " << (i + 1) << '\n';
        std::cout << "Area: " << shapes[i]->getArea() << '\n';
        std::cout << "Perimeter: " << shapes[i]->getPerimeter() << '\n';
        std::cout << "Coordinates:\n";
        shapes[i]->printCoordinates();
        std::cout << '\n';
    }

    for (int i = 0; i < SHAPE_COUNT; ++i) {
        delete shapes[i];
    }

    return 0;
}