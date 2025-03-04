#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstRepeated(int arr[], int n)
{
    // code here
    unordered_map<int, int> hash; //<elementAsKey, countAsValue>

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] > 1)
            return i + 1;
    }

    return -1;
}

int firstRepeatedPractice(vector<int> &arr)
{
    // code here
    unordered_map<int, int> hash; //? <elementAsKey, occurrence>
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] > 1)
        {
            return i + 1;
        }
    }

    return -1;
}

int main()
{

    return 0;
}