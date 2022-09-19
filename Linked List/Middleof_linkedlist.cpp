//****************************************************************************
//**********	MIDDLE OF LINKED LIST	- OPTIMISED********************
//****************************************************************************
#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//traversing with two node to getmiddle node
Node* getmiddle(Node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    //2 node
    if(head->next->next == NULL)
    {
        return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast->next != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

//function to return middle node
Node* findMiddle(Node *head)
{
    return getmiddle(head);
}

//driver code
int main()
{
    system("cls");
    
    Node* head = NULL;
    //create a linked_list and insert some elements into it

    Node* middle = findMiddle(head);

    //print the linked_list

    return 0;
    getch();
}

//TC - O(n)
//SC - O(1)