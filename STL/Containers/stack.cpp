#include <iostream>
#include <stack>

using namespace std;

int main()
{

    //? Creation
    stack<int> st;

    //? push, pop, size
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // cout << st.size() << endl;

    st.pop();
    st.pop();

    // cout << st.size() << endl;

    //? top

    cout << st.top() << endl;

    return 0;
}