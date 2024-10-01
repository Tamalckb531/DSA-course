#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//? traverse each element from right -> store the smaller than element stack top into ans -> push element in the stack for the it's left checks

void solve(vector<int> &arr, stack<int> &s, vector<int> &ans)
{
    int size = arr.size();

    for (int i = size - 1; i >= 0; i--)
    {
        int element = arr[i];

        while (s.top() > element)
        {
            s.pop();
        }

        ans.push_back(s.top());
        s.push(element);
    }
}

int main()
{
    vector<int> v;

    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    stack<int> s;
    s.push(-1);
    vector<int> ans;

    solve(v, s, ans);
    reverse(ans.begin(), ans.end());

    int size = ans.size();
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}