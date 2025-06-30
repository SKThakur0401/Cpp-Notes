// Here we have created a Header-file, to store our own hand-made "2_Trie.h"  (TRIE).
// IT CONTAIN ALL 3 FUNCTIONS : INSERT, SEARCH & REMOVE

#include<iostream>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode** children;

    bool isTerminal;

    TrieNode(char data)
    {
        this->data= data;
        children= new TrieNode*[26];
        isTerminal=false;

        for (int i = 0; i < 26; i++)
        {
            children[i]=NULL;
        }
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if(children[i] !=NULL) delete children[i];
        }
    }
};

class Trie
{
    TrieNode* root;
    public:

    Trie()
    {
        root= new TrieNode('\0');
    }

    void insertWord(string word, TrieNode* root)
    {
        int i= word[0] - 'a' ;
        if(root->children[i]==NULL) root->children[i] = new TrieNode(word[0]);

        if(word.size()==1)
        {
            root->children[i]->isTerminal=true;
            return;
        }
        insertWord(word.substr(1),root->children[i]);
    }

    void insertWord(string word)     // Helper Function
    {
        return insertWord(word,root);
    }

    bool search(string word, TrieNode* root)
    {
        if(word.size()==0) return root->isTerminal;
        int i= word[0]- 'a';
        if(root->children[i] !=NULL && root->children[i]->data == word[0])
        {
            return search(word.substr(1), root->children[i]);
        }

        return false;
    }

    bool search(string word)        // Helper Function
    {
        return search(word,root);
    }

    void remove(string word, TrieNode* root)
    {
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }
        int i= word[0] - 'a';

        if(root->children[i] == NULL)       // This means the word we are asked to remove does not 
                                            // exist! so in that case we don't have to remove anything, just return;
        {
            return;
        }

        remove(word.substr(1),root->children[i]);

        TrieNode* child= root->children[i];
        bool isLast=true;
        for (int i = 0; i < 26; i++)
        {
            if(child->children[i] !=NULL)
            {
                isLast=false;
                break;
            }
        }

        
        if(root->children[i]->isTerminal== false && isLast)
        {
            delete child;
            root->children[i]= NULL;
        }
    }

    void remove(string word)
    {
        return remove(word, root);
    }

};


