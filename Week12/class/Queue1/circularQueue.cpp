#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int n;
    int front;
    int rear;

public:
    CircularQueue(int size)
    {
        n = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int val)
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
    void pop()
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
    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty";
            return -1;
        }
        return arr[front];
    }
    int getSize()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        else if (rear >= front)
        {
            return rear - front + 1;
        }
        return n - front + rear + 1;
    }
    int isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        return false;
    }
};

int main()
{
    return 0;
}