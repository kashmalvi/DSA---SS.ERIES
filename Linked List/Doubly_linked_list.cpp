//**************************************************************************************************
//**********	DOUBLY LINKED LIST - CREATION, INSERTION, DELETION, TRAVERSE	****************
//**************************************************************************************************
#include <iostream>
#include <conio.h>
using namespace std;

class node
{
public:
    int data;
    node *next;     // to indicate next element
    node *previous; // to indicate previous element

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
        if (this->next != NULL) // condition to re-check whether next is pointing to NULL or not
        {
            delete next;
            this->next = NULL;
        }
        cout << "\n memory free for value " << val;
    }
};

// insert node at head
void insertAthead(node *&head, node* &tail, int n)
{
    if (head == NULL)
    {
        node* temp = new node(n);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(n);
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
}

// insert node at tail
void insertAttail(node* &tail, node* &head, int n)
{
    if (tail == NULL)
    {
        node* temp = new node(n);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(n);
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }
}

// insert at any position
void insertAtposition(node *&head, node *&tail, int position, int n)
{
    // if at first position
    if (position == 1)
    {
        insertAthead(head, tail, n);
        return;
    }

    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // if insertion at last position
    if (temp->next == NULL)
    {
        insertAttail(tail, head, n);
        return;
    }

    // insertion in between
    node *nodeToinsert = new node(n);
    nodeToinsert->next = temp->next;
    temp->next->previous = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->previous = temp;
}

// deleting a node
void deletingnode(node* &head, node *&tail, int position)
{
    // deleting starting node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next->previous = NULL;
        temp->next = NULL;
        delete temp;
        return ;
    }

    node* current = head;
    node* prev = NULL;
    
    int cnt = 1;
    while(cnt < position)
    {
        prev = current;
        current = current->next;
        cnt++;
    }

    if(current->next == NULL)
    {
        prev->next = NULL;
        tail = prev;
        delete current;
        return ;
    }
    prev->next = current->next;
    current->next = NULL;
    current->previous = NULL;
    delete current;
}

// traverse/print list
void print(node *&head, node *&tail)
{
    cout << endl
         << endl;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n head " << head->data;
    cout << "\n tail " << tail->data;
}

// driver code
int main()
{
    system("cls");
    // node *n1 = new node(10);

    //initially if we don't have any node in memory
    node *head = NULL;
    node *tail = NULL;

    insertAthead(head, tail, 12);
    print(head, tail);

    insertAttail(tail, head, 8);
    print(head, tail);

    insertAtposition(head, tail, 3, 6);
    print(head, tail);

    insertAtposition(head, tail, 2, 11);
    print(head, tail);

    insertAtposition(head, tail, 3, 9);
    print(head, tail);

    deletingnode(head, tail, 1);
    print(head, tail);
    
    deletingnode(head, tail, 4);
    print(head, tail);
    
    deletingnode(head, tail, 2);
    print(head, tail);
    
    deletingnode(head, tail, 2);
    print(head, tail);

    return 0;
    getch();
}

/*
output - 
12
 head 12    
 tail 12    

12 8        
 head 12    
 tail 8     

12 8 6      
 head 12    
 tail 6     

12 11 8 6   
 head 12    
 tail 6     

12 11 9 8 6 
 head 12
 tail 6
 memory free for value 12

11 9 8 6
 head 11
 tail 6
 memory free for value 6

11 9 8
 head 11
 tail 8
 memory free for value 9

11 8
 head 11
 tail 8
 
11
 head 11
 tail 11
*/