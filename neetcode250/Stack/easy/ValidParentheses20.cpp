#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> parentheses;

    for (int i = 0; i < s.size(); i++)
    {
        if (parentheses.empty())
        {
            parentheses.push(s[i]);
        }
        else if ((s[i] == ')' && parentheses.top() == '(') ||
                 (s[i] == '}' && parentheses.top() == '{') ||
                 (s[i] == ']' && parentheses.top() == '['))
        {
            parentheses.pop();
        }
        else
        {
            parentheses.push(s[i]);
        }
    }

    return parentheses.empty();
}

int main()
{
    cout << "LeetCode 20. Valid Parentheses" << endl;
}