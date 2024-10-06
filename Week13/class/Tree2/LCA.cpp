#include <iostream>
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

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //? base case:
        if (root == NULL)
            return NULL;
        if (root->val == p->val)
            return p;
        if (root->val == q->val)
            return q;

        //? recursive call
        TreeNode *leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightNode = lowestCommonAncestor(root->right, p, q);

        //? Processing
        if (leftNode == NULL && rightNode == NULL)
            return NULL;
        else if (leftNode != NULL && rightNode == NULL)
            return leftNode;
        else if (leftNode == NULL && rightNode != NULL)
            return rightNode;
        else
            return root; //? where both left and right are not NULL
    }
};