#include <iostream>
#include <vector>
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
    void getInorder(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;

        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
    bool checkTwoSum(vector<int> &inorder, int target)
    {
        int size = inorder.size();
        int start = 0;
        int end = size - 1;

        while (start < end)
        {
            int total = inorder[start] + inorder[end];
            if (total == target)
                return true;
            else if (total > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return false;
    }
    bool findTarget(TreeNode *root, int k)
    {
        //? get the inorder and store in a vector -> do two pointer approach to find if any two sum making the target
        vector<int> inorder;
        getInorder(root, inorder);
        bool ans = checkTwoSum(inorder, k);
        return ans;
    }
};