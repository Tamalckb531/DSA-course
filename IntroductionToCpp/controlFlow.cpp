#include <iostream>
using namespace std;

int main()
{
    cout << "Hello from the control flow" << endl;

    int budget;
    cout << "Enter your budget : " << endl;
    cin >> budget;

    if (budget > 5000)
    {
        cout << "You have the budget" << endl;
    }
    else if (budget > 3000)
    {
        cout << "You can take loan" << endl;
    }
    else
    {
        cout << "Get the fuck outta here dwag !" << endl;
    }

    return 0;
}