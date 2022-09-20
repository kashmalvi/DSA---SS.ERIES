//************************************************************************************
//**********	SINGLY CIRCULAR LINKED LIST - 1  **************if is circular list
//************************************************************************************
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

// inserting a node
void insertNode(Node *&tail, int element, int n)
{
    // assuming that element is present is present in list

    if (tail == NULL) // if list is empty
    {
        Node *newaNode = new Node(n);
        newaNode->next = newaNode;
        tail = newaNode;
    }
    else // non empty list
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found and current represent element wala node
        Node *temp = new Node(n);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// printing nodes in list
void print(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "\n List is empty" << endl;
        return;
    }
    cout << endl;
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << " ";
}

// function to check list is circulat or not
bool isCircular(Node *head)
{
    // for empty list
    if (head == NULL)
    {
        return 1;
    }

    // for non empty list
    Node *temp = head->next;
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

int main()
{
    system("cls");
    Node *tail = NULL;

    print(tail);
    // inseting element in empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5); // inserting element in list
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    // print the node in the list/

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
List is empty

3
3 5
3 5 7
 Linked list is circular
*/

//TC - O(n)
//SC - O(1)