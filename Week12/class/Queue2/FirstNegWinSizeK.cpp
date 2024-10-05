#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int k)
{

    vector<long long> ans;
    deque<long long int> storeIndex; //? use for storing the index of negetive number in a window

    //* handle the first window

    //? step1 : store the index of negetive number in the queue
    for (int i = 0; i < k; i++)
    {
        int element = A[i];

        if (element < 0)
        {
            storeIndex.push_back(i);
        }
    }

    //? store the first negetive element in the ans vector
    if (storeIndex.empty())
    {
        ans.push_back(0);
    }
    else
    {
        int index = storeIndex.front();
        int element = A[index];
        ans.push_back(element);
    }

    //? handle the rest
    for (int i = k; i < N; i++)
    {

        //? step1 : removal of prev first element index
        if (!storeIndex.empty() && storeIndex.front() < i - k + 1)
        {
            storeIndex.pop_front();
        }

        //? step2: addition of next element
        int element = A[i];
        if (element < 0)
        {
            storeIndex.push_back(i);
        }

        //! window shifted successfully

        //? step3: store the first negetive element of the window in ans
        if (storeIndex.empty())
        {
            ans.push_back(0);
        }
        else
        {
            int index = storeIndex.front();
            int element = A[index];
            ans.push_back(element);
        }
    }

    return ans;
}