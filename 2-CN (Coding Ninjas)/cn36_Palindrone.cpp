#include<iostream>
#include<cmath>
using namespace std;

bool isPal(string s){           //TELLS IF THE GIVEN STRING IS A PALINDRONE OR NOT (WITHOUT THE USE OF RECURSION)
    string k="";
    for (int i = 0; i < s.size(); i++)
    {
        k= s[i] +k ;
    }
    if(k == s){return true;}
    else{return false;}
} 

string reverse(string s){   //RETURNS THE REVERSE STRING OF THE GIVEN STRING    #USING RECURSION

    string k =s;
    if(s.size()== 0){return "" ;}
    return  reverse(s.substr(1, s.size()-1  )) + s[0];
    
}
 

bool recursive_isPal(string s){             //"isPal" FUNCTION USING RECURSION :)
    if(s.size() == 0 || s.size()== 1){return true;}
    if(s[0] != s[s.size()-1]){return false;}
    else{return recursive_isPal(s.substr(1,s.size()-2)) ;}
}


int main(){


    string s;
    cin>>s;
    cout<< isPal(s) <<endl;
    cout<< reverse(s) <<endl;
    cout<< recursive_isPal(s) <<endl;

    return 0;
}