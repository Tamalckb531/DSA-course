#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the value for Node : " << endl;
    int value;
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }
    else
    {
        Node *root = new Node(value);
        cout << "Adding left child for " << value << endl;
        root->left = createTree();
        cout << "Adding right child for " << value << endl;
        root->right = createTree();
        return root;
    }
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    //? NLR

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    //? LNR

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    //? LRN

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *ans = createTree();

    // preOrderTraversal(ans);
    // cout << endl;

    // inOrderTraversal(ans);
    // cout << endl;

    // postOrderTraversal(ans);
    // cout << endl;

    // 10 20 40 -1 -1 50 -1 80 -1 -1 30 60 -1 -1 70 90 -1 -1 -1

    // 10 50 40 -1 -1 -1 30 20 -1 -1 -1

    levelOrderTraversal(ans);
    cout << endl;
    return 0;
}
