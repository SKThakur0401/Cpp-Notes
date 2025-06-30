#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int countCycle(int** arr, int n)
{
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]==1 && i != j)
            {
                for (int k = 0; k < n; k++)
                {
                    if(arr[j][k]==1 && k !=i && k!=j)
                    {
                        if(arr[i][k]==1)
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return (count)/6;
}

int main(){
    int n,e;
    cin>>n>>e;

    int** arr= new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]= new int[n];

        for (int j = 0; j < n; j++)
        {
            arr[i][j]=0;
        }
    }
    

    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        arr[f][s]=1;
        arr[s][f]=1;
    }
    cout <<endl;
    cout <<endl;
    

    cout<< countCycle(arr, n) <<endl;

    return 0;
}

