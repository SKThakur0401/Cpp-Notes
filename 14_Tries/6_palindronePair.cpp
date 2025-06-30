// Find all palindrones,


#include<iostream>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode** children;

    int isTerminal;

    TrieNode(char data)
    {
        this->data= data;
        children= new TrieNode*[26];
        isTerminal=-1;

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

    void insertWord(string word, TrieNode* root, int x)
    {
        int i= word[word.size() -1 ] - 'a' ;
        if(root->children[i]==NULL) root->children[i] = new TrieNode(word[word.size()-1]);

        if(word.size()==1)
        {
            root->children[i]->isTerminal=x;
            return;
        }
        word.pop_back();
        insertWord(word,root->children[i], x);
    }

    void insertWord(string word, int x)     // Helper Function
    {
        return insertWord(word,root, x);
    }

    int search(string word, TrieNode* root)
    {
        if(word.size()==0)
        {
            // if(root->isTerminal== -1) return false;
            // return true;
            return root->isTerminal;
        }



        int i= word[0]- 'a';
        if(root->children[i] !=NULL && root->children[i]->data == word[0])
        {
            return search(word.substr(1), root->children[i]);
        }

        return -1;
    }

    int search(string word)        // Helper Function
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


int main(){

    int n; cin>>n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // Trie somu;
    // // bool isPal=false;

    // for (int i = 0; i < n; i++)
    // {
    //     somu.insert(arr[i],i);
    // }



    Trie somu;

    for (int i = 0; i < n; i++)
    {
        somu.insertWord(arr[i],i);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(somu.search(arr[i]) != -1)
        {
            cout<<i<<" "<<somu.search(arr[i])<<endl;
        }
    }
    



    // somu.insertWord("abcd",2);
    // cout<< somu.search("dcba") <<endl;

    return 0;
}


