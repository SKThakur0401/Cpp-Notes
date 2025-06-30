// We use "tries" to implement 'dictionary', a dictionary is a large collection of words, we can also store all those words (&meanings) in a "hashmap", but that will consume a lot more space when compared to a "trie", bcoz a trie is a tree like structure, where each Node has a 'data' part, which is a char, and an array type which contains "26" other nodes, (coz there are 26 alphabets in english) ,and so on.

// Tries is more space efficient bcoz,e.g.  for all the thousands of words starting with "a", it has 1 "a" stored as a character, whereas the dictionary would have taken "thousand bits for all the thousand a's  "

// From that "a" it moves to all other characters and so on for every character


// U CAN DIRECTLY SEE THE "2_Trie.h" file, it contains all that this file has to offer, + it has remove function also!



#include<iostream>
#include<cmath>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode ** children;
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
};


// Insert, Remove and Search
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
        // if(word.size()==0) return;
        // if(word.size()==0) {root->isTerminal=true; return;}
        if(root->children[word[0]- 'a'] ==NULL)
        {
            root->children[word[0]- 'a'] = new TrieNode(word[0]);
        }
        if(word.size()==1)
        {
            root->children[word[0]- 'a']->isTerminal = true;
            return;
        }

        insertWord(word.substr(1), root->children[word[0]- 'a']);
    }

    void insertWord(string word)
    {
        insertWord(word,root);
    }

    bool search(string word, TrieNode* x)
    {
        if(word.size()==0) return x->isTerminal;

        if(x->children[word[0] - 'a'] != NULL && x->children[word[0]- 'a']->data == word[0])
        {
            return search(word.substr(1), x->children[word[0]- 'a']);
        }
        return false;
    }

    bool search(string word)
    {
        return search(word, root);
    }
};

int main(){

    Trie somu;
    somu.insertWord("sky");    
    somu.insertWord("vox");    
    somu.insertWord("done");    
    somu.insertWord("do");    
    somu.insertWord("donation");
    somu.insertWord("doing");    
    somu.insertWord("v");    

    cout<< somu.search("v") <<endl;
    cout<< somu.search("vo") <<endl;
    cout<< somu.search("vox") <<endl;

    return 0;
}

