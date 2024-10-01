#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int value)
{

    if (s.empty())
    {
        s.push(value);
        return;
    }

    int topElem = s.top();
    s.pop();

    insertAtBottom(s, value);

    s.push(topElem);
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int value = 18;

    insertAtBottom(s, value);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}