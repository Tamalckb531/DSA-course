#include <iostream>
#include <string>
using namespace std;

//* compile time polymorphism

//? Function overloading

class Add
{
public:
    int sum(int x, int y)
    {
        return x + y;
    }
    int sum(int x, int y, int z)
    {
        return x + y + z;
    }
    double sum(double x, double y)
    {
        return x + y;
    }
};

//? operator overloading

class Complex
{
public:
    int real;
    int imag;

    Complex()
    {
        real = imag = -1;
    }

    Complex(int r, int i)
    {
        this->real = r;
        this->imag = i;
    }

    //? + overloading
    Complex operator+(const Complex &B)
    {
        // Here this will point A instance
        Complex temp;
        temp.real = this->real + B.real;
        temp.imag = this->imag + B.imag;
        return temp;
    }

    //? - overloading
    Complex operator-(const Complex &B)
    {
        // Here this will point A instance
        Complex temp;
        temp.real = this->real - B.real;
        temp.imag = this->imag - B.imag;
        return temp;
    }

    void print()
    {
        printf("[%d + i%d]\n", this->real, this->imag);
    }
};

//* run time polymorphism

class Shape
{
public:
    virtual void draw()
    {
        cout << "Generic drawing......" << endl;
    }
    void remove() final
    {
        cout << "Removing the drawing......" << endl;
    } //* this function can't be override in the children class for the final keyword
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Circle is drawing....." << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Rectangle is drawing....." << endl;
    }
};

void ShapeDrawing(Shape *s)
{
    s->draw();
}

int main()
{
    //? function overloading
    // int x = 5, y = 6, z = 2;
    // Add add;
    // cout << add.sum(x, y) << endl;
    // cout << add.sum(x, y, z) << endl;
    // cout << add.sum(5.4, 2.3) << endl;

    //? operator overloading
    // Complex A(2, 5);
    // A.print();
    // Complex B(7, 3);
    // B.print();

    // Complex C = A + B;
    // C.print();

    // Complex D = A - B;
    // D.print();

    //? run time polymorphism
    Circle c;
    Rectangle r;
    ShapeDrawing(&c);
    ShapeDrawing(&r);

    return 0;
}