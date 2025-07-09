#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;
    vector<int> index;

    while (left < right)
    {
        if (numbers[left] + numbers[right] == target)
        {
            index.push_back(left + 1);
            index.push_back(right + 1);
            return index;
        }
        else if (numbers[left] + numbers[right] > target)
            right--;
        else
            left++;
    }

    return index;
}

int main()
{
    cout << "LeetCode 167. Two Sum II - Input Array Is Sorted" << endl;
}