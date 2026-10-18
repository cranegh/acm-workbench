#include <iostream>

using namespace std;

class Shape {
public:
    virtual double GetArea() = 0;
};

class Rectangle : public Shape {
private:
    double len;
    double width;
public:
    Rectangle(double l, double w) : len(l), width(w) {}
    double GetArea() {
        return len * width;
    }
};

class Circle : public Shape {
private:
    double r;
    const double PI = 3.14;
public:
    Circle(double r) : r(r) {}
    double GetArea() {
        return PI * r * r;
    }
};

int main() {
    double l, w, r;

    if (cin >> l >> w) {
        Rectangle rect(l, w);
        cout << rect.GetArea() << endl;
    }

    if (cin >> r) {
        Circle circle(r);
        cout << circle.GetArea() << endl;
    }

    return 0;
}