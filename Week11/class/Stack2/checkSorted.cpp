#include <iostream>
#include <string>
#include <stack>
#include <climits>

using namespace std;

bool checkSort(stack<int> &s, int Elem1)
{
    if (s.empty())
        return true;

    int Elem2 = s.top();
    s.pop();

    if (Elem2 < Elem1)
    {
        bool recurAns = checkSort(s, Elem2);
        s.push(Elem2);
        return recurAns;
    }
    else
    {
        s.push(Elem2);
        return false;
    }
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(5);
    s.push(40);
    s.push(45);
    s.push(50);

    int Elem1 = INT_MAX;
    cout << checkSort(s, Elem1) << endl;

    return 0;
}