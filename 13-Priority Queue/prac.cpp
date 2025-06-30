#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    int n; cin>>n;
    int c=0; int a= 1;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        if(i%2)
        {
            for (int j = 0; j < i; j++)
            {
                cout<< a<<" ";
                a++;
            }
            cout <<endl;
        }

        else if(i%2 == 0)
        {
            for (int j = 0; j < i; j++)
            {
                cout<< char(c+'A')<<" ";
                c++;
            }
            cout <<endl;
        }
    }
    

    return 0;
}

