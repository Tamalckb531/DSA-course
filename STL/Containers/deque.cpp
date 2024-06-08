#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //? creation
    deque<int> dq;

    //? push_back, push_front

    dq.push_back(300);
    dq.push_back(400);

    dq.push_front(200);
    dq.push_front(100);

    //? pop_back , pop_front

    // dq.pop_back();
    // dq.pop_front();

    //? front and back
    // cout << dq.front() << endl;
    // cout << dq.back() << endl;

    //? iterator, begin and end:
    deque<int>::iterator it = dq.begin();

    while (it != dq.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}