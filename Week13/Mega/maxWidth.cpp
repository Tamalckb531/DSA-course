#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
    //? We can declare level of each node -> on each level we can find the rightmost and leftmost diff -> max of the diff will be the width
    //? Somethings to note : node left index = node index * 2 , node right index = node index * 2  + 1.
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        unsigned long long maxWidth = 0;

        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 1}); // first node with it's index inserted

        while (!q.empty())
        {
            //? processing for maxWidth in each level
            unsigned long long size = q.size();
            unsigned long long leftMostIndex = q.front().second;
            unsigned long long rightMostIndex = q.back().second;
            unsigned long long IndexDiff = rightMostIndex - leftMostIndex + 1;
            maxWidth = max(maxWidth, IndexDiff);

            //? Traversing to create the next level
            for (unsigned long long i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                auto node = front.first;
                unsigned long long index = front.second;

                if (node->left != NULL)
                {
                    q.push({node->left, 2 * index});
                }
                if (node->right != NULL)
                {
                    q.push({node->right, 2 * index + 1});
                }
            }
        }
        return maxWidth;
    }
};