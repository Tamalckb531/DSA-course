#include <iostream>
#include <vector>
#include <unordered_map>
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
    //? In preorder, the first element is the root node. The next node is the root of left sub-tree and so on.
    //? In inorder, if we find the root node of preorder in that, the left part of root will be the left sub tree and right part will be the right sub tree

    //? STEPS : Take the preorder first node -> create a root -> find it's index in the inorder array -> call for it's left and right tree.

    void createMapping(unordered_map<int, int> &valueToIndex, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            int element = inorder[i];
            int index = i;
            valueToIndex[element] = index;
        }
    }

    TreeNode *createTree(vector<int> &preorder, vector<int> &inorder, int size, int inorderStart, int inorderEnd, int &preorderIndex, unordered_map<int, int> &valMap)
    {
        if (preorderIndex >= size)
            return NULL;
        if (inorderStart > inorderEnd)
            return NULL;

        //? Step 1 : Take the preorder first node and create root
        int rootElem = preorder[preorderIndex];
        preorderIndex++;
        TreeNode *root = new TreeNode(rootElem);

        //? Step 2 : Find it's index in the inorder array
        int inorderRootIndex = valMap[rootElem];

        //? Step 3 : Call for it's left and right tree
        root->left = createTree(preorder, inorder, size, inorderStart, inorderRootIndex - 1, preorderIndex, valMap);
        root->right = createTree(preorder, inorder, size, inorderRootIndex + 1, inorderEnd, preorderIndex, valMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int size = inorder.size();
        int inorderStart = 0;
        int inorderEnd = size - 1;
        int preorderIndex = 0;
        unordered_map<int, int> valMap;
        createMapping(valMap, inorder);

        TreeNode *root = createTree(preorder, inorder, size, inorderStart, inorderEnd, preorderIndex, valMap);
        return root;
    }
};