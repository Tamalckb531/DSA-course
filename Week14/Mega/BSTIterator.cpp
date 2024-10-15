#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class BSTIterator
{
    //? Take a stack and push all the left node on constructor calling -> whenever popping a node in the next function, push it's right and onward left nodes -> that's how we can implement a on calling inorder next function
public:
    stack<TreeNode *> st;
    void pushLeft(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    int next()
    {
        auto top = st.top();
        st.pop();

        if (top->right)
            pushLeft(top->right);

        return top->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */