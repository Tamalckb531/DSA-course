#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int n;
    int front;
    int rear;

public:
    Queue(int size)
    {
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    }
    void push(int val)
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
    void pop()
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
    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
    int getSize()
    {
        if (front == -1 && rear == -1)
            return 0;
        return rear - front + 1;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;

        return false;
    }
};

int main()
{
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << q.getSize() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.pop();
    q.pop();
    cout << q.getSize() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.getSize() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.pop();
    return 0;
}