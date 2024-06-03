#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double bruteForce(vector<int> &nums, int &k)
{
    int maxSum = INT_MIN;
    int i = 0;
    int j = k - 1;

    while (j < nums.size())
    {
        int sum = 0;
        for (int y = i; y <= j; y++)
        {
            sum += nums[y];
        }
        maxSum = max(maxSum, sum);
        j++;
        i++;
    }

    double maxAvg = maxSum / (double)k;
    return maxAvg;
}

double slidingWindow(vector<int> &nums, int &k)
{
    int i = 0;
    int j = k - 1;
    int sum = 0;

    // initial sum
    for (int y = i; y <= j; y++)
    {
        sum += nums[y];
    }
    int maxSum = sum; //? For comparison
    j++;              //? For adding the next element in the next loop

    while (j < nums.size())
    {
        sum = sum - nums[i];       // removing first element
        sum = sum + nums[j];       // adding next element
        maxSum = max(maxSum, sum); // Getting the larger sum
        // sliding the window
        i++;
        j++;
    }

    double maxAvg = maxSum / (double)k;
    return maxAvg;
}

int main()
{
    return 0;
}