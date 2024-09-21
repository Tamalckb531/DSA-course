#include <bits/stdc++.h>
using namespace std;

bool isMatchHelper(string &s, int si, string &p, int pi)
{
    //? base case

    //* out of bound case
    if (si == s.size() && pi == p.size())
    {
        return true;
    }
    if (si == s.size() && pi < p.size())
    {
        //? if all left are * than it's ok, other than that not okay
        while (pi < p.size())
        {
            if (p[pi] != '*')
                return false;
            pi++;
        }
        return true;
    }

    //? processing

    //* handling char and ?
    if (s[si] == p[pi] || '?' == p[pi])
    {
        return isMatchHelper(s, si + 1, p, pi + 1);
    }

    //* handling *
    if (p[pi] == '*')
    {
        bool notTakeStar = isMatchHelper(s, si, p, pi + 1);
        bool consumeChar = isMatchHelper(s, si + 1, p, pi);

        return notTakeStar || consumeChar;
    }

    return false; // nothing matched
}

bool isMatch(string s, string p)
{
    int si = 0;
    int pi = 0;

    return isMatchHelper(s, si, p, pi);
}