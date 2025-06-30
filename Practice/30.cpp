#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    double x,y,a,b;

    cin>>x>>y>>a>>b;
    cout <<endl;
    cout <<endl;

    int turns = 0;

    if(x >= y)      // To handle edge case where numerator >= denominator
    {
        if(x > y) turns = -1;
        else if(a== b) turns = 0;
        cout<< turns <<endl;
    }

    else{
        if(x/y < a/b)           // If desired fraction is smaller, we will try to
        {                       // give tests where we fail to reach the desired
            while(x/y < a/b)    // fraction in minimum steps
            {
                b++;
                turns++;
            }
        }

        else
        {
            while(x/y > a/b)    // If desired frac is greater than current frac, 
            {                   // we'll give tests we pass to reach desired frac
                a+=1;           // in min steps
                b+=1;
                turns++;
            }
        }
    }

    cout<< turns <<endl;
    return 0;
}




