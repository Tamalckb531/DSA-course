#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Two pointer: TC:O(n-k), SC:O(k) {we can ignore the k here cause it is for output vector}
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int left = 0;
    int right = arr.size() - 1;

    while (right - left + 1 > k)
    {
        if (abs(arr[left] - x) > abs(arr[right] - x))
            left++;
        else
            right--;
    }

    return vector<int>(arr.begin() + left, arr.begin() + right + 1);
}

int main()
{
    cout << "LeetCode 658. Find K Closest Elements" << endl;
}
