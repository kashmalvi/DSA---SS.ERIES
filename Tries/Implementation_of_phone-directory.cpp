//****************************************************************************
//**********	IMPLEMENTATION OF PHONE DIRECTORY	********************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    //constructor
    TrieNode( char ch )
    {
        this->data = ch;
        for(int i=0; i<25; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode* root ;

    //constructor
    Trie()
    {
        root = new TrieNode('/0');
    }

    //insertion
    void insertUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return ;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }        

        //recursion 
        insertUtil(child, word.substr(1));
    }
    void insertword(string input)
    {
        insertUtil(root, input);
    }

    //PRINT SUGGESTIONS 
    void printsuggestion(TrieNode* curr, vector<string> &temp, string prefix)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for(char ch='a'; ch<='z'; ch++)
        {
            TrieNode* next = curr->children[ch - 'a'];

            if(next != NULL)
            {
                prefix.push_back(ch);
                printsuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string str)
    {
        vector<vector<string>> ans;

        TrieNode* prev = root;
        string prefix = "";

        for(int i=0; i<str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);

            TrieNode* curr = prev->children[lastch - 'a'];

            if(curr == NULL)
                break;

            vector<string> temp;
            printsuggestion(curr, temp, prefix);
            ans.push_back(temp);
            temp.clear();
            prev = curr;            
        }
        return ans;        
    }
    
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t = new Trie();
    
    //insert all contact in trie
    for(int i=0; i<contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertword(str);
    }


    //return ans
    return t->getSuggestions(queryStr);
}


int main()
{
    system("cls");
    vector<string> input = {"cod" , "coding" , "codding" , "code" , "coly"};
    string querystr = {"coding"};
    for(auto i : phoneDirectory(input, querystr)){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
    getch();
}

/*
complexity----
tc - O(n*m*m)
sc - O(n*m)


o/p  -                                      prefixes for every stack
cod codding code coding coly            -   c
cod codding code coding coly            -   co
cod codding code coding                 -   cod
coding                                  -   codi
coding                                  -   codin
coding                                  -   coding
*/
