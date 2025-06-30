// { Driver Code Starts
//Initial Template for C++
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 

 // } Driver Code Ends
//User function Template for C++


class TrieNode
{
    public:
    char data;
    TrieNode** children;

    bool isTerminal;
    
    int ax;

    TrieNode(char data)
    {
        this->data= data;
        children= new TrieNode*[26];
        isTerminal=false;

        for (int i = 0; i < 26; i++)
        {
            children[i]=NULL;
        }
        ax=-1;
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

    void insertWord(string word, TrieNode* root, int axCode)
    {
        int i= word[0] - 'a' ;
        if(root->children[i]==NULL) root->children[i] = new TrieNode(word[0]);

        if(word.size()==1)
        {
            root->children[i]->isTerminal=true;
            root->children[i]->ax= axCode;
            return;
        }
        insertWord(word.substr(1),root->children[i], axCode);
    }

    void insertWord(string word, int axCode)     // Helper Function
    {
        return insertWord(word,root, axCode);
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
    
    int retAX(string word, TrieNode* root)
    {
        if(word.size()==0 && root->isTerminal== true)
        {
            return root->ax;
        }
        
        return retAX(word.substr(1), root->children[word[0] - 'a']);
    }
    
    int retAX(string word)
    {
        return retAX(word, root);
    }

};


class Solution{
  public:
  
    
string sort(string s)
{
    for(int i = s.size() ; i >= 0; i--)
    {
        for (int j = 0; j < i-1; j++)
        {
            if(s[j]> s[j+1])
            {
                swap(s[j],s[j+1]);
            }
        }
        
    }
    return s;
}


    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        
        Trie somu;
        int ax=0;
        for(int i=0; i< string_list.size(); i++)
        {
            if(!somu.search(sort(string_list[i])))
            {
                somu.insertWord(sort(string_list[i])   , ax);
                ax++;
                
            }
        }
        vector<vector<string> > ans(ax+1);
        
        for(int i=0; i< string_list.size(); i++)
        {
            ans[somu.retAX(sort(string_list[i]))].push_back(string_list[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends