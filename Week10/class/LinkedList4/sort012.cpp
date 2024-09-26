#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    };
};
class Solution
{
public:
    void insertAtTail(Node *&segregateNode, Node *&head, Node *&tail)
    {
        //? Fisrt node
        if (head == NULL && tail == NULL)
        {
            head = segregateNode;
            tail = segregateNode;
            return;
        }

        tail->next = segregateNode;
        tail = segregateNode;
        return;
    }

    Node *segregate(Node *head)
    {

        // Add code here
        Node *zeroHead = NULL;
        Node *zeroTail = NULL;

        Node *oneHead = NULL;
        Node *oneTail = NULL;

        Node *twoHead = NULL;
        Node *twoTail = NULL;

        Node *temp = head;

        while (temp != NULL)
        {

            //? Node segregation
            Node *segregateNode = temp;
            temp = temp->next;
            segregateNode->next = NULL;

            //? Node Insertion differently

            if (segregateNode->data == 0)
            {
                insertAtTail(segregateNode, zeroHead, zeroTail);
            }
            if (segregateNode->data == 1)
            {
                insertAtTail(segregateNode, oneHead, oneTail);
            }
            if (segregateNode->data == 2)
            {
                insertAtTail(segregateNode, twoHead, twoTail);
            }
        }

        //? Merge of Nodes
        if (zeroHead != NULL)
        {
            if (oneHead != NULL)
            {
                zeroTail->next = oneHead;
                oneTail->next = twoHead;
            }
            else
            {
                zeroTail->next = twoHead;
            }
            return zeroHead;
        }
        else
        {
            if (oneHead != NULL)
            {
                oneTail->next = twoHead;
                return oneHead;
            }
        }

        return twoHead;
    }
};
