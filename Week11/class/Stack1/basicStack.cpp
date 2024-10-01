#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        top = -1;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        arr[top] = -1;
        top--;
    }

    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "There is no value to at the top as stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void print()
    {
        cout << "Printing the stack : " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack s(5);

    s.print();

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();

    cout << s.getTop() << endl;

    s.pop();
    s.print();
    s.pop();
    s.print();

    cout << s.getSize() << endl;

    return 0;
}