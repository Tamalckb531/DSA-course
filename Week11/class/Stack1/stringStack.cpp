#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    string name = "TamalCkb";

    for (int i = 0; i < name.length(); i++)
    {
        char ch = name[i];
        s.push(ch);
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    cout << endl;

    return 0;
}