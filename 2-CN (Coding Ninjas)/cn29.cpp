//QUESTION : GIVEN AN INTEGER "n" ,,, COUNT THE NUMBER OF ZEROES IN IT USING RECURSION


#include<iostream>
#include<cmath>
using namespace std;

int zero(int n,int ans=0){
    if(n%10 == 0){ans++;}
    else if(n%10 == n){return ans;}
    n= (n-(n%10))/10;
    return zero(n ,ans);
}
 

int main(){

    int n;
    cin>>n;
    cout<< zero(n) <<endl;

    return 0;
}

//SAME QUESTION DONE USING STRINGS :) ,,, IF DON'T REMEMBER STRINGS, CHECK-OUT CN-31 ;
// int main(){

//     int n;
//     cin>>n;
//     string s =to_string(n);
//     int ans=0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if(s[i] == '0'){ans++;}
//         else{continue ;}
//     }
//     cout<< ans <<endl;
// }

