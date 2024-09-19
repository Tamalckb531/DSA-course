#include <iostream>
#include <string>

using namespace std;

class Student
{

private:
    void keyPassPrinter()
    {
        cout << "Your key pass is : " << keyPass << endl;
    }

private:
    //? Attributes
    int id;
    int age;
    string name;
    int numOfSub;
    float *gpa;
    string keyPass;

public:
    //? Constructor
    Student(int id, int age, string name, int numOfSub, float gpa, string keyPass)
    {
        this->id = id;
        this->age = age;
        this->name = name;
        this->numOfSub = numOfSub;
        this->gpa = new float(gpa);
        this->keyPass = keyPass;
    }

    //? setter & getter
    void setGpa(float a)
    {
        *this->gpa = a;
    }
    float getGpa() const
    {
        return *this->gpa;
    }

    int getAge() const
    {
        return this->age;
    }

    //? Methods
    void study()
    {
        cout << this->name << " Pori loooooo!!!!!" << endl;
    }
    void sleep()
    {
        cout << this->name << " Ghumaaaa!!!!!" << endl;
    }
    void bunk()
    {
        cout << this->name << " Doura!!!!!" << endl;
    }

    //? Destructor
    ~Student()
    {
        delete this->gpa;
    }
};

int main()
{

    Student A(1, 20, "Tamal", 5, 3.45, "askdfj#%45654");

    cout << A.getAge() << endl;
    cout << A.getGpa() << endl;
    A.setGpa(3.5);
    cout << A.getGpa() << endl;

    return 0;
}