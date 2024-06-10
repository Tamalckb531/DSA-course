#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, string> table;

    table["bn"] = "Bangladesh";
    table.insert(make_pair("in", "India"));
    table.insert(make_pair("br", "Brazil"));
    table.insert(make_pair("np", "nepal"));

    // cout << table.at("bn") << endl;

    //? Iterator
    // unordered_map<string, string>::iterator it = table.begin();

    // while (it != table.end())
    // {
    //     pair<string, string> p = *it;
    //     cout << p.first << " " << p.second << endl;
    //     it++;
    // }

    if (table.find("in") != table.end())
    {
        cout << "Key found" << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }

    return 0;
}