// Create a function "autoComplete" which when given the initial letters... will find all the strings with those initials!  e.g. if your trie contains various words like devil, dedil, delta, delshit etc...  and u ask for autocomplete("de") ... will return all the words which starts with "de", just like when we do google search!!!

// Note solving this question using "tries" requires a lot less time complexity, search engines have infinite no. of words its impossible for them to search for a word starting with "de" if they try to go through every word and see if it starts with "de" (#brute force approach) , therefore tries are a great help to them.


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

    void autoComplete(string word, TrieNode* root, string realWord)
    {

        if(word.empty())
        {
            printAll(root, realWord);
            return;
        }
        int i= word[0]- 'a';
        if(root->children[i]==NULL)
        {
            return;
        }

        autoComplete(word.substr(1), root->children[i], realWord);
    }

    void autoComplete(string word)
    {
        autoComplete(word,root, word);
    }

    void printAll(TrieNode* root, string word)
    {
        for (int i = 0; i < 26; i++)
        {
            if(root->children[i] !=NULL)
            {
                if(root->children[i]->isTerminal)
                {
                    cout<<word + root->children[i]->data<<endl;
                }

                printAll(root->children[i], word+ root->children[i]->data );

            }
        }
        
    }


};

int main()
{
    Trie somu;

    somu.insertWord("alpha");
    somu.insertWord("alpino");
    somu.insertWord("alpi");
    somu.insertWord("alpingo");
    somu.insertWord("beta");
    somu.insertWord("gamma");
    somu.insertWord("gadha");
    somu.insertWord("theta");
    somu.insertWord("delta");
    somu.insertWord("alpix");
    somu.insertWord("alter");
    somu.insertWord("alti");
    somu.insertWord("altd");
    somu.insertWord("altf");

    somu.insertWord("delfuck");
    somu.insertWord("delcunt");
    somu.insertWord("delshit");
    somu.insertWord("deshit");
    somu.insertWord("devil");
    somu.insertWord("dedil");
    somu.insertWord("dsomu");
    somu.insertWord("djesu");


    somu.autoComplete("ga");

    return 0;
}
