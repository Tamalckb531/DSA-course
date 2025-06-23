#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;
    char temp;

    while (start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    cout << "LeetCode 344. Reverse String" << endl;
}