#include<iostream>
#include<cmath>
using namespace std;

 
string encoder(string &s){
    for (int i = 0; i < s.size(); i++)
    {
        if(i%3 == 0){s[i]++;}
        else if(i%5 == 0){s[i]-- ;}
        else if(i%7 == 0){s[i]+=2;}
        else if(i%11 == 0){s[i]-=2;}
        else if(i%13 == 0){s[i]+=3;}
        else if(i%17 == 0){s[i]-=3;}
        else{s[i]+=4;}
    }
    cout<< "Encoded Data ----->  ";
    return s;
} 

string decoder(string &s){
    for (int i = 0; i < s.size(); i++)
    {
        if(i%3 == 0){s[i]--;}
        else if(i%5 == 0){s[i]++ ;}
        else if(i%7 == 0){s[i]-=2;}
        else if(i%11 == 0){s[i]+=2;}
        else if(i%13 == 0){s[i]-=3;}
        else if(i%17 == 0){s[i]+=3;}
        else{s[i]-=4 ;}
    }
    cout<< "Decoded Data ----->  ";
    return s;
}


int main(){


    string s="Hi, my name is Saumya Kumar Thakur , This is a string encoder : use can use it to encrypt and decrypt your data :)";
    // cout<< encoder(s) <<endl;
    // cout<< decoder(s) <<endl;
    
//  USE THESE FUNCTIONS "encoder AND decoder"       //ENTER WHAT U WANT TO ENCODE/DECODE IN CONTENT :)
    string content = "TRIBOHOI$JMN\"TXBQQNN%W!ADDM$ESSS";

    cout<< encoder(content) <<endl;
    cout<< decoder(content) <<endl;

    // cout<< '' +1 <<endl;

    return 0;
}