#include <iostream>
#include <queue>
using namespace std;
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int data, int rowIndex, int colIndex)
    {
        this->data = data;
        this->rowIndex = rowIndex;
        this->colIndex = colIndex;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<class Info *, vector<Info *>, compare> pq;
        vector<int> ans;

        int rowSize = arr.size();
        int colSize = arr[0].size();

        //? inserting all the element of first col of each row in the min heap
        for (int row = 0; row < rowSize; row++)
        {
            int data = arr[row][0];
            Info *element = new Info(data, row, 0);
            pq.push(element);
        }

        //? now compare and push the elements in the ans vector
        while (!pq.empty())
        {
            Info *front = pq.top(); //? will always return the min element as it is the min heap
            pq.pop();

            int frontData = front->data;
            int frontRow = front->rowIndex;
            int frontCol = front->colIndex;

            ans.push_back(frontData);

            if (frontCol + 1 < colSize)
            {
                int data = arr[frontRow][frontCol + 1];
                Info *element = new Info(data, frontRow, frontCol + 1);
                pq.push(element);
            }
        }

        return ans;
    }
};