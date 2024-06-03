#include <iostream>
#include <vector>
using namespace std;

void fun(int a[], int n)
{
    cout << "Array elements : " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print(vector<int> v)
{
    int size = v.size();
    if (size == 0)
    {
        cout << "No Item to print" << endl;
        return;
    }
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    //? static
    // int arr[5] = {1, 2, 3, 4, 5};
    // fun(arr, 5);

    //? dynamic
    // int n;
    // cin >> n;
    // int *arr = new int[n];

    // for (int i = 0; i < n; ++i)
    // {
    //     int data;
    //     cin >> data;
    //     arr[i] = data;
    // }

    // fun(arr, n);

    //? Vector
    vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // print(v);
    // v.pop_back();
    // v.pop_back();
    // print(v);
    // cout << "Capacity : " << v.capacity() << endl;
    // cout << "Capacity : " << v.size() << endl;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }

    print(v);

    cout << v.at(1) << endl;
    v.clear();
    print(v);
    return 0;
}