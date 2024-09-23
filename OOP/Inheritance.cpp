#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string name;
    string model;
    int noOfTyres;

public:
    //? constructor
    Vehicle(string _name, string _model, int _noOfTyres)
    {
        cout << "This is vehicle" << endl;
        this->name = _name;
        this->model = _model;
        this->noOfTyres = _noOfTyres;
    }
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
protected:
    int noOfDoors;
    string transmissionType;

public:
    //? constructor
    Car(string _name, string _model, int _noOfTyres, int _noOfDoors, string _transmissionType) : Vehicle(_name, _model, _noOfTyres)
    {
        cout << "This is car" << endl;
        this->noOfDoors = _noOfDoors;
        this->transmissionType = _transmissionType;
    }

    void startAc()
    {
        cout << "AC has started of " << name << endl;
    }
};

class MotorCycle : public Vehicle
{
protected:
    string handleBarStyle;
    string suspensionType;

public:
    MotorCycle(string _name, string _model, int _noOfTyres, string _handleBarStyle, string _suspensionType) : Vehicle(_name, _model, _noOfTyres)
    {
        cout << "This is motorcycle" << endl;
        this->handleBarStyle = _handleBarStyle;
        this->suspensionType = _suspensionType;
    }

    void wheelie()
    {
        cout << name << " doing wheelie" << endl;
    }
};

int main()
{
    Car A("Maruti 800", "LXI", 4, 4, "Manual");

    A.startEngine();
    A.startAc();
    A.stopEngine();

    MotorCycle M("BMW", "VXI", 2, "U", "Hard");
    M.startEngine();
    M.wheelie();
    M.stopEngine();
    return 0;
}