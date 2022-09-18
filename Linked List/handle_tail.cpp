//****************************************************************************
//**********	DELETING LAST NODE OF LINKED-LIST	********************
//****************************************************************************
#include<iostream>
#include<conio.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        int val = this->data;
        if(this->next == NULL)
        {
            delete next; //node is made by next not by data
            cout<<"\n deleting the memory occupied by "<<val<<endl;
        }
        
    }
    
};

void insertAttail(node* &tail, int n)
{
    node* temp = new node(n);
    tail->next = temp;
    tail = temp;
}

void insertAthead(node* &head, int n)
{
    node* temp = new node(n);
    temp->next = head;
    head = temp;

}

void insertaAtposition(node* &head, node* &tail, int position, int n)
{
    if(position == 1)
    {
        insertAthead(head, n);
        return ;
    }

    node* temp = head;

    int i=1;
    while(i < position-1)
    {
        temp = temp->next;
        i++;
    }

    if(temp->next == NULL)
    {
        insertAttail(tail, n);
        return ;
    }

    node* nodeToinsert = new node(n);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

void deletenode(node* &head , node* &tail, int position)
{
    if(position == 1)
    {
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node* temp = head;
        int cnt = 1;
        node* previous;
        while( cnt < position)
        {
            previous = temp;
            temp = temp->next;
            cnt++;
        }

        if(temp->next == NULL) //this is the way to delete last node and also handle tail to last node of remaining linked-list
        {
            previous->next = NULL;
            tail = previous;
            delete temp;
            return ;
        }

        previous->next = temp->next;
        temp->next = NULL;
        delete temp;
        
    }
}

void print(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    system("cls");
    node* n1 = new node(10);
    node* head = n1;
    node* tail = n1;

    insertAthead(head, 12);   
    print(head); 

    cout<<endl;
    insertAttail(tail, 8);
    print(head); 

    cout<<endl;
    insertaAtposition(head, tail,4 , 1);
    print(head);

    deletenode(head,tail, 1);
    print(head);
    
    deletenode(head,tail, 3);
    print(head);

    cout<<"\nhead "<<head->data;
    cout<<"\ntail "<<tail->data;
    return 0;
    getch();
}

/*

output - 
12 10
12 10 8
12 10 8 1
 deleting the memory occupied by 12
10 8 1
 deleting the memory occupied by 1 
10 8
head 10
tail 8

*/