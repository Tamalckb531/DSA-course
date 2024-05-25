#include <iostream>
using namespace std;

int main()
{
    cout << "Hello from the switch case statement!" << endl;

    char grade;

    cout << "Enter Your Grade : " << endl;
    cin >> grade;

    switch (grade)
    {
    case 'A':
        cout << "Your marks will be in range of 80-100";
        break;
    case 'B':
        cout << "Your marks will be in range of 50-59";
        break;
    case 'C':
        cout << "Your marks will be in range of 40-49";
        break;
    case 'D':
        cout << "Your marks will be in range of 33-40";
        break;

    default:
        cout << "Nigga you failed!";
        break;
    }

    return 0;
}