#include <iostream>
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
    int getMax(TreeNode *root)
    {
        if (!root)
            return -1;

        while (root->right != NULL)
        {
            root = root->right;
        }

        return root->val;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (!root)
            return NULL;

        if (root->val == key)
        {
            //? gonna delete something

            //? case 1:
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            //? case 2:
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *leftNode = root->left;
                root->left = NULL;
                delete root;
                return leftNode;
            }

            //? case 3:
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode *rightNode = root->right;
                root->right = NULL;
                delete root;
                return rightNode;
            }

            //?
            if (root->left != NULL && root->right != NULL)
            {
                //? take the just less value of root and replace it with root value
                int justLessVal = getMax(root->left);
                root->val = justLessVal;
                root->left = deleteNode(root->left, justLessVal);
                return root;
            }
        }
        else if (key < root->val)
        {
            //? go to the left
            root->left = deleteNode(root->left, key);
        }
        else
        {
            //? go to the right
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

int main()
{
    return 0;
}