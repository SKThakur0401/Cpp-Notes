//SORTING CHARACTERS IN A STRING IN ALPHABETICAL ORDER...USING BUBBLE SORT
 

#include<iostream>
#include<cmath>
using namespace std;
 
void sort(string &s,int n)
{
    for (int i = n-1; i >=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(  (s[j]) > (s[j+1])  )
            {
                char temp= s[j];
                s[j]= s[j+1];
                s[j+1]= temp;
            }
        }
    }
}

int main(){
    string random="ifhewilewfj";
    sort(random,random.length());
    cout<< random <<endl;
    return 0;
}