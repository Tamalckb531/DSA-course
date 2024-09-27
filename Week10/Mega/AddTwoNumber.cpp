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

ListNode *loopAns(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(-1);
    ListNode *it = ans;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        //? get the list value with safe check
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;

        //? get the digit and carry
        int sum = a + b + carry;
        int digit = sum % 10;
        carry = sum / 10;

        //? store it in ans with "it" pointer and move it to next
        it->next = new ListNode(digit);
        it = it->next;

        //? move the list value to next with safe check
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }

    //? final ans don't contain the initial -1
    ListNode *finalAns = ans->next;
    return finalAns;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    return loopAns(l1, l2);
}