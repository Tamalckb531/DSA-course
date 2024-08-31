#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int convert(string time)
{
    int hour = stoi(time.substr(0, 2));
    int minitue = stoi(time.substr(3, 2));

    return hour * 60 + minitue;
}
int findMinDifference(vector<string> &timePoints)
{
    vector<int> HourToMinitue;

    //? STEP 1: convert all time into int minute
    for (auto time : timePoints)
        HourToMinitue.push_back(convert(time));

    //? STEP 2: Sort them -> adjacent two min finding method
    sort(HourToMinitue.begin(), HourToMinitue.end());

    //? STEP 3: Find the minimum distance
    int ans = INT_MAX;
    int size = HourToMinitue.size() - 1;
    for (int i = 0; i < size; i++)
    {
        ans = min(ans, HourToMinitue[i + 1] - HourToMinitue[i]);
    }

    //? (Special) STEP 4: Find the anti clockwise distance
    //* as the clock run in a circle, so the last and first element also have a distance anti-clockwise
    int lastDistance = 1440 + HourToMinitue[0] - HourToMinitue[size];
    ans = min(ans, lastDistance);

    return ans;
}

int main()
{
    return 0;
}