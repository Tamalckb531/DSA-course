#include <iostream>
using namespace std;

class DequeCircular
{
private:
    int *arr;
    int n;
    int front;
    int rear;

public:
    DequeCircular(int size)
    {
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    }
    void pushFront(int val)
    {
        //? first to last full || front filled the rest of rear
        if ((front == 0 && rear == n - 1) || (rear == front - 1))
        {
            cout << "Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (front == 0 && rear != n - 1)
        {
            front = n - 1;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }
    void pushBack(int val)
    {
        //? first to last full || front filled the rest of rear
        if ((front == 0 && rear == n - 1) || (rear == front - 1))
        {
            cout << "Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (rear == n - 1 && front != 0)
        {
            //? circular nature
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void popFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == n - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = n - 1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    return 0;
}