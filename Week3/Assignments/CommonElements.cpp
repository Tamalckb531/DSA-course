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

int main()
{

    return 0;
}