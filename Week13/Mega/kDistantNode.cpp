#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    //? We need to go through left, right and parent to find the k distant nodes. We can go left and right but can't go to the parents. So we need a map for parent to traverse in the parent also.

    //? Create a map for parent mapping -> Now do level order traversal from target by a queue until the level is equal to the distance -> While doing level order traversal, keep traverse on the parent node also alongside with the left and right -> keep a visited array to mark nodes which will prevent parent-children infinite loop -> Create a vector, store all the queue element(after LOT, only the k distant node will be in the queue) and return it

    void mapping(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap)
    {
        if (!root)
            return;

        if (root->left)
        {
            parentMap[root->left] = root;
            mapping(root->left, parentMap);
        }

        if (root->right)
        {
            parentMap[root->right] = root;
            mapping(root->right, parentMap);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        //? Step 1 : create a map for parent mapping
        unordered_map<TreeNode *, TreeNode *> parentMap;
        parentMap[root] = nullptr;
        mapping(root, parentMap);

        //? Step 2 : LOT from target by a queue & keep tracking visited
        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> visited;
        q.push(target);
        visited[target] = true;

        int currentLevel = 0; // need it to track the level

        while (!q.empty())
        {
            int size = q.size();

            if (currentLevel == k)
                break;
            currentLevel++; //? as we need just the node for k distant, so we need to stop the queue after k times as it will store all the k distant nodes after it

            for (int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();

                //? left element insertion
                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = true;
                }

                //? right element insertion
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                }

                //? Step 3 : parent insertion
                auto parentNode = parentMap[front];
                if (parentNode && !visited[parentNode])
                {
                    q.push(parentNode);
                    visited[parentNode] = true;
                }
            }
        }

        //? Step 4: store all the queue element in an ans vector and return
        vector<int> ans;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            ans.push_back(front->val);
        }

        return ans;
    }
};