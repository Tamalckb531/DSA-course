#include <iostream>
using namespace std;

int main()
{
    cout << "Do while Loop" << endl;
    int i = 1;

    do
    {
        cout << i << " ";
        i++;
    } while (i <= 5);

    cout << endl
         << "Nested Loop" << endl;

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cout << "i: " << i << " j: " << j << endl;
        }
    }

    cout << endl;
    return 0;
}