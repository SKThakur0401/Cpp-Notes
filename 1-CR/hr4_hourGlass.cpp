#include<iostream>
#include<cmath>
using namespace std;


int main(){


    int arr[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    int ans[4][4];
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            ans[i-1][j-1] = arr[i][j] + arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1]+ arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
        }
    }
    

    int max= ans[0][0];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(ans[i][j] > max){max= ans[i][j];}
            // cout<<endl<< ans[i][j] <<" ";
        }
        
    }
    cout<< max <<endl;
    return 0;
}