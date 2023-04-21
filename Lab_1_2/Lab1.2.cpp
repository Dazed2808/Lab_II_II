#include<iostream>
#include<cmath>

using namespace std;

class Point
{
private:
    double x, y;
public:
    Point(double _x = 0, double _y = 0)
    {
        x = _x; y = _y;
    }

    friend Point operator+(const Point& p1, const Point& p2) 
    {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }

    friend Point operator-(const Point& p1, const Point& p2) 
    {
        return Point(p1.x - p2.x, p1.y - p2.y);
    }

    friend Point operator*(const Point& p1, const Point& p2) 
    {
        return Point(p1.x * p2.x, p1.y * p2.y);
    }

    friend Point operator/(const Point& p1, const Point& p2) 
    {
        return Point(p1.x / p2.x, p1.y / p2.y);
    }

    void print() const
    {
        cout << "(" << x << " , " << y << ")" << endl;
    }
};


class GeomFigura
{
private:
    Point a, b, c;
public:
    GeomFigura(const Point& _a, const Point& _b, const Point& _c)
    {
        a = _a; b = _b; c = _c;
    }

    friend GeomFigura operator+(const GeomFigura& g1, double dx) 
    {
        Point dl(dx, 0.0);
        return GeomFigura(g1.a + dl, g1.b + dl, g1.c + dl);
    }

    friend GeomFigura operator+(const GeomFigura& g1, const Point& p1)
    {
        return GeomFigura(g1.a + p1, g1.b + p1, g1.c + p1);
    }

    friend GeomFigura operator*(const GeomFigura& g1, double scale)
    {
        return GeomFigura(g1.a * scale, g1.b * scale, g1.c * scale);
    }

    friend GeomFigura operator/(const GeomFigura& g1, double scale)
    {
        return GeomFigura(g1.a / scale, g1.b / scale, g1.c / scale);
    }

    void print()
    {
        cout << "Point 1: "; a.print();
        cout << "Point 2: "; b.print();
        cout << "Point 3: "; c.print();
    }
};


int main()
{
    double _x_, _y_, mv_x, mv_y;

    cout << "P1 x: "; cin >> _x_;
    cout << "P1 y: "; cin >> _y_;
    Point p1(_x_, _y_);

    cout << "P2 x: "; cin >> _x_;
    cout << "P2 y: "; cin >> _y_;
    Point p2(_x_, _y_);

    cout << "P3 x: "; cin >> _x_;
    cout << "P3 y: "; cin >> _y_;
    Point p3(_x_, _y_);

    GeomFigura fig(p1, p2, p3);

    cout << "Figura: ";
    fig.print();

    cout << "Enter move along x-axis: ";
    cin >> mv_x;

    cout << "Figure moved along x-axis by " << mv_x << ": ";
    (fig + mv_x).print();

    cout << "Move x: "; cin >> _x_;
    cout << "Move y: "; cin >> _y_;
    Point p4(_x_, _y_);

    cout << "Figure moved: s" << endl;
    (fig + p4).print();


    cout << "Scale: "; cin >> mv_y;
    cout << "Figure scaled: " << endl;
    (fig * mv_y).print();

    cout << "Degrees: "; cin >> mv_x;

    cout << "Figure rotated by " << mv_x << " degrees:" << endl;
    mv_x = 180 / mv_x;
    (fig * M_PI / mv_x).print();

    return 0;
}