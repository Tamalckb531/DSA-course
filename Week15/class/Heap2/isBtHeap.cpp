#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    bool completeBT(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        bool nullFound = false;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            if (front == NULL)
            {
                nullFound = true;
            }
            else
            {
                if (nullFound)
                    return false;
                q.push(front->left);
                q.push(front->right);
            }
        }

        return true;
    }

    bool maxProperty(Node *root)
    {
        if (!root)
            return true;

        if (root->left == NULL && root->right == NULL)
            return true;

        bool leftAns = maxProperty(root->left);
        bool rightAns = maxProperty(root->right);

        bool leftOption = true;
        bool rightOption = true;

        if (root->left && root->data < root->left->data)
            leftOption = false;
        if (root->right && root->data < root->right->data)
            rightOption = false;

        bool currAns = leftOption && rightOption;

        return currAns && leftAns && rightAns;
    }

    bool isHeap(struct Node *tree)
    {
        bool isComplete = completeBT(tree);
        bool isMax = maxProperty(tree);

        return isComplete && isMax;
    }
};