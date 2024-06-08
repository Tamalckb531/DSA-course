#include <iostream>
#include <list>
using namespace std;

int main()
{
    //? creation
    // list<int> myList;

    //? push and pop
    // myList.push_back(10);
    // myList.push_back(20);
    // myList.push_back(30);

    // myList.push_front(40);
    // myList.push_front(50);
    // myList.push_front(50);
    // myList.push_front(60);
    // myList.push_front(70);

    // myList.pop_front();
    // myList.pop_back();

    //? front and back
    // cout << myList.front() << endl;
    // cout << myList.back() << endl;

    //? Iterator, begin and end, remove
    // cout << "before removing" << endl;
    // list<int>::iterator it = myList.begin();

    // while (it != myList.end())
    // {
    //     cout << *it << " ";
    //     it++;
    // }
    // cout << endl;

    // myList.remove(50);

    // cout << "after removing" << endl;
    // list<int>::iterator itt = myList.begin();

    // while (itt != myList.end())
    // {
    //     cout << *itt << " ";
    //     itt++;
    // }

    // cout << endl;

    //? swap
    list<int> first;
    first.push_back(10);
    first.push_back(20);
    first.push_back(30);
    // 10 -> 20 -> 30

    list<int> second;
    second.push_back(110);
    second.push_back(120);
    second.push_back(130);

    first.swap(second);

    list<int>::iterator it = first.begin();

    while (it != first.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    return 0;
}
