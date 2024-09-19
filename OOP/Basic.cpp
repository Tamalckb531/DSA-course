#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    //? Parameterized constructor
    Student(int id, int age, string name, int numOfSub)
    {
        this->id = id;
        this->age = age;
        this->name = name;
        this->numOfSub = numOfSub;
    }

    //? copy constructor
    Student(const Student &srcObj) //? srcObj -> the instance we are copying from
    {
        this->id = srcObj.id;
        this->age = srcObj.age;
        this->name = srcObj.name;
        this->numOfSub = srcObj.numOfSub;
    }

    //? Attributes
    int id;
    int age;
    string name;
    int numOfSub;

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

    //? Destructor -> use to delete dynamicly allocated attributes to prevent memory leak
    ~Student()
    {
        cout << "Student Default destructor called" << endl;
    }
};

int main()
{

    // Student s1(1, 20, "Tamal", 5);
    // Student s2(2, 15, "Nilu", 4);
    // Student s3(3, 18, "Akash", 8);

    // Student s4 = s1; // copy

    // cout << s1.name << " " << s1.age << endl;
    // cout << s2.name << " " << s2.age << endl;
    // cout << s3.name << " " << s3.age << endl;
    // cout << s4.name << " " << s4.age << endl;

    // s1.sleep();
    // s2.study();
    // s3.bunk();
    // s4.bunk();

    //? Dynamic memory allocation
    Student *s1 = new Student(1, 20, "Dip", 7);
    cout << s1->name << endl;
    cout << s1->age << endl;
    s1->study();
    delete s1;

    return 0;
}