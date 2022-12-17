//**********************************************************************************
//**********	CREATION OF TRIES - IMPLEMENTING A DICTIONARY	********************
//**********************************************************************************
#include<iostream>
#include<conio.h>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        //constructor
        TrieNode(char ch)
        {
            data = ch;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false; 
        }
};

class Tries
{
    public:
        TrieNode* root;

        //constructor
        Tries()
        {
            root = new TrieNode('\0');
        }

        //INSERTION - O(l) , where l is length of word
        void insertUtil(TrieNode* root, string word)
        {
            //base case
            if(word.length() == 0)
            {
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            //present
            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }
            //absent
            else
            {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursion
            insertUtil(child, word.substr(1));
        }

        void insertword(string word)
        {
            insertUtil(root, word);
        }

        //SEARCHING - O(l) , where l is length of word
        bool searchUtil(TrieNode* root, string word)
        {
            //base case
            if(word.length() == 0)
                return root->isTerminal;

            int index = word[0] - 'a';
            TrieNode* child;

            //present
            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }
            
            //absent
            else
            {
                return false;
            }
 
            //recursion
            return searchUtil(child, word.substr(1));
        }

        bool search(string word)
        {
            return searchUtil(root, word);
        }

        //DELTION
        void deleteUtil(TrieNode* root, string word)
        {
            //base case
            if(word.length() == 0)
            {
                root->isTerminal = false;
                delete root;
                return ;
            }

            int index = word[0] - 'a';
            TrieNode* child;
            child = root->children[index];

            //recursion
            deleteUtil(child, word.substr(1));

            //space optimisation
            if(root->isTerminal==false && !root->children)
            {
                delete root;
            }


        }
        void deleteword(string word)
        {
            deleteUtil(root, word);
        }
};

int main()
{
    // system("cls");

    Tries *t = new Tries();
    t->insertword("bablu");
    t->insertword("dablu");
    t->insertword("babul");

    cout<<"\nPresent or not "<<t->search("bablu");
    cout<<"\nPresent or not "<<t->search("dablu");

    cout<<"\nPresent or not "<<t->search("babl");   
    t->deleteword("bablu");
    cout<<"\nPresent or not "<<t->search("bablu");   
    cout<<"\nPresent or not "<<t->search("dablu");   
    cout<<"\nPresent or not "<<t->search("babul");  

    return 0;
    getch();
}

