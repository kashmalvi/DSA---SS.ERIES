//****************************************************************************
//**********	DOUBLY CIRCULAR LINKED LIST	********************
//****************************************************************************
#include <iostream>
#include <conio.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *previous;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
    // destructor
    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "\n memory free for node " << val;
    }
};

// inserting node into list
void insertAttail(node *&tail, int value, int n)
{
    // if no node is present in the list
    if (tail == NULL)
    {
        node *temp = new node(n);
        temp->next = temp;
        temp->previous = temp;
        tail = temp;
        return;
    }
    // if single node is present in list
    else if (tail->next == tail || tail->previous == tail)
    {
        node *temp = new node(n);
        temp->next = tail;
        tail->previous = temp;
        temp->previous = tail;
        tail->next = temp;
    }

    // if more than one node is present in the list
    // inserting node after value
    else
    {
        node *temp = new node(n);
        node *prev = tail;
        node *curr = prev->next;

        while (prev->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        temp->next = prev->next;
        prev->next = temp;
        temp->previous = curr->previous;
        curr->previous = temp;
    }
}

// deleting a node
void deletingNode(node *&tail, int value)
{
    // if no node is present in list
    if (tail == NULL)
    {
        return;
    }
    else
    {
        node *prev = tail;
        node *curr = prev->next;
        while (prev->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->previous->next = curr;
        prev->next = NULL;
        curr->previous = prev->previous;
        prev->previous = NULL;
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == prev)
        {
            tail = curr;
        }
        delete prev;
    }
}

// print list
void print(node *&tail)
{
    cout << endl;
    // if list is empty
    if (tail == NULL)
    {
        cout << "\n Sorry the list is empty";
    }
    // if list having only one node
    else if (tail->next == tail || tail->previous == tail)
    {
        cout << tail->data << " ";
    }
    // if list contains more than one node
    else
    {
        node *temp = tail;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail);
    }
}

// driver code
int main()
{
    system("cls");
    node *tail = NULL;

    // insertion
    insertAttail(tail, 10, 10);
    print(tail);

    insertAttail(tail, 10, 12);
    print(tail);

    insertAttail(tail, 12, 14);
    print(tail);

    insertAttail(tail, 10, 11);
    print(tail);

    insertAttail(tail, 12, 13);
    print(tail);

    //deleting node
    deletingNode(tail, 12);
    print(tail);

    deletingNode(tail, 11);
    print(tail);

    deletingNode(tail, 10);
    print(tail);

    deletingNode(tail, 13);
    print(tail);

    deletingNode(tail, 14);
    print(tail);

    return 0;
    getch();
}

/*
output - 
10
10 12
10 12 14
10 11 12 14
10 11 12 13 14
 memory free for node 12
10 11 13 14
 memory free for node 11
10 13 14
 memory free for node 10
13 14
 memory free for node 13
14
 memory free for node 14

 Sorry the list is empty
*/