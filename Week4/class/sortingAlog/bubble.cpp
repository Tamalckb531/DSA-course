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

void bubbleSort(vector<int> &v)
{
    int endIndex = v.size() - 1;

    for (int i = 0; i <= endIndex - 1; i++)
    {
        for (int j = 0; j <= endIndex - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void bubbleSortPractice(vector<int> &v)
{
    int endIndex = v.size() - 1;

    for (int i = 0; i < endIndex; i++)
    {
        for (int j = 0; j < endIndex - i; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

int main()
{
    vector<int> v1 = {55, 45, 82, 96, 12, 103, -10, 78, 54, -64, 3};
    vector<int> v2 = {55, 45, 82, 96, 12, 103, -10, 78, 54, -64, 3};
    bubbleSort(v1);
    bubbleSortPractice(v2);
    print(v1);
    print(v2);
    return 0;
}