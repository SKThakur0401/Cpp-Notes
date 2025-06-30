//QUESTION: WRITE A FUNCTION WHICH REMOVES ALL INSTANCES OF THE CHARACTER "x" FROM A CHARACTER ARRAY

#include<iostream>
#include<cmath>
using namespace std;

void removeX(char str[])
{
    if(str[0] == '\0'){return;}

    if(str[0] != 'x'){return removeX(str+1);}
    else
    {
        int i=1;
        for (i = 1; str[i] !='\0'; i++)
        {
            str[i-1]=str[i];
        }
        str[i-1]=str[i];
        return removeX(str);
    }
}


int main(){


    char str[]="djxxklxxkl";
    removeX(str);
    cout<< str <<endl;

    return 0;
}