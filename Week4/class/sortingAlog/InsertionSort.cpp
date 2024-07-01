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

void InsertionSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main()
{
    vector<int> v = {55, 45, 82, 96, 12, 103, -10, 78, 54, -64, 3};
    // vector<int> v = {5, 4, 9, 8, 2};
    InsertionSort(v);
    print(v);
    return 0;
}