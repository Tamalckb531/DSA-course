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

//? work with one element which left part is total sorted -> insert that element in the it's exact sorted place in the left part

void InsertionSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j]; //? shifting all the elements to right until we can put the key
            j--;
        }
        v[j + 1] = key;
    }
}

void InsertionSortPractice(vector<int> &v)
{
    int size = v.size();

    for (int i = 1; i < size; i++) //? outer loop work for targeting an element
    {
        int key = v[i]; //? targetted element that will be inserted in it's left part sorted way
        int j = i - 1;  //? for targeting left part

        while (j >= 0 && v[j] > key)
        {
            //? moving elements to right until we reach the exact place to insert key
            v[j + 1] = v[j];
            j--; //? this will one extra j-- on last iteration, so we will do j+1 while insertion
        }

        //? now insert the key to it's exact place
        v[j + 1] = key;
    }
}

int main()
{
    vector<int> v1 = {5, 4, 9, 8, 2};
    vector<int> v2 = {5, 4, 9, 8, 2};
    InsertionSort(v1);
    InsertionSortPractice(v2);
    print(v1);
    print(v2);
    return 0;
}