#include <iostream>
#include <bits/stdc++.h>
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

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        arr[top--] = -1;
    }

    int getTop()
    {
        if (top == -1)
            return -1;
        return arr[top];
    }

    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void print()
    {
        cout << "Printing the array of this Stack : " << endl;
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
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(100);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << "The top elem: " << s.getTop() << endl;
    cout << "Size of stack: " << s.getSize() << endl;
    cout << "Is stack empty: " << s.isEmpty() << endl;
    s.print();
    return 0;
}

//? .push(), .size(), .top(), .pop(), .empty()

// class Stack
// {
// public:
//     int *arr;
//     int size;
//     int top;

//     Stack(int capacity)
//     {
//         arr = new int[capacity];
//         size = capacity;
//         top = -1;
//     }

//     void push(int val)
//     {
//         if (top == size - 1)
//         {
//             cout << "Stack overflow" << endl;
//             return;
//         }
//         arr[++top] = val;
//     }

//     void pop()
//     {
//         if (top == -1)
//         {
//             cout << "Stack underflow" << endl;
//             return;
//         }
//         arr[top--] = -1;
//     }

//     int getSize()
//     {
//         return top + 1;
//     }

//     bool isEmpty()
//     {
//         if (top == -1)
//             return true;
//         return false;
//     }

//     int getTop()
//     {
//         if (top == -1)
//         {
//             cout << "Stack is empty" << endl;
//             return -1;
//         }
//         return arr[top];
//     }

//     void print()
//     {
//         cout << "Printing Stack" << endl;
//         for (int i = 0; i < size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };
