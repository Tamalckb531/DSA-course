#include <iostream>
#include <unordered_map>
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
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, bool> m;
        ListNode *temp = head;

        while (temp != NULL)
        {
            if (m[temp] == true)
            {
                return true;
            }
            else
            {
                m[temp] = true;
            }
            temp = temp->next;
        }

        return false;
    }
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && slow != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            else
            {
                return false;
            }
            if (slow == fast)
                return true;
        }

        return false;
    }
};

int main()
{
    return 0;
}