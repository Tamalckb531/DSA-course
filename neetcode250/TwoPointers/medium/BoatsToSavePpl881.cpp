#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int boat = 0;
    int left = 0;
    int right = people.size() - 1;

    while (left <= right)
    {
        int remain = limit - people[right--];
        boat++;
        //? One person is already on the boat. Now let's see if another can jump in. So we search in the left for less weight
        if (left <= right && remain >= people[left])
            left++; //? Put another person which is filled the at most two person condition
    }

    return boat;
}
int main()
{
    cout << "LeetCode 881. Boats to Save People" << endl;
}