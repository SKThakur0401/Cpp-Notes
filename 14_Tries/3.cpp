#include<iostream>
#include "2_Trie.h"

int main(){
    Trie somu;
    somu.insertWord("sky");
    // somu.insertWord("vox");
    // somu.insertWord("done");
    // somu.insertWord("do");
    // somu.insertWord("donation");
    // somu.insertWord("doing");    
    // somu.insertWord("v");

    // cout<< somu.search("v") <<endl;
    // cout<< somu.search("vo") <<endl;
    // cout<< somu.search("voxi") <<endl;
    cout<< somu.search("sky") <<endl;
    somu.remove("sky");
    cout<< somu.search("sky") <<endl;
    somu.insertWord("skyler");
    cout<<somu.search("skyler")<<endl;
    somu.remove("skyler");
    cout<<somu.search("skyler")<<endl;

    return 0;
}


