#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
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
    vector<int> bottomView(Node *root)
    {
        queue<pair<Node *, int>> q;
        // to maintain initial state
        q.push(make_pair(root, 0));
        unordered_map<int, Node *> distMap;
        int minDist = INT_MAX;
        int maxDist = INT_MIN;

        // rule-> left(-1), right(+1) in distance

        while (!q.empty())
        {

            pair<Node *, int> frontPair = q.front();
            q.pop();

            Node *frontNode = frontPair.first;
            int hd = frontPair.second;
            minDist = min(minDist, hd);
            maxDist = max(maxDist, hd);

            distMap[hd] = frontNode;

            // left child
            if (frontNode->left != NULL)
            {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            // right child
            if (frontNode->right != NULL)
            {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }

        vector<int> ans;
        for (int i = minDist; i <= maxDist; i++)
        {
            Node *temp = distMap[i];
            ans.push_back(temp->data);
        }
        return ans;
    }
};