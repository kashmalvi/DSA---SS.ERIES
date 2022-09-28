//****************************************************************************
//**********	CREATION AND TRAVERSAL IN TREE  	********************
//****************************************************************************
#include <iostream>
#include <conio.h>
#include <queue>
using namespace std;

// binary tree node
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// build tree
node *buildTree(node *root)
{
    cout << "\nEnter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "\n Enter data for inserting in left" << endl;
    root->left = buildTree(root->left);
    cout << "\n Enter data for inserting in right" << endl;
    root->right = buildTree(root->right);

    return root;
}

void leverOrderTraversal(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        
        q.pop();

        if (temp == NULL) // puranan level complete traverse ho chuka hai
        {
            cout << endl;
            if (!q.empty()) // q still have some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left) // non-null = 1 and nul = 0
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(node* root)
{
    if(root == NULL)
        return ;
    
    inorder(root->left);          //L
    cout<<root->data<<" ";        //N
    inorder(root->right);         //R
}

void preorder(node* root)
{
    if(root == NULL)
        return ;

    cout<<root->data<<" ";        //N    
    preorder(root->left);          //L
    preorder(root->right);         //R
}

void postorder(node* root)
{
    if(root == NULL)
        return ;
    
    postorder(root->left);          //L
    postorder(root->right);         //R
    cout<<root->data<<" ";          //N
}

void buildfromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"\nEnter data for root : "<<endl;
    int data;
    cin>>data; 
    root = new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"\n enter left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        
        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        } 
        
        cout<<"\n enter right node for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        
        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        } 
    }
}

int main()
{
    system("cls");
    node *root = NULL;
    
    buildfromLevelOrder(root);
    leverOrderTraversal(root);

    /*
    root = buildTree(root);
    cout << "\n Printing the level order traversal" << endl;
    leverOrderTraversal(root);

    cout<<"\nInorder : ";
    inorder(root);

    cout<<"\nPreorder : ";
    preorder(root);

    cout<<"\nPostorder : ";
    postorder(root);

    */
    return 0;
    getch();
}

// for level order traversal ----- i/p = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

// for build order traversal ----- i/p = 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1