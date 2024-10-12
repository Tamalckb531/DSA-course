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
    //? get all value of Node in an inorder array -> traverse it from right and store the all right sum there -> update the Node with all the value stored in inorder array by inorder traversal(as we are inserting sorted).

    void inorderStore(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;

        inorderStore(root->left, inorder);
        inorder.push_back(root->val);
        inorderStore(root->right, inorder);
    }

    void updateNode(TreeNode *root, vector<int> &inorder, int &index)
    {
        if (!root)
            return;

        updateNode(root->left, inorder, index);
        root->val = inorder[index++];
        updateNode(root->right, inorder, index);
    }

    TreeNode *bstToGst(TreeNode *root)
    {

        //? Step 1 : store all the inorder value in an inorder array
        vector<int> inorder;
        inorderStore(root, inorder);

        //? Step 2: Store all right sum
        int n = inorder.size();
        for (int i = n - 2; i >= 0; i--)
        {
            inorder[i] = inorder[i] + inorder[i + 1];
        }

        //? Step 3: update the Node
        int index = 0;
        updateNode(root, inorder, index);

        return root;
    }
};