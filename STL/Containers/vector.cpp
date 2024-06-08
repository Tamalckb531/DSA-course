#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> marks;
    // vector<int> miles(10);
    // vector<int> distance(10, 5);

    //? begin and end

    // cout << *(distance.begin()) << endl;
    // cout << *(distance.end()) << endl;

    //? push, pop, front, back and size
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);

    // cout << "Size : " << marks.size() << endl;

    // marks.pop_back();
    // cout << "Size : " << marks.size() << endl;

    //? front, back, empty
    // cout << marks.front() << endl;
    // cout << marks.back() << endl;
    // cout << marks.empty() << endl;

    //? at, []

    // cout << marks.at(0) << endl;
    // marks.at(1) = 100;
    // cout << marks[1] << endl;

    //? Iterator :
    // vector<int>::iterator it = marks.begin();

    // while (it != marks.end())
    // {
    //     cout << *it << " ";
    //     it++;
    // }
    // cout << endl;

    //? 2D array
    vector<vector<int>> arr(5, vector<int>(4, 0));
    int totalRow = arr.size();
    int totalColumn = arr[0].size();

    //? jagged array
    vector<vector<int>> arr2(4); // 4 row

    arr2[0] = vector<int>(4);
    arr2[1] = vector<int>(2);
    arr2[2] = vector<int>(5);
    arr2[3] = vector<int>(3);

    int totalRowCount = arr2.size();

    return 0;
}