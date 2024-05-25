#include <iostream>
using namespace std;

int main()
{
    cout << "This is Loop" << endl;

    for (int i = 0; i < 10; i++)
    {
        if (i == 6)
        {
            break;
        }

        if (i == 3)
        {
            continue;
        }
        cout << "This is inside for loop" << endl;
    }

    int j = 0;

    while (j < 5)
    {
        cout << "This is inside while loop" << endl;
        j++;
    }

    return 0;
}