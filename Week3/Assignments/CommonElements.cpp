#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> ans;
    set<int> st;
    int i, j, k;
    i = j = k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        // when three points have same element
        if (A[i] == B[j] && B[j] == C[k])
        {
            st.insert(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    for (auto element : st)
    {
        ans.push_back(element);
    }

    return ans;
}

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    int arr1Size = arr1.size();
    int arr2Size = arr2.size();
    int arr3Size = arr3.size();

    int arr1Index, arr2Index, arr3Index;
    arr1Index = arr2Index = arr3Index = 0;

    vector<int> ans;
    set<int> temp;

    while (arr1Index < arr1Size && arr2Index < arr2Size && arr3Index < arr3Size)
    {
        if (arr1[arr1Index] == arr2[arr2Index] && arr2[arr2Index] == arr3[arr3Index])
        {
            temp.insert(arr1[arr1Index]);
            arr1Index++;
            arr2Index++;
            arr3Index++;
        }
        else if (arr1[arr1Index] < arr2[arr2Index])
        {
            arr1Index++;
        }
        else if (arr2[arr2Index] < arr3[arr3Index])
        {
            arr2Index++;
        }
        else
        {
            arr3Index++;
        }
    }

    for (auto element : temp)
    {
        ans.push_back(element);
    }

    if (ans.empty())
    {
        ans.push_back(-1);
    }

    return ans;
}

int main()
{

    return 0;
}