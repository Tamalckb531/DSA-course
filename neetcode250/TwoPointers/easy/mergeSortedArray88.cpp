#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int pt1 = m - 1;
    int pt2 = n - 1;
    int traverse = m + n - 1;

    if (m == 0)
        nums1 = nums2;

    while (traverse >= 0 && pt1 >= 0 && pt2 >= 0)
    {
        cout << "Loop 1 run" << endl;
        if (nums1[pt1] >= nums2[pt2])
            nums1[traverse--] = nums1[pt1--];
        else
            nums1[traverse--] = nums2[pt2--];
    }

    while (traverse >= 0 && pt1 >= 0)
    {
        cout << "Loop 2 run" << endl;
        nums1[traverse--] = nums1[pt1--];
    }

    while (traverse >= 0 && pt2 >= 0)
    {
        cout << "Loop 3 run" << endl;
        nums1[traverse--] = nums2[pt2--];
    }
}

int main()
{
    cout << "LeetCode 88. Merge Sorted Array" << endl;
}