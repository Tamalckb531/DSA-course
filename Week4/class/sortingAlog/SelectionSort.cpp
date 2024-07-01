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

int main()
{
    vector<int> v = {55, 45, 82, 96, 12, 103, -10, 78, 54, -64, 3};
    selectionSort(v);
    print(v);
    return 0;
}