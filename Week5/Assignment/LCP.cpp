#include <string>
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans;
    int i = 0; // global index for string traversal

    while (true)
    {
        char str_ch = 0;
        for (auto str : strs)
        {

            // out of bound checking
            if (i >= str.length())
            {
                str_ch = 0;
                break;
            }

            // just started
            if (str_ch == 0)
            {
                str_ch = str[i];
            }
            else if (str_ch != str[i])
            { // for loop breaking
                str_ch = 0;
                break;
            }
        }

        // while loop breaking
        if (str_ch == 0)
            break;

        ans.push_back(str_ch);
        i++;
    }

    return ans;
}

int main()
{
    return 0;
}