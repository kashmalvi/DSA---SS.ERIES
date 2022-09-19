//************************************************************************************
//**********	REVERSE A LINKED LIST - RECURSIVELY	******************** CODE STUDIO
//**********************************************************************************
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

//recursively 
void reverse(Node* &head, Node* current, Node* previous )
{
    //base case
    if(current == NULL)
    {
        head = previous;
        return ;
    }

    //ek case solve karo
    Node* forward = current->next;
    reverse(head, forward, current);
    current->next = previous;
}


//function to reverse linked_list
Node* reverseLinkedList(Node *head)
{
    Node* previous = NULL;
    Node* current = head;
    reverse(head, current, previous);
    return head;
}

int main()
{
    system("cls");

    return 0;
    getch();
}

//TC - O(N)
//SC - O(n)

//h.w - reverse doubly