#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int value)
{
    //? base case
    if (s.empty())
    {
        s.push(value);
        return;
    }
    if (s.top() < value)
    {
        s.push(value);
        return;
    }

    //? processing and recursion

    int topElem = s.top();
    s.pop();

    sortedInsert(s, value);

    s.push(topElem);
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int value1 = 23;
    int value2 = 11;
    int value3 = 45;

    printStack(s);

    sortedInsert(s, value1);
    sortedInsert(s, value2);
    sortedInsert(s, value3);

    printStack(s);

    return 0;
}