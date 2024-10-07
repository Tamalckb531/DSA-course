#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    void leftNodeStore(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return; //? as we can't print leaf nodes in leftNodestore

        ans.push_back(root->data);

        if (root->left != NULL)
        {
            leftNodeStore(root->left, ans);
        }
        else
        {
            leftNodeStore(root->right, ans);
        }
    }

    void leafNodeStore(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            ans.push_back(root->data);

        leafNodeStore(root->left, ans);
        leafNodeStore(root->right, ans);
    }

    void rightNodeStore(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return; //? as we can't print leaf nodes in leftNodestore

        if (root->right != NULL)
        {
            rightNodeStore(root->right, ans);
        }
        else
        {
            rightNodeStore(root->left, ans);
        }

        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        //? Process Root Node first
        ans.push_back(root->data);

        //? Process left nodes without leaf
        leftNodeStore(root->left, ans);

        //? Process left leafnodes
        leafNodeStore(root->left, ans);

        //? Process right leafnodes
        leafNodeStore(root->right, ans);

        //? Process right nodes without leaf in reverse order
        rightNodeStore(root->right, ans);
    }
};