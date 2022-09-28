//****************************************************************************
//**********	REVERSE LEVER ORDER USING VECTOR	********************
//****************************************************************************
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

//************************************************************

template <typename T>

class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

//************************************************************/
TreeNode<int> *buildTree(TreeNode<int> *root)
{
    int data;
    cout << "\n enter data: ";
    cin >> data;

    root = new TreeNode(data);

    if (data == -1)
        return NULL;

    cout << "\n enter data for left : " << root->val;
    root->left = buildTree(root->left);
    cout << "\n enter data for right : " << root->val;
    root->right = buildTree(root->right);

    return root;
}

vector<int> reverseLevelOrder(TreeNode<int> *root)
{
    vector<int> ans;
    queue<TreeNode<int> *> q;

    if (root == NULL)
        return ans;

    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();

        ans.push_back(temp->val);

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main()
{
    system("cls");

    TreeNode<int> *root = NULL;

    root = buildTree(root);

    cout << "\n Printing the tree in reversal order:" << endl;
    for(auto i : reverseLevelOrder(root))
        cout<<i<<" ";


    return 0;
    getch();
}

//SC - O(n)
//TC - O(n)

// for reverse level order traversal ----- i/p = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1