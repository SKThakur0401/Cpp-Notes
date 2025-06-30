// { Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

 // } Driver Code Ends
// User function Template for C++




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

    void autoComplete(string word, TrieNode* root, string realWord, vector<string> &vi)
    {

        if(word.empty())
        {
            if(root->isTerminal) vi.push_back(realWord);
            printAll(root, realWord, vi);
            return;
        }
        int i= word[0]- 'a';
        if(root->children[i]==NULL)
        {
            return;
        }

        autoComplete(word.substr(1), root->children[i], realWord,vi);
    }

    void autoComplete(string word, vector<string> &vi)
    {
        autoComplete(word,root, word, vi);
    }

    void printAll(TrieNode* root, string word, vector<string> &vi)
    {
        for (int i = 0; i < 26; i++)
        {
            if(root->children[i] !=NULL)
            {
                if(root->children[i]->isTerminal)
                {
                    // cout<<word + root->children[i]->data<<endl;
                    vi.push_back(word + root->children[i]->data);
                }

                printAll(root->children[i], word+ root->children[i]->data, vi );
            }
        }
    }
};




class Solution{
public:
    
    

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie somu;
        for(int i=0; i<n; i++)
        {
            somu.insertWord(contact[i]);
        }
        
        vector<vector<string> > ans(s.size());
        
        for(int i=1; i<= s.size(); i++)
        {
            string st= s.substr(0,i);
            vector<string> vi;
            somu.autoComplete(st,vi);
            if(vi.size()==0) vi.push_back("0");
            ans[i-1] = vi;
            // ans.push_back(vi);   //This line is giving error
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends