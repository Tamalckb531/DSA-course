#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseListHelper(ListNode *&prev, ListNode *&curr)
{
    //? base case
    if (curr == NULL)
    {
        return prev;
    }

    //? processsing

    ListNode *forward = curr->next;
    curr->next = prev;

    //? pointing
    prev = curr;
    curr = forward;

    //? recursive call
    return reverseListHelper(prev, curr);
}

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    ListNode *newHead = reverseListHelper(prev, curr);
    return newHead;
}

int main()
{
    return 0;
}