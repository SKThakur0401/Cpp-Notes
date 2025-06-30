//PRINT THE MATRIX IN SPIRAL FORMAT     //IF DON'T KNOW SPIRAL : C++ INTRO : 2D ARRAY PLAYLIST

#include<iostream>
#include<cmath>
using namespace std;

// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16

// 1  2  3  4 5
// 6  7  8  9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25

int main()
{
    // int arr[5][5]={{1,2,3,4, 5},{6,7,8, 9,10},{11,12, 13,14,15},{16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int arr[4][4]={{1,2,3,4},{ 5,6,7,8}, {9,10, 11,12},{ 13,14,15, 16} };

    int ans[16];
    // int ans[25];
    int rs,re,cs,ce;
    rs=0;cs=0;re=3;ce=3;
    int q=0;

    while(rs <= re && cs <= ce)
    {
        for (int i = cs; i <= ce; i++)
        {
            ans[q]= arr[rs][i]; q++;
        }
        
        rs++;

        for (int i = rs; i <= re; i++)
        {
            ans[q]= arr[i][ce]; q++;
        }

        ce--;

        for (int i = ce; i >= cs; i--)
        {
            ans[q]= arr[re][i]; q++;
        }
        
        re--;

        for (int i = re; i >= rs; i--)
        {
            ans[q]= arr[i][cs]; q++;
        }
        cs++;

    }

    for (int i = 0; i < q; i++)
    {
        cout<< ans[i]<<" ";
    }
    

    return 0;
}
 

// int main(){


//     int arr[4][4]={{1,2,3,4},{5,6,7,8,},{9,10,11,12},{13,14,15,16}};

//     int ans[16];
//     int rs,re,cs,ce;
//     rs=0;cs=0;re=3;ce=3;
//     int q=0;


//     //LOOP STARTS HERE

//     for (int i = cs; i < ce; i++)
//     {
//         ans[q]=arr[rs][i];
//         q++;
//     }
//     for (int i = rs; i < re; i++)
//     {
//         ans[q]=arr[i][ce];
//         q++;
//     }
//     rs++;


//     for (int i = ce; i > cs; i--)
//     {
//         ans[q]=arr[re][i];
//         q++;
//     }
//     ce--;


//     for (int i = re; i > rs; i--)
//     {
//         ans[q]=arr[i][cs];
//         q++;
//     }
//     re--;
    

//     for (int i = cs; i < ce; i++)
//     {
//         ans[q]=arr[rs][i];
//         q++;
//     }
//     cs++;


//     for (int i = rs; i < re; i++)
//     {
//         ans[q]=arr[i][ce];
//         q++;
//     }
//     rs++;


//     for (int i = ce; i >= cs; i--)
//     {
//         ans[q]=arr[re][i];
//         q++;
//     }
//     ce--;
    
//     //LOOP ENDS HERE




//     for (int i = 0; i < 16; i++)
//     {
//         cout<< ans[i]<<" ";
//     }
    

//     return 0;
// }