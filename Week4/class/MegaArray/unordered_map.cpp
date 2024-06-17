#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> desk_map;

    desk_map[1] = 53;
    desk_map[2] = 54;
    desk_map[3] = 55;

    // iterate

    unordered_map<int, int>::iterator it;

    for (it = desk_map.begin(); it != desk_map.end(); it++)
    {
        int key = it->first;
        int value = it->second;
        cout << "Key: " << key << " Value: " << value << endl;
    }

    // for (auto it : desk_map)
    // {
    //     int key = it.first;
    //     int value = it.second;
    //     cout << "Key: " << key << " Value: " << value << endl;
    // }

    //? find
    int key = 2;
    if (desk_map.find(key) != desk_map.end())
    {
        // found
        int value = desk_map[key];
        cout << value << endl;
    }
    else
    {
        // not found
        cout << "Value not found" << endl;
    }

    cout << endl;

    //? deletion
    desk_map.erase(2);

    for (auto it : desk_map)
    {
        int key = it.first;
        int value = it.second;
        cout << "Key: " << key << " Value: " << value << endl;
    }

    return 0;
}