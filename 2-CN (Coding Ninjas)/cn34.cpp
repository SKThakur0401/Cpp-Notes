#include<iostream>
#include<cmath>
using namespace std;
 

int main(){

    // int ans=0;
    // string n;
    // cin>>n;
    // for (int i = 0; i < n.length(); i++)
    // {
    //     int k = stoi(s[i]);
    //     ans+=k;
    // }
    // cout<< k <<endl;

    string x ="abcdefghijklmnopqrstuvwxyz";
 
    cout<< sizeof(x) <<endl;
    cout<< x.substr(3,3) <<endl;
    cout<< sizeof(x[0]) <<endl;
    cout<< sizeof(x.substr(3,3)) <<endl;
    // int k =stoi(x[0]);
    // cout<< k+6 <<endl;
    string t = "a";

    char arr[]="coding";
    cout<< arr <<endl;
    char cic;
    for (int i = 0; i < 26; i++)
    {
        cic='a' +i;
        cout<< cic <<endl;
    }

    
    
    


    return 0;
}