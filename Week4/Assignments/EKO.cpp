#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSol(vector<long long int> &trees, long long int m, long long int mid)
{
    long long int woodCollected = 0;
    long long int size = trees.size();
    for (long long int i = 0; i < size; i++)
    {
        if (trees[i] > mid)
        {
            woodCollected += trees[i] - mid;
        }
    }

    return woodCollected >= m;
}

long long int maxSawBladeHeight(vector<long long int> &trees, long long int m)
{
    long long int start, end, mid, ans = -1;
    start = 0;
    end = *max_element(trees.begin(), trees.end());
    mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossibleSol(trees, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    long long int n, m;
    cin >> n >> m;

    vector<long long int> trees;
    while (n--)
    {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }

    cout << maxSawBladeHeight(trees, m) << endl;

    return 0;
}