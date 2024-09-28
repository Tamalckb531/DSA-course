#include <bits/stdc++.h>
using namespace std;

//* Steps
// 1. Traverse the linkedList and return the tail of it which is before child or null
// 2. Whenever child found, do recursive call for the child
// 3. Get the child Tail and connect with the next node
// 4. Connect the node with the child
// 5. Make the child connection null.

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *solve(Node *head)
    {
        Node *it = head;
        Node *tail = it;

        while (it)
        {
            if (it->child)
            {
                Node *childTail = solve(it->child);

                //? step 1 : store the next of it
                Node *forward = it->next;

                //? step 2 : connect child with it
                it->next = it->child;
                it->child->prev = it;
                it->child = NULL;

                //? step 3 : connect child tail with forwardNode
                childTail->next = forward;
                if (forward)
                    forward->prev = childTail;
            }
            tail = it;
            it = it->next;
        }

        return tail;
    }

    Node *flatten(Node *head)
    {
        solve(head); //? it will return tail but it's not the result, as we need to count from the head.
        return head;
    }
};