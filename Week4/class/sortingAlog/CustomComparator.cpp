#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! for vector

bool myComp(int &a, int &b)
{
    return a > b;
}

void print(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

//! For vector of a vector

bool myCompForFirstIndex(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

void printVV(vector<vector<int>> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> &temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout << a << " " << b << endl;
    }
    cout << endl;
}

int main()
{

    //? vector sorting with sort algo

    // vector<int> v = {44, 55, 22, 11, 33};
    // sort(v.begin(), v.end()); // increasing
    // print(v);
    // sort(v.begin(), v.end(), myComp); // decreasing
    // print(v);

    //? vector of vector sorting with sort algo

    vector<vector<int>> v;

    int n;
    cout << "Enter size : " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter a,b : " << endl;
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }

    cout << endl
         << "Here are the values : " << endl;
    printVV(v);

    cout << endl
         << "After Sorting : " << endl;
    sort(v.begin(), v.end(), myCompForFirstIndex);
    printVV(v);

    return 0;
}