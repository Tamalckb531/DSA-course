#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
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
        head->prev = newNode;
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
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(int position, int value, Node *&head, Node *&tail)
{
    int len = getLen(head);
    if (position == 1)
    {
        insertAtHead(value, head, tail);
        return;
    }
    else if (position == len + 1)
    {
        insertAtTail(value, head, tail);
        return;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(value);
        Node *forwardNode = temp->next;

        newNode->prev = temp;
        temp->next = newNode;
        forwardNode->prev = newNode;
        newNode->next = forwardNode;
    }
}

void DeleteDLL(int postion, Node *&head, Node *&tail)
{

    if (head == NULL && tail == NULL)
    {
        cout << "No node to delete" << endl;
        return;
    }
    else if (head == tail)
    {
        //? only one node
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else if (postion == 1)
    {
        //? head node delete
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if (postion == getLen(head))
    {
        //? tail node delete
        Node *temp = tail;

        tail = tail->prev;
        tail->next = NULL;

        //? isolation
        temp->next = NULL;
        temp->prev = NULL;

        delete temp;
    }
    else
    {
        //? any other node delete
        Node *back = head;
        for (int i = 1; i < postion - 1; i++)
        {
            back = back->next;
        }
        Node *curr = back->next;
        Node *front = curr->next;

        back->next = front;
        front->prev = back;

        //? curr isolation
        curr->next = NULL;
        curr->prev = NULL;

        delete curr;
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

    cout << "NULL";
    while (temp != NULL)
    {
        cout << "<-" << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void printRev(Node *tail)
{
    Node *temp = tail;

    cout << "NULL";
    while (temp != NULL)
    {
        cout << "<-" << temp->data << "->";
        temp = temp->prev;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(50, head, tail);
    insertAtHead(40, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(10, head, tail);
    insertAtTail(60, head, tail);
    insertAtTail(70, head, tail);
    insertAtPosition(4, 35, head, tail);
    print(head);
    DeleteDLL(8, head, tail);
    // DeleteDLL(6, head, tail);
    print(head);

    int ans = search(head, 50);
    cout << ans << endl;

    return 0;
}