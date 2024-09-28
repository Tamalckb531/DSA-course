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

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    //? step 1 : find the total number of node
    int numberOfNode = 0;
    ListNode *it = head;
    while (it)
    {
        numberOfNode++;
        it = it->next;
    }

    //? step 2 : find the part size with extraNode alignment
    int partSize = numberOfNode / k;
    int extraNodes = numberOfNode % k;

    //? step 3 : insert the nodes into a vector of ListNodes
    vector<ListNode *> ans(k, nullptr);
    it = head;
    for (int i = 0; i < k && it; i++)
    {
        ans[i] = it;
        int nodeToAdd = partSize + (extraNodes-- > 0 ? 1 : 0);
        for (int j = 1; j < nodeToAdd; j++)
        {
            it = it->next;
        }
        ListNode *nextNode = it->next;
        it->next = NULL;
        it = nextNode;
    }

    return ans;
}