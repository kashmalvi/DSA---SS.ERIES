//****************************************************************************
//**********	REVERSE THE LIST IN K-GROUP 	********************
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

// code to reverse the list in k-group
Node *kReverse(Node *head, int k)
{
    //base case
    if(head == NULL)
    {
        return NULL;
    }

    //1 - reverse the node first k-th term
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    int cnt = 0;
    while( curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr  = next;
        cnt++;
    }

    //2- recursive null
    if(next != NULL)
    {
         head->next = kReverse(next, k);
    }

    //return head of reverse list
    return prev;
}
int main()
{
    system("cls");

    Node* head = NULL;

    //insert the node

    //print the node in the list
    
    return 0;
    getch();
}

//TC - O(n)
//SC - O(n/k) or O(n)