#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    string ans = "";
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        char currCharacter = s[i];
        if (ans.empty())
        {
            ans.push_back(currCharacter);
        }
        else if (currCharacter != ans.back())
        {
            ans.push_back(currCharacter);
        }
        else if (currCharacter == ans.back())
        {
            ans.pop_back();
        }
    }

    return ans;
}

int main()
{
    return 0;
}