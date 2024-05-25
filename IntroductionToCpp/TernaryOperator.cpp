#include <iostream>
using namespace std;

int main()
{
    cout << "Enter your age: " << endl;
    int age;
    cin >> age;

    age > 18 ? cout << "Can vote!" << endl : cout << "Can not vote!" << endl;
    return 0;
}