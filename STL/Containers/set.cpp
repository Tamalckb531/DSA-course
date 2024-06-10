#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> st;
    st.insert(10);
    st.insert(8);
    st.insert(15);
    st.insert(4);
    st.insert(10);

    set<int>::iterator it = st.begin();

    while (it != st.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    //? find
    if (st.find(59) != st.end())
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}