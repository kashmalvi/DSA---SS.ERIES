//************************************************************************************
//**********	DETECT AND REMOVE LOOP	********************VIA FLOYD-DETECTION 
//************************************************************************************
#include<iostream>
#include<conio.h>
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

// function to print the list of nodes
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//by floydDetection algorithm
node* floydDetectLoop(node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast)
        {
            // cout<<"\n present at slow->data "<<slow->data;
            return slow;
        }
    }
    return NULL;
}

//function to getstarting point of loop
node* getStartingNode(node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    node* intersection = floydDetectLoop(head);

    node* slow = head;

    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

//fucction to remove loop
void removeLoop(node* head)
{
    if(head == NULL)
    {
        return ;
    }

    node* startOfloop = getStartingNode(head);
    cout<<endl;
    node* temp = startOfloop;

    while(temp->next != startOfloop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

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

    cout<<"\ntail "<<tail->data;
    cout<<"\nhead "<<head->data;

    tail->next = head->next->next; // creating loop starting at 10

    // print(head); //it will print loop infinitly times

    if(floydDetectLoop(tail) != NULL)
        cout<<"\n list having loop";
    else    
        cout<<"\n list do not having loop";

    node* loop = getStartingNode(head);
    cout<<endl<<loop->data<<endl;

    removeLoop(head);
    print(head); // if not loop then it print all values in list    

    return 0;
    getch();
}

/*
output - 
10
15 12 10
15 12 10 8 6

tail 6
head 15
 present at slow->data 6
 list having loop       
 present at slow->data 8
10

 present at slow->data 8
15 12 10 8 6
*/

//TC - O(n)
//SC - for maping - O(n)
//   - for floydDetect - O(1) 