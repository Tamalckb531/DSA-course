#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int index;

    Heap(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        index = 0;

        //? will increase index while inserting
    }

    void printHeap()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int val)
    {
        if (index == capacity - 1)
        {
            cout << "Overflow" << endl;
            return;
        }

        index++;
        arr[index] = val;

        int currIndex = index;
        while (currIndex > 1)
        {
            int parentIndex = currIndex / 2;

            if (arr[parentIndex] < arr[currIndex])
            {
                swap(arr[parentIndex], arr[currIndex]);
                currIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void deleteFromHeap()
    {
        swap(arr[1], arr[index]);
        index--;
        // heapify(arr, index, 1);
    }
};

void heapify(int *arr, int n, int currIndex)
{
    int i = currIndex;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    int indexOfLargest = i;

    //? check for left

    if (leftIndex < n && arr[leftIndex] > arr[indexOfLargest])
    {
        indexOfLargest = leftIndex;
    }

    //? check for left

    if (rightIndex < n && arr[rightIndex] > arr[indexOfLargest])
    {
        indexOfLargest = rightIndex;
    }

    if (indexOfLargest != i)
    {
        swap(arr[i], arr[indexOfLargest]);
        i = indexOfLargest;
        heapify(arr, n, i);
    }
}

void buildHeap(int *arr, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int *arr, int n)
{
    int e = n - 1;
    while (e > 1)
    {
        swap(arr[1], arr[e]);
        e--;
        heapify(arr, e + 1, 1);
    }
}

int main()
{

    // Heap pq(10);

    int arr[] = {-1, 10, 20, 30, 40, 50};
    int n = 6;

    buildHeap(arr, n);
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // pq.insert(10);
    // pq.printHeap();
    // pq.insert(20);
    // pq.insert(30);
    // pq.insert(40);
    // pq.insert(35);
    // pq.printHeap();

    // pq.deleteFromHeap();
    // pq.printHeap();

    return 0;
}