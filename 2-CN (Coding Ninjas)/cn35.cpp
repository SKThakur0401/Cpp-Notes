//QUESTION : IN A STRING FIND THE CHARACTER WITH MAXIMUM OCCURENCES... TELL THE NUMBER OF TIMES IT OCCURED AND WHICH IS THE LUCKY CHARACTER :)

#include<iostream>
#include<cmath>
using namespace std;

 
int main(){

    string st= "ffjiejissssslfjjjjjnf";

    int arr[26];        //LATER ADDED DATA : WE CAN ALSO CREATE "arr" the way it is here by simply doing --> int arr[26]={0} ... all other 25 elements here are replaced by zero by default

    for (int i = 0; i < 26; i++)
    {
        arr[i]=0;
    }
    
    for (int i = 0; i < st.size(); i++){
        arr[st[i] - 'a']++;}

    int maxf=0;
    char cmax;
    for (int i = 0; i < 26; i++){
        if(arr[i] > maxf){ maxf = arr[i] ; cmax= i+ 'a' ; }
    }

    cout<< "max frequency is : "<<maxf <<endl;
    cout<< "Most frequently used character is : "<< cmax <<endl;
    
    return 0;
}

