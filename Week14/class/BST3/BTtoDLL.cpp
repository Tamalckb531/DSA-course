#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

class Solution
{
public:
    void solve(Node *root, Node *&head)
    {
        if (!root)
            return;

        //? RNL

        //*R
        solve(root->right, head);

        //*N -> point the right of root to the head -> point head left to root if head is not NULL -> update head to root
        root->right = head;
        if (head)
            head->left = root;
        head = root;

        //*L
        solve(root->left, head);
    }

    Node *bToDLL(Node *root)
    {
        Node *head = NULL;
        solve(root, head);
        return head;
    }
};