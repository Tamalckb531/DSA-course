#if !defined(BIRD_H)
#define BIRD_H

#include <iostream>
using namespace std;

//? This is pure virtual function

class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
};

class sparrow : public Bird
{
public:
    void eat()
    {
        cout << "Sparrow is eating\n";
    }
    void fly()
    {
        cout << "Sparrow is flying\n";
    }
};

class Eagle : public Bird
{
public:
    void eat()
    {
        cout << "Eagle is eating\n";
    }
    void fly()
    {
        cout << "Eagle is flying\n";
    }
};

#endif