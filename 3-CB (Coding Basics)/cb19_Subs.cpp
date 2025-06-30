// A more simpler/easier/ less power hungry code for printing subsequences :)
// e.g. input = "ab"        we take 2 cases(and divide those 2 cases in further 2 cases)
// case 1> "a" is taken, and now there are 2 cases, whether "a" is inserted in output string, or not inserted   (ie. simply discarded :)

//  then, in input string, remains only b.... again, 2 cases, "b" is either discarded, or moved to output string
// This is how we will end-up printing every possible subsequence-string
  
#include<iostream>
#include<cmath>
using namespace std;

void pin(string input, string output)
{
    if(input.empty()){cout<< output <<endl;}
    else
    {
        pin(input.substr(1), output);
        pin(input.substr(1), output + input[0]);
    }
}


int main(){

    string output="";
    cout<< "Enter the string : ";
    string input;
    cin>>input;

    pin(input,output);
    

    return 0;
}