#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    TreeNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getLength(ListNode *&head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    TreeNode *solve(ListNode *&head, int n)
    {
        if (!head || n <= 0)
        {
            return NULL;
        }

        //? LNR

        //*L
        TreeNode *leftSubTree = solve(head, n / 2);
        TreeNode *root = new TreeNode(head->val);
        root->left = leftSubTree;

        //*N
        head = head->next;

        //*R
        TreeNode *rightSubTree = solve(head, n - n / 2 - 1);
        root->right = rightSubTree;

        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        int n = getLength(head);
        TreeNode *root = solve(head, n);
        return root;
    }
};