#include <iostream>
#include <queue>
using namespace std;

int main()
{

    //! MAX_HEAP:

    //? creation
    priority_queue<int> pq;

    //? push, top

    pq.push(10);
    pq.push(210);
    pq.push(300);
    pq.push(40);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    //! MIN_HEAP:
    //? creation
    priority_queue<int, vector<int>, greater<int>> pq;

    return 0;
}