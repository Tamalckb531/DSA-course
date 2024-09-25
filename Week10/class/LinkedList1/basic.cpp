//? creation of Singly LinkedList

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

int getLen(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

void insertAtHead(int value, Node *&head, Node *&tail)
{
    //? Inserting the first Node
    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    //? LL is not empty
    else
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(int value, Node *&head, Node *&tail)
{
    //? Inserting the first Node
    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    //? LL is not empty
    else
    {
        Node *newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(int position, int value, Node *&head, Node *&tail)
{
    int len = getLen(head);

    if (position == 1)
    {
        insertAtHead(value, head, tail);
    }
    else if (len == position + 1)
    {
        insertAtTail(value, head, tail);
    }
    else
    {
        Node *temp = head;

        int point = 1;
        while (point != position - 1)
        {
            temp = temp->next;
            point++;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFormLL(int postion, Node *&head, Node *&tail)
{
    //? no node
    if (head == NULL && tail == NULL)
        return;
    //? Single node
    if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    //? multiple node inside LinkedList
    else
    {
        if (postion == 1)
        {
            Node *temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < postion - 1; i++)
            {
                temp = temp->next;
            }
            Node *nodeToDelete = temp->next;
            Node *forwardNode = nodeToDelete->next;
            temp->next = forwardNode;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            return;
        }
    }
}

int search(Node *&head, int target)
{
    Node *temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == target)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    //? dynamic memory allocation
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(40, head, tail);
    insertAtHead(50, head, tail);
    insertAtTail(5, head, tail);
    insertAtTail(0, head, tail);
    insertAtPosition(4, 35, head, tail);
    insertAtPosition(1, 1, head, tail);
    insertAtPosition(10, 60, head, tail);
    print(head);

    // int ans = search(head, 35);
    // cout << ans << endl;
    // ans = search(head, 45);
    // cout << ans << endl;

    // deleteFormLL(1, head, tail);
    deleteFormLL(10, head, tail);
    // deleteFormLL(5, head, tail);

    print(head);

    return 0;
}