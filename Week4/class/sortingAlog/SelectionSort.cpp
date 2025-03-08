#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> &v)
{
    int endIndex = v.size() - 1;

    // outer loop running 1 less time as it target smallest element and place it. So placing last element will place automatically
    for (int i = 0; i <= endIndex - 1; i++)
    {
        int minIndex = i;

        // inner loop don't count the first element or already placed element and run until end.
        for (int j = i + 1; j <= endIndex; j++)
        {
            if (v[j] < v[minIndex])
            {
                swap(v[j], v[minIndex]);
            }
        }
    }
}
void selectionSortPractice(vector<int> &v)
{
    int endIndex = v.size() - 1;
    for (int i = 0; i < endIndex; i++) //? this target each element from left to right -> no need for the last element as we sorting from left to right, right element will be automatically sorted
    {
        int currMinIndex = i; //? target the ith element first and later store the smaller to smallest element from the right part

        for (int j = i + 1; j <= endIndex; j++) //? target the right part of an element -> here we find the smallest element and put it in the currMinIndex
        {
            if (v[j] < v[currMinIndex])
            {
                swap(v[j], v[currMinIndex]);
            }
        }
    }
}

int main()
{
    vector<int> v1 = {5, 8, 4, 9, 3};
    vector<int> v2 = {5, 8, 4, 9, 3};
    selectionSort(v1);
    selectionSortPractice(v2);
    print(v1);
    print(v2);
    return 0;
}