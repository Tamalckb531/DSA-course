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
    void createMapping(unordered_map<int, int> &valueToIndex, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            int element = inorder[i];
            int index = i;
            valueToIndex[element] = index;
        }
    }

    TreeNode *createTree(vector<int> &inorder, vector<int> &postorder, int size, int &postIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &valMap)
    {
        if (postIndex < 0)
            return NULL;
        if (inorderStart > inorderEnd)
            return NULL;

        int rootElem = postorder[postIndex--];
        TreeNode *root = new TreeNode(rootElem);
        int inorderRootIndex = valMap[rootElem];

        root->right = createTree(inorder, postorder, size, postIndex, inorderRootIndex + 1, inorderEnd, valMap);
        root->left = createTree(inorder, postorder, size, postIndex, inorderStart, inorderRootIndex - 1, valMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int size = inorder.size();
        int postIndex = size - 1;
        ;
        int inorderStart = 0;
        int inorderEnd = size - 1;

        unordered_map<int, int> valMap;
        createMapping(valMap, inorder);
        TreeNode *root = createTree(inorder, postorder, size, postIndex, inorderStart, inorderEnd, valMap);

        return root;
    }
};