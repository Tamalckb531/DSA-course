#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
public:
    string name;
    string model;
    int noOfTyres;

public:
    void startEngine()
    {
        cout << "Engine is starting " << name << " " << model << endl;
    }

    void stopEngine()
    {
        cout << "Engine is stopping " << name << " " << model << endl;
    }
};

class Car : public Vehicle
{
public:
    int noOfDoors;
    string transmissionType;

    void startAc()
    {
        cout << "AC has started of " << name << endl;
    }
};

int main()
{
    return 0;
}