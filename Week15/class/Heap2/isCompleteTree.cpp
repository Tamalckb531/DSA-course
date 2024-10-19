#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution
{
public:
    bool solve(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool nullFound = false;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            if (front == NULL)
            {
                nullFound = true;
            }
            else
            {
                if (nullFound)
                    return false;
                q.push(front->left);
                q.push(front->right);
            }
        }

        return true;
    }
    bool isCompleteTree(TreeNode *root)
    {
        bool ans = solve(root);
        return ans;
    }
};