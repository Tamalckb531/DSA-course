#include <iostream>
#include <queue>
#include <queue>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
};

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;

        ListNode *head = NULL;
        ListNode *tail = NULL;

        int totalRows = lists.size();

        for (int row = 0; row < totalRows; row++)
        {
            ListNode *temp = lists[row];
            if (temp != NULL)
            {
                pq.push(temp);
            }
        }

        while (!pq.empty())
        {
            ListNode *front = pq.top();
            pq.pop();

            if (head == NULL && tail == NULL)
            {

                head = front;
                tail = front;
            }
            else
            {

                tail->next = front;
                tail = front;
            }

            if (tail->next != NULL)
            {
                pq.push(tail->next);
            }
        }
        return head;
    }
};