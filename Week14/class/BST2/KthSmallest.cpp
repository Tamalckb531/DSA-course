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
    void solve(TreeNode *root, TreeNode *&ans, int k, int &count)
    {
        if (!root)
            return;

        solve(root->left, ans, k, count);
        count++;
        if (k == count)
            ans = root;
        solve(root->right, ans, k, count);
    }
    // void inorderTrav(TreeNode* root, vector<int>&inorder){
    //     if(!root) return;

    //     inorderTrav(root->left, inorder);
    //     inorder.push_back(root->val);
    //     inorderTrav(root->right, inorder);
    // }
    int kthSmallest(TreeNode *root, int k)
    {
        // vector<int> inorder;
        // inorderTrav(root,inorder);
        // return inorder[k-1];

        TreeNode *ans = NULL;
        int count = 0;
        solve(root, ans, k, count);
        return ans->val;
    }
};