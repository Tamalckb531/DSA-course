#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        int result = 0;
        int sign = 1;
        int num = 0; // temp

        for (char ch : s)
        {
            if (ch >= '0' && ch <= '9')
                num = num * 10 + (ch - '0');
            else if (ch == '+')
            {
                result += sign * num;
                num = 0;

                sign = 1;
            }
            else if (ch == '-')
            {
                result += sign * num;
                num = 0;

                sign = -1;
            }
            else if (ch == '(')
            {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (ch == ')')
            {
                result += sign * num;
                num = 0;

                int sign = st.top();
                st.pop();
                result *= sign;
                result += st.top();
                st.pop();
                sign = 1;
            }
        }
        result += sign * num;
        return result;
    }
};