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

double bruteForcePractice(vector<int> &nums, int &k)
{
    int start = 0;
    int end = k - 1;
    int maxSum = INT_MIN;

    while (end < nums.size())
    {
        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum += nums[i];
        }
        maxSum = max(maxSum, sum);
        start++;
        end++;
    }

    double maxAvg = maxSum / (double)k;
    return maxAvg;
}

double slidingWindowPractice(vector<int> &nums, int &k)
{
    int start = 0;
    int end = k - 1;
    int maxSum;
    int compareSum = 0;

    for (int i = start; i <= end; i++)
    {
        compareSum += nums[i];
    }
    maxSum = compareSum;
    end++;

    while (end < nums.size())
    {
        compareSum = compareSum + nums[end] - nums[start];
        maxSum = max(maxSum, compareSum);
        start++;
        end++;
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