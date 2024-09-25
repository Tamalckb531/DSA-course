#include <iostream>
using namespace std;

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