#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calPoints(vector<string> &operations)
{
    stack<int> st;
    int ans = 0;

    for (const string &op : operations)
    {
        if (op == "+")
        {
            int top = st.top();
            st.pop();
            int newTop = st.top() + top;
            st.push(top);
            st.push(newTop);
            ans += newTop;
        }
        else if (op == "D")
        {
            st.push(2 * st.top());
            ans += st.top();
        }
        else if (op == "C")
        {
            ans -= st.top();
            st.pop();
        }
        else
        {
            st.push(stoi(op));
            ans += st.top();
        }
    }

    return ans;
}

int main()
{
    cout << "LeetCode 682. Baseball Game" << endl;
}