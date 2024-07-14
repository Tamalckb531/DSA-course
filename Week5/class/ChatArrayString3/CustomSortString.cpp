#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string orderCopy;

bool compare(char a, char b)
{
    // true -> a will be placed before b
    // false -> b will be placed before a

    return (orderCopy.find(a) < orderCopy.find(b));
}

string customSortString(string order, string s)
{
    orderCopy = order;
    sort(s.begin(), s.end(), compare);
    return s;
}

int main()
{
    return 0;
}