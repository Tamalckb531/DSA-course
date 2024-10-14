#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Info
{
public:
    int minVal;
    int maxVal;
    int treeSum;
    bool isBst;
};
class Solution
{
public:
    Info solve(TreeNode *root, int &sum)
    {
        if (!root)
        {
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.treeSum = 0;
            temp.isBst = true;
            sum = max(sum, temp.treeSum);
            return temp;
        }
        if (root->left == NULL && root->right == NULL)
        {
            Info temp;
            temp.minVal = root->val;
            temp.maxVal = root->val;
            temp.treeSum = root->val;
            temp.isBst = true;
            sum = max(sum, temp.treeSum);
            return temp;
        }

        //?LRN
        Info LeftAns = solve(root->left, sum);
        Info RightAns = solve(root->right, sum);

        Info curr;

        curr.minVal = min(LeftAns.minVal, min(RightAns.minVal, root->val));
        curr.maxVal = max(LeftAns.maxVal, max(RightAns.maxVal, root->val));
        curr.treeSum = LeftAns.treeSum + RightAns.treeSum + root->val;
        if (LeftAns.isBst && RightAns.isBst && root->val > LeftAns.maxVal && root->val < RightAns.minVal)
        {
            curr.isBst = true;
            sum = max(sum, curr.treeSum);
        }
        else
        {
            curr.isBst = false;
        }

        return curr;
    }
    int maxSumBST(TreeNode *root)
    {
        int sum = 0;
        Info temp = solve(root, sum);
        return sum;
    }
};