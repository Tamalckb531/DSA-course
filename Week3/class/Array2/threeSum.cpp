#include <iostream>
#include <vector>
using namespace std;

void printThreeSum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << endl;
                }
            }
        }
    }
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    int s = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < s; j++)
            {
                if ((i != j) && (j != k) && (k != i) && (nums[i] + nums[j] + nums[k] == 0))
                {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int target = 60;

    printThreeSum(arr, n, target);

    return 0;
}