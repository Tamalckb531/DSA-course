#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        st.push(element);
    }

    while (!st.empty())
    {
        int element = st.top();
        st.pop();

        q.push(element);
    }
}

void reverseQueueRec(queue<int> &q)
{
    if (q.empty())
        return;

    int frontElement = q.front();
    q.pop();

    reverseQueueRec(q);

    q.push(frontElement);
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // reverseQueue(q);
    reverseQueueRec(q);

    //? print queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}