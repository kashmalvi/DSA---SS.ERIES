//****************************************************************************
//**********	REVERSE LEVEL ORDER USING STACK    ********************
//****************************************************************************
#include <iostream>
#include <conio.h>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "\n enter data: ";
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "\n enter data for left : " << root->data;
    root->left = buildTree(root->left);
    cout << "\n enter data for right : " << root->data;
    root->right = buildTree(root->right);

    return root;
}

void reversalOrderTraversal(node *root)
{
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *temp = q.front();
        
        q.pop();

        if (temp == NULL) // puranan level complete traverse ho chuka hai
        {
            s.push(NULL);
            if (!q.empty()) // q still have some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            s.push(temp);
            
            if (temp->right)
                q.push(temp->right);
            
            if (temp->left) // non-null = 1 and nul = 0
                q.push(temp->left);


        }
    }

    while (!s.empty())
    {
        root = s.top();
        
        if(root != NULL)
            cout << root->data << " ";
        else
            cout<<endl;

        s.pop();    
    }
}

int main()
{
    system("cls");

    node *root = NULL;

    root = buildTree(root);

    cout << "\n Printing the tree in reversal order:" << endl;
    reversalOrderTraversal(root);

    return 0;
    getch();
}

//SC - O(n)
//TC - O(n)
// for level order traversal ----- i/p = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1