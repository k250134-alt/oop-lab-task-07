#include <iostream>
#include<math.h>
using namespace std;

class Shape {
protected:
    string position, color;
    int borderThickness;

public:
    Shape(string p = "", string c = "", int b = 1) {
        position = p;
        color = c;
        borderThickness = b;
    }

    virtual void draw() {
        cout << "Drawing Shape\n";
    }

    virtual void calculateArea() {
        cout << "Area not defined\n";
    }

    virtual void calculatePerimeter() {
        cout << "Perimeter not defined\n";
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : Shape("Center", "Red", 1) {
        radius = r;
    }

    void draw() {
        cout << "Drawing Circle\n";
    }

    void calculateArea() {
        cout << "Area: " << 3.14 * radius * radius << endl;
    }

    void calculatePerimeter() {
        cout << "Perimeter: " << 2 * 3.14 * radius << endl;
    }
};

class Rectangle : public Shape {
private:
    float width, height;

public:
    Rectangle(float w, float h) : Shape("Top-Left", "Blue", 1) {
        width = w;
        height = h;
    }

    void draw() {
        cout << "Drawing Rectangle\n";
    }

    void calculateArea() {
        cout << "Area: " << width * height << endl;
    }

    void calculatePerimeter() {
        cout << "Perimeter: " << 2 * (width + height) << endl;
    }
};

class Triangle : public Shape {
private:
    float a, b, c;

public:
    Triangle(float x, float y, float z) : Shape("Points", "Green", 1) {
        a = x; b = y; c = z;
    }

    void draw() {
        cout << "Drawing Triangle\n";
    }

    void calculateArea() {
        float s = (a + b + c) / 2;
        cout << "Area: " << sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
    }

    void calculatePerimeter() {
        cout << "Perimeter: " << a + b + c << endl;
    }
};

class Polygon : public Shape {
private:
    int sides;
    float length;

public:
    Polygon(int s, float l) : Shape("Multiple", "Yellow", 1) {
        sides = s;
        length = l;
    }

    void draw() {
        cout << "Drawing Polygon\n";
    }

    void calculateArea() {
        cout << "Area formula depends on polygon\n";
    }

    void calculatePerimeter() {
        cout << "Perimeter: " << sides * length << endl;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 3);
    Triangle t(3, 4, 5);
    Polygon p(6, 2);

    c.draw(); c.calculateArea(); c.calculatePerimeter();
    cout << endl;

    r.draw(); r.calculateArea(); r.calculatePerimeter();
    cout << endl;

    t.draw(); t.calculateArea(); t.calculatePerimeter();
    cout << endl;

    p.draw(); p.calculateArea(); p.calculatePerimeter();

    return 0;
}
