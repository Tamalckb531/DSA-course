#include <iostream>
using namespace std;

void printPermutation(string &str, int i)
{
    //? base case
    if (i >= str.length())
    {
        cout << str << endl;
        return;
    }

    //? processing
    for (int j = i; j < str.length(); j++)
    {
        swap(str[i], str[j]);
        printPermutation(str, i + 1);
        swap(str[j], str[i]); //? backtracking for pass by reference
    }
}

int main()
{
    string str = "abc";
    int i = 0;
    printPermutation(str, i);
    return 0;
}