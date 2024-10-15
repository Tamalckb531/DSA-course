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
//? Do inorder traversal for sorted order -> check if any two element breaking the order -> The two breaking the order, make the first one FV(First Violence) and second one SV(Second Violence) -> Now don't update the first violence and keep traversing for the end of second violence as the element to swap can be non-adjacent -> After whole traverse, swap the FV and SV
class Solution
{
    TreeNode *FV = NULL;
    TreeNode *SV = NULL;
    TreeNode *prev = NULL;

public:
    void solve(TreeNode *curr)
    {
        if (!curr)
            return;

        solve(curr->left);

        if (prev && curr->val < prev->val)
        {
            if (!FV)
                FV = prev;
            SV = curr;
        }
        prev = curr;

        solve(curr->right);
    }
    void recoverTree(TreeNode *root)
    {
        solve(root);
        if (FV && SV)
        {
            swap(FV->val, SV->val);
        }
    }
};