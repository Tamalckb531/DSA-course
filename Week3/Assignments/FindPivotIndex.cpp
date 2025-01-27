#include <iostream>
#include <vector>
using namespace std;

int bruteforce(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {

        int lsum = 0;
        int rsum = 0;

        // find lsum excluding current index:
        for (int j = 0; j < i; j++)
        {
            lsum += nums[j];
        }

        // find rsum excluding current index:
        for (int j = i + 1; j < nums.size(); j++)
        {
            rsum += nums[j];
        }

        if (lsum == rsum)
            return i;
    }
}

int bruteForcePrac(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        int leftSum = 0;
        int rightSum = 0;

        //? counting left sum [0,i)
        for (int j = 0; j < i; j++)
        {
            leftSum += nums[j];
        }

        //? counting right sum [i+1,size)
        for (int j = i + 1; j < size; j++)
        {
            rightSum += nums[j];
        }

        //! can't take the i as the i can be potential pivot index and pivot index number can't be included

        //? condition of pivot index
        if (leftSum == rightSum)
            return i;
    }
}

int PrefixSum(vector<int> &nums)
{

    vector<int> lsum(nums.size(), 0);
    vector<int> rsum(nums.size(), 0);

    // storing the left sum
    for (int i = 1; i < nums.size(); i++)
    {
        lsum[i] = lsum[i - 1] + nums[i - 1];
    }

    // storing the right sum
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        rsum[i] = rsum[i + 1] + nums[i + 1];
    }

    // check pivot index
    for (int i = 0; i < nums.size(); i++)
    {
        if (lsum[i] == rsum[i])
            return i;
    }

    return -1;
}

int PrefixSumPrac(vector<int> &nums)
{
    vector<int> LSum(nums.size(), 0);
    vector<int> RSum(nums.size(), 0);

    //? for each index, store the sum of all other prev elements
    for (int i = 1; i < LSum.size(); i++)
    {
        LSum[i] = nums[i - 1] + LSum[i - 1];
    }

    //? for each index, store the sum of all other next elements
    for (int i = RSum.size() - 2; i >= 0; i++)
    {
        RSum[i] = nums[i + 1] + RSum[i + 1];
    }

    //? Now match if an index has same LSum and RSum
    for (int i = 0; i < nums.size(); i++)
    {
        if (LSum[i] == RSum[i])
            return i;
    }

    return -1;
}

int main()
{
    return 0;
}