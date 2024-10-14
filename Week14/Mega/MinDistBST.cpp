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

class Solution
{
public:
    void solve(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;

        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }

    void solve2(TreeNode *root, TreeNode *&prev, int &ans)
    {
        if (!root)
            return;

        solve2(root->left, prev, ans);

        if (prev)
            ans = min(ans, root->val - prev->val);
        prev = root;

        solve2(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode *root)
    {
        // vector<int> inorder;
        // solve(root, inorder);

        // int minimum = INT_MAX;
        // int n = inorder.size();
        // for(int i=0; i<n; i++){
        //     if(i+1 < n){
        //         int diff = inorder[i+1] - inorder[i];
        //         minimum = min(minimum,diff);
        //     }
        // }

        // return minimum;

        TreeNode *prev = NULL;
        int ans = INT_MAX;
        solve2(root, prev, ans);
        return ans;
    }
};