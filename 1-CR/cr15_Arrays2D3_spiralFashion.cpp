//SOLVING THE PREVIOUS QUESTION FOR 5X5 SPIRAL

#include<iostream>
#include<cmath>
using namespace std;


int main(){


    int arr[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

    int ans[25];
    int rs,re,cs,ce;
    rs=0;cs=0;re=4;ce=4;
    int q=0;

for (int a = 0; a < 3; a++)
{
    for (int i = cs; i < ce; i++)
    {
        ans[q]=arr[rs][i];
        q++;
    }
    if(a>0){cs++;}
    if(q>=24){ans[q]=13;break;}
    for (int i = rs; i < re; i++)
    {
        ans[q]=arr[i][ce];
        q++;
    }
    rs++;
    
    if(q>=24){ans[q]=13;break;}


    for (int i = ce; i > cs; i--)
    {
        ans[q]=arr[re][i];
        q++;
    }
    ce--;

    if(q>=24){ans[q]=13;break;}


    for (int i = re; i > rs; i--)
    {
        ans[q]=arr[i][cs];
        q++;
    }
    re--;
    if(q>=24){ans[q]=13;break;}

}

    for (int x = 0; x < 25; x++)
    {
        cout<< ans[x]<<" ";
    }
    

    return 0;
}