#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getLength(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    int len = getLength(head);

    if (head == NULL || head->next == NULL || len < k)
    {
        return head;
    }

    ListNode *prev = NULL;
    ListNode *curr = head;
    int counter = 0;

    while (counter < k)
    {
        ListNode *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        counter++;
    }

    if (curr != NULL)
    {
        ListNode *RecursionHead = reverseKGroup(curr, k);
        head->next = RecursionHead;
    }

    return prev;
}

int main()
{
    return 0;
}