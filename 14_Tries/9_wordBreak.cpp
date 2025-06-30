// Important question (currently trending)

// Given a dictionary of words, and u have to tell that a user inserted string can be made with your dictionary or not.
// Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details. 

// Consider the following dictionary 
// { i, like, sam, sung, samsung, mobile, ice, 
//   cream, icecream, man, go, mango}

// Input:  ilike
// Output: Yes 
// The string can be segmented as "i like".

// Input:  ilikesamsung
// Output: Yes
// The string can be segmented as "i like samsung" or 
// "i like sam sung".


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
    
    bool isPresent(string word)
    {
        if(word.empty()) return true;
        for (int i = 1; i <= word.size(); i++)
        {
            if( search(word.substr(0,i)))
            {
                bool x= isPresent(word.substr(i));
                if(x== true) return true;
            }
        }
        return false;
    }
};

int main()
{
    Trie somu;
    string arr[] = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", 
  "cream", "icecream", "man", "go", "mango"};

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        somu.insertWord(arr[i]);
    }

    string s;
    cin>>s;

    cout<< somu.isPresent(s) <<endl;
}