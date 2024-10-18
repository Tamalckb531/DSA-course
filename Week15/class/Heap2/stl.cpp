#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //? max_heap
    // priority_queue<int> pq;
    // pq.push(10);
    // pq.push(5);
    // pq.push(30);
    // pq.push(15);

    // cout << pq.top() << endl;
    // pq.pop();
    // cout << pq.top() << endl;
    // pq.pop();
    // cout << pq.top() << endl;
    // pq.pop();
    // cout << pq.top() << endl;
    // pq.pop();

    //? min_heap
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(5);
    pq.push(30);
    pq.push(15);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();

    return 0;
}