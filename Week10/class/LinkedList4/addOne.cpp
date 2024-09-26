#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverseList(Node *&head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    Node *addOne(Node *head)
    {
        //? step1: reverse list;
        head = reverseList(head);

        //? step2: add one
        int carry = 1;
        Node *temp = head;

        while (temp != NULL)
        {
            int sum = carry + temp->data;
            int digit = sum % 10;
            carry = sum / 10;

            temp->data = digit;

            if (temp->next == NULL && carry != 0)
            {
                Node *newNode = new Node(carry);
                newNode->next = NULL;

                temp->next = newNode;
                temp = newNode;
            }
            temp = temp->next;
        }

        //? step3: reverseList;
        head = reverseList(head);

        return head;
    }
};
