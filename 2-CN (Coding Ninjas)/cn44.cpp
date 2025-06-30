//QUESTION-1 : "replace" will replace all instances of character s1 with character s2 in the character array str
//QUESTION-2 : "dupify" WILL REMOVE consecutive duplicates from it recursively. IF SAME LETTER IS TYPED MULTIPLE TIMES CONSECUTIVELY ,,, THEN IT WILL LET ONLY ONE INSTANCE TO LIVE


#include<iostream>
#include<cmath>
using namespace std;
  
void replace(char s2, char s1, char str[])
{
    if(str[0]== '\0'){return;}
    if(str[0]!= s1){return replace(s2,s1, str+1);}
    else
    {
        str[0]= s2;
        return replace(s2,s1,str+1);
    }
}

void dupify(char str[])
{
    if(str[0]=='\0' || str[1]=='\0'){return;}
    if(str[0]!= str[1]){return dupify(str+1);}
    else
    {
        int i=1;
        for (; str[i] != '\0' ; i++)
        {
            str[i-1]=str[i];
        }
        str[i-1]=str[i];
        return dupify(str);
    }
}



int main(){

    char s2= 'z',s1='s';
    char str[]="subbtillissssser";
    dupify(str);
    cout<< str <<endl;


    replace(s2,s1, str);
    cout<< str <<endl;


    return 0;
}