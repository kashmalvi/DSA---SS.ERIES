//****************************************************************************
//**********	MERGE TWO SORTED LINKED LIST	********************
//****************************************************************************
#include<iostream>
#include<conio.h>
using namespace std;

//************************************************************    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

//************************************************************/
Node<int>* solve(Node<int>* first, Node<int>* second)
{
    //if only one element present in the list
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }

    //if more than one element present in the list
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL)
    {
        if(curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            //add nodes in between the first line
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            //update pointers 
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            //curr1 and next1 ko aage badhana hai
            curr1 = next1;
            next1  = next1->next;

            if(next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    

    if(first->data <= second->data)
        return solve(first, second);
    else
        return solve(second, first);
       
}


int main()
{
    system("cls");

    //create two sorted linked list

    //function call to merge two sorted linked list

    //print merged linked list

    return 0;
    getch();
}

//TC - O(n)
//SC - O(1)