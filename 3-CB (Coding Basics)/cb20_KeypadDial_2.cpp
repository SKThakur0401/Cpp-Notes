// Just like cb-19 is a different way to go about cb-17 ,,, this is a different way to go about cb-18

#include<iostream>
#include<cmath>
using namespace std;
  
// void pin(string input, string output)    // Not optimised for, " 4-letter keys " like 7 and 9
// {
//     string a= "abcdefghijklmno";
//     if(input.empty()){cout<< output <<" ";}
//     else
//     {
//         int p = input[0] - '0';
//         pin(input.substr(1), a[(p-2)*3+ 0] +output);
//         pin(input.substr(1), a[(p-2)*3+ 1] +output);
//         pin(input.substr(1), a[(p-2)*3+ 2] +output);
//     }
// }



void keypad(string s, string arr[], string output= "")
{
    if(s.empty()) {cout<< output <<" "; return;}

    for (int i = 0; i < arr[s[0]- '2'].size(); i++)
    {
        keypad(s.substr(1), arr, output+ arr[s[0]- '2'][i]);
    }
    
}

int main(){
    string output="";
    string input;
    cin>>input;

    string arr[8] = {"abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" ,"tuv" , "wxyz"};

    keypad(input, arr, output);

    return 0;
}