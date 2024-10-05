#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseInKGroup(queue<int> &q, int k, int count)
{
    if (count >= k)
    {
        stack<int> st;
        //? insert elem in stack
        for (int i = 0; i < k; i++)
        {
            int element = q.front();
            q.pop();

            st.push(element);
        }

        //? re-insert element in queue again
        for (int i = 0; i < k; i++)
        {
            int element = st.top();
            st.pop();

            q.push(element);
        }
        reverseInKGroup(q, k, count - k);
    }
    else
    {
        //? get each element and push them into the last
        for (int i = 0; i < count; i++)
        {
            int element = q.front();
            q.pop();

            q.push(element);
        }
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);

    int k = 3;
    int count = q.size();

    reverseInKGroup(q, k, count);

    //? print queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}