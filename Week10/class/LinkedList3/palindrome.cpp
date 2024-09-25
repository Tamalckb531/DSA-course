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
class Solution
{
public:
    ListNode *getMiddle(ListNode *head, ListNode *&middleNodeKaPrev)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                middleNodeKaPrev = slow;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode *reverseList(ListNode *&prev, ListNode *&curr)
    {
        while (curr != NULL)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            // LL is empty
            return true;
        }
        if (head->next == NULL)
        {
            // single node
            return true;
        }

        ListNode *firstHalfHead = head;
        ListNode *middleNodeKaPrev = NULL;
        ListNode *middleNode = getMiddle(head, middleNodeKaPrev);
        // break
        middleNodeKaPrev->next = NULL;

        ListNode *prev = NULL;
        ListNode *curr = middleNode;
        ListNode *secondHalfHead = reverseList(prev, curr);

        ListNode *temphead1 = firstHalfHead;
        ListNode *temphead2 = secondHalfHead;
        while (temphead1 != NULL)
        {
            if (temphead1->val != temphead2->val)
            {
                // not a palindrome
                return false;
            }
            else
            {
                temphead1 = temphead1->next;
                temphead2 = temphead2->next;
            }
        }
        return true;
    }
};