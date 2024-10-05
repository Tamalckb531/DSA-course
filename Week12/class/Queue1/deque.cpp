#include <iostream>
using namespace std;

class Deque
{
private:
    int *arr;
    int n;
    int front;
    int rear;

public:
    Deque(int size)
    {
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    }
    void pushFront(int val)
    {
        if (front == 0)
        {
            cout << "Overflow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            //? first element insertion
            rear++;
            front++;
            arr[front] = val;
            return;
        }

        front--;
        arr[front] = val;
    }
    void pushBack(int val)
    {
        if (rear == n - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            //? first element insertion
            rear++;
            front++;
            arr[rear] = val;
            return;
        }

        rear++;
        arr[rear] = val;
    }
    void popFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        else if (front == rear)
        {
            //? single element left in the queue
            arr[rear] = -1;
            front = -1;
            rear = -1;
            return;
        }
        arr[front] = -1;
        front++;
    }
    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
            return;
        }
        arr[rear] = -1;
        rear--;
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
    Deque dq(5);

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40);
    dq.pushBack(50);
    dq.print();
    dq.popFront();
    dq.popFront();
    dq.popFront();
    dq.print();
    dq.pushFront(30);
    dq.pushFront(20);
    dq.pushFront(10);
    dq.print();

    return 0;
}