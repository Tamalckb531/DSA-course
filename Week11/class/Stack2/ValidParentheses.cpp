#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    int size = s.length();

    for (int i = 0; i < size; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')' && !st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else if (ch == '}' && !st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else if (ch == ']' && !st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
        return true;
    return false;
}

int main()
{

    return 0;
}