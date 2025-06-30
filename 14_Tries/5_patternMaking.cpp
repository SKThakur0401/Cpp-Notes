// Suffix tree implementation (for pattern Making)
// See screenshots for notes... or vdo on "types-of tries" of coding ninjas

#include<iostream>
#include<cmath>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode ** children;
    TrieNode(char data)
    {
        this->data=data;
        children= new TrieNode*[26];

        for (int i = 0; i < 26; i++)
        {
            children[i]=NULL;
        }
        
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            delete children[i];
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
            return;
        }
        insertWord(word.substr(1),root->children[i]);
    }

    void insert(string word)     // Helper Function
    {
        for (int i = 0; i < word.size(); i++)
        {
            insertWord(word.substr(i), root);
        }
        
        return;
    }

    bool search(string word, TrieNode* root)
    {
        if(word.size()==0) return true;
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

};



int main(){


    Trie somu;
    somu.insert("abc");
    somu.insert("def");
    somu.insert("ghi");
    somu.insert("cba");

    cout<< somu.search("ba") <<endl;
    cout<< somu.search("i") <<endl;
    cout<< somu.search("cb") <<endl;
    return 0;
}