#include <iostream>
#include <vector>
using namespace std;

bool sameChar(string &ans, char newCh, int n)
{
    int init = ans.size() - 1;
    int limit = init - n;
    for (int it = init; it > limit; it--)
    {
        if (ans[it] != newCh)
            return false;
    }
    return true;
}

string removeDuplicates(string s, int k)
{
    string ans;

    for (auto newCh : s)
    {
        //? STEP 1: Enter k-1 element in the ans first
        if (ans.size() < k - 1)
        {
            ans.push_back(newCh);
        }
        //? STEP 2 : compare and push/pop
        else
        {
            if (sameChar(ans, newCh, k - 1))
            {
                for (int j = 1; j < k; j++)
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans.push_back(newCh);
            }
        }
    }

    return ans;
}
int main()
{
    return 0;
}
