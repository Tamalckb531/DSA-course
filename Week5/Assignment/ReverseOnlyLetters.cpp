#include <iostream>
using namespace std;

string reverseOnlyLetters(string s)
{
    int low = 0;
    int high = s.length() - 1;

    while (low <= high)
    {
        if (isalpha(s[low]) && isalpha(s[high]))
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
        else if (!isalpha(s[low]))
        {
            low++;
        }
        else
        {
            high--;
        }
    }

    return s;
}

string reverseOnlyLetters(string s)
{
    int low = 0;
    int high = s.length() - 1;

    while (low <= high)
    {
        if (isalpha(s[low]) && isalpha(s[high]))
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
        else if (!isalpha(s[low]))
        {
            low++;
        }
        else
        {
            high--;
        }
    }

    return s;
}

int main()
{
    return 0;
}