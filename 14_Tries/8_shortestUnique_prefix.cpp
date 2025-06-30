// WAP TO PRINT SHORTEST UNIQUE PREFIX FOR EACH WORD

// Input: arr[] = {"zebra", "dog", "duck", "dove"}
// Output: dog, dov, du, z
// Explanation: dog => dog
//              dove => dov 
//              duck => du
//              zebra => z

// Note: The solution given below is not the most optimised soln, there's an easier + more optimised approach!! (Its hint is given in the next file)
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

    bool isLast(string s, TrieNode* root)
    {
        if(s.size()==0) return true;
        int j= s[0]- 'a';

        for (int i = 0; i < 26; i++)
        {
            if(root->children[i]!= NULL && i != j)
            {
                return false;
            }
        }
        return isLast(s.substr(1), root->children[j]);
    }

    string shortestPrefix(string s, TrieNode* root, string ans)
    {
        if(s.size()==0)
        {
            return ans;
        }

        int i= s[0] - 'a';
        if(isLast(s.substr(1),root->children[i]))
        {
            return ans + s[0];
        }
        return shortestPrefix(s.substr(1), root->children[i], ans+ s[0]);
        
    }

    string shortestPrefix(string s)
    {
        string ans= "";
        return shortestPrefix(s,root, ans);
    }

};

int main()
{
    Trie somu;
    string arr[] = {"zebra", "dog", "duck", "dove"};
    // string arr[] = {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
    // string arr[] = {"soman", "jesu", "papa","somaan"};

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        somu.insertWord(arr[i]);
    }
    
    
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]) ; i++)
    {
        string st= somu.shortestPrefix(arr[i]);
        cout<< st <<endl;
    }


    return 0;
}

