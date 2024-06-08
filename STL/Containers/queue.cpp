#include <iostream>
#include <queue>

using namespace std;

int main()
{
    //? creation
    queue<int> q;

    //? push, pop and size
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);

    // q.pop();
    // q.pop();

    // cout << "Size : " << q.size() << endl;

    //? front and back
    // cout << "Front : " << q.front() << endl;
    // cout << "Back : " << q.back() << endl;

    //? Swap:
    queue<int> first;
    queue<int> second;

    first.push(10);
    first.push(20);

    second.push(100);
    second.push(200);

    first.swap(second);

    cout << first.front() << endl;
    cout << first.back() << endl;

    return 0;
}