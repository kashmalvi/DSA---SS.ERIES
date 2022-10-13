//****************************************************************************
//*******************	 MORRIS TRAVERSAL	**************************
//****************************************************************************
#include <iostream>
#include <conio.h>
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

void MorrisTraversal(node *root)
{
    node *curr;
    node *pre;
    if (root == NULL)
        return;
    curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while (pre->left != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL) // make current as right of pre
            {
                pre->right = curr;
                curr = curr->left;
            }
            else // revert changes done in if-condition above
            {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    system("cls");
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    MorrisTraversal(root);

    return 0;
    getch();
}

// tc - O(n)
// sc - O(1)