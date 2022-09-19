//****************************************************************************
//**********	CIRCULAR SINGLY LINKED LIST 	********************
//****************************************************************************
#include <iostream>
#include <conio.h>
using namespace std;

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

    // destructor
    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "\n memory free for value " << val;
    }
};

// inserting a node
void insertNode(node *&tail, int element, int n)
{
    // assuming that element is present is present in list

    if (tail == NULL) // if list is empty
    {
        node *newaNode = new node(n);
        newaNode->next = newaNode;
        tail = newaNode;
    }
    else // non empty list
    {
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found and current represent element wala node
        node *temp = new node(n);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// printing nodes in list
void print(node *&tail)
{
    if(tail == NULL)
    {
        cout<<"\n List is empty"<<endl;
        return ;
    }
    cout<<endl;
    node *temp = tail; 
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << " ";
}

//deleting node
void deleteNode(node* &tail, int value)
{
    //for empty list
    if(tail == NULL)
    {
        cout<<"\n List is empty , please check again "<<endl;
        return ; 
    }
    else
    {
        //non empty case
        node* pre = tail;
        node* cur = pre->next;

        while(cur->data != value)
        {
            pre = cur;
            cur = cur->next;
        }

        pre->next = cur->next;

        //if one node is present in linked list
        if(cur == pre)
        {
            tail = NULL;
        }
        
        //if >=2 node in linked list
        else if(tail == cur)
        {
            tail = pre;
        }
        cur->next = NULL;
        delete cur;

    }
}
// driver code
int main()
{
    system("cls");
    node *tail = NULL;

    // inseting element in empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);//inserting element in list
    print(tail);
    
    insertNode(tail, 5, 7);
    print(tail);
    
    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 7, 9);
    print(tail);
    
    //deleting the node
    deleteNode(tail, 7);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
    
    deleteNode(tail, 9);
    print(tail);
    
    deleteNode(tail, 5);//if two element left in list
    print(tail);
    
    deleteNode(tail, 6);//if only one element present in list
    print(tail);

    return 0;
    getch();
}

/*
output - 
3
3 5
3 5 7
3 5 6 7
3 5 6 7 9
 memory free for value 7
3 5 6 9
 memory free for value 3
9 5 6
 memory free for value 9
6 5
 memory free for value 5
6
 memory free for value 6
 List is empty
*/