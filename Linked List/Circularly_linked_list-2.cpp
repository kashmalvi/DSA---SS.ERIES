//*********************************************************************************************
//********** SINGLY CIRCULAR LINKED LIST - 2	*************** if is singly list
//*********************************************************************************************
#include <iostream>
#include <conio.h>
using namespace std;

// creating the node
class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// insert new node at head
void insertAthead(node *&head, int n)
{
    // create new node here
    node *temp = new node(n);
    temp->next = head;
    head = temp; // changing the head for each new node
}

// insert new node at tail
void insertAttail(node *&tail, int n)
{
    node *temp = new node(n);
    tail->next = temp;
    tail = temp;
}

// insert a node in between
void insertAtposition(node *&head, node *&tail, int position, int n)
{
    // if want to insert at first position
    if (position == 1)
    {
        insertAthead(head, n);
        return;
    }

    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAttail(tail, n);
        return;
    }

    // creating a node for n
    node *nodeToinsert = new node(n);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

// function to print the list of nodes
void print(node *&head)
{
    if (head == NULL)
    {
        cout<<"\n List is empty";
        return ;
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// function to check list is circulat or not
bool isCircular(node *head)
{
    // for empty list
    if (head == NULL)
    {
        return 1;
    }

    // for non empty list
    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return 1;
    }
    return 0;
}

// driver code
int main()
{
    system("cls");

    // created a new node
    node *n1 = new node(10); // creating node dynamically

    // head pointed to  node n1
    node *head = n1;

    // tail pointing to node n1
    node *tail = n1;

    print(head); // printing from node head

    insertAthead(head, 12);
    insertAthead(head, 15);
    print(head); // printing from head after insertion two element at head

    insertAttail(tail, 8);
    insertAttail(tail, 6);
    print(head); // printing from head after insertion two element at tail

    print(tail); // printing from tail after insertion two element at head

    insertAtposition(head, tail, 3, 11);
    print(head); // printing after inserting 11 at third position

    insertAtposition(head, tail, 1, 20);
    print(head); // printing after inserting 20 at first position position

    insertAtposition(head, tail, 8, 4);
    print(head); // printing after inserting 4 at last element with this function

    cout << "\nhead = " << head->data;
    cout << "\ntail = " << tail->data;

    if (isCircular(tail))
    {
        cout << "\n Linked list is circular ";
    }
    else
    {
        cout << "\n Linked list is not circular";
    }

    return 0;
    getch();
}

/*
output -
10
15 12 10
15 12 10 8 6       
6
15 12 11 10 8 6    
20 15 12 11 10 8 6 
20 15 12 11 10 8 6 4 

head = 20
tail = 4
 Linked list is not circular
*/

//TC - O(n)
//SC - O(1)