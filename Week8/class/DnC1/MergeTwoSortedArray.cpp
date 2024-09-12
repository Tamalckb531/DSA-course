#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(int arr[], int sizeArr, int brr[], int sizeBrr, vector<int> &ans)
{
    int i = 0; //? pointing the arr
    int j = 0; //? pointing the brr

    //? compare and push
    while (i < sizeArr && j < sizeBrr)
    {
        if (arr[i] < brr[j])
        {
            ans.push_back(arr[i]);
            i++;
        }
        else
        {
            ans.push_back(brr[j]);
            j++;
        }
    }

    //? extra element may remain in one of the array

    while (i < sizeArr)
    {
        ans.push_back(arr[i]);
        i++;
    }

    while (j < sizeBrr)
    {
        ans.push_back(brr[j]);
        j++;
    }

    return;
}

int main()
{
    int arr[] = {10, 30, 50, 70};
    int sizeArr = 4;

    int brr[] = {20, 40, 60, 80, 90, 100};
    int sizeBrr = 6;

    vector<int> ans;
    mergeSortedArrays(arr, sizeArr, brr, sizeBrr, ans);

    //? Printing ans
    for (int num : ans)
    {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}