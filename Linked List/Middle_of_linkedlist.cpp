//****************************************************************************
//**********	MIDDLE OF LINKED LIST	********************
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

//traversing the entire list
int getlength(Node* head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
//function to return middle node
Node* findMiddle(Node *head)
{
    int len = getlength(head);
    int ans = (len / 2);

    Node* temp = head;
    int cnt = 0;
    while(cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}
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