#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printMiddleElem(stack<int> &s, int count)
{
    //? base case
    if (count == 0)
    {
        cout << "Middle element : " << s.top() << endl;
        return;
    }

    //? processing
    int topElement = s.top();
    s.pop();
    count--;

    //? recursion
    printMiddleElem(s, count);

    //? backtracking
    s.push(topElement);
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(35);
    s.push(40);
    s.push(45);
    s.push(50);

    int count = s.size() / 2;
    printMiddleElem(s, count);

    return 0;
}