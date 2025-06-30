//      CONVERT LOWER-CASE CHARACTERS INTO UPPER CASE AND VICE-VERSA

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

 
int main(){
    cout<< 'a' - 'A' <<endl;        //RETURNS--> 32  ,, SO THERE IS AN EXACT DIFFERENCE OF "32" BETWEEN ASCII VALUES OF UPPER-CASE AND LOWER CASE ALPHABETS
                                    //SO, IF WE DECREASE ASCII VALUE OF EACH LOWER CASE ALPHABET BY 32,,, THEN WE WILL GET UPPER-CASE OF THE SAME ALPHABET :)
    string st;
    cin>>st;
    for (int i = 0; i < st.size(); i++)
    {
        if(st[i]>='a' && st[i]<='z'){st[i] -= 32 ; continue;}       //BCOZ, AFTER CONVERTING LOWER CASE TO UPPERCASE,,, IT WILL GO TO NEXT "IF STATEMENT" AND THEN CONVERT BACK TO LOWER CASE,,, TO AVOID THAT, WE USED "CONTINUE :)"
        if(st[i]>='A' && st[i] <='Z'){st[i]+= 32 ;}
    }
    
    cout<< st <<endl;


    string str="dangerousCoder";
    transform(str.begin(),str.end(), str.begin(), ::toupper);       //CONVERTS THE ENTIRE STRING TO UPPER-CASE
    cout<< str <<endl;

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<< str <<endl;
    return 0;

}