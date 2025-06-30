#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){


    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int c=0;

        for(int i=0; i<n; i++)
        {

            int x;
            cin>>x;
            if(x=0)
            {
                c=-1;
            }
            if(x<0 && c!=-1) c= (c+1)%2;
        }

        if(c%2==0 || c== -1) cout<< 0 <<endl;
        else cout<< 1 <<endl;
    }

    return 0;
}
