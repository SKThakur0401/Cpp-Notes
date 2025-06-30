#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


bool coinTower(int n, int x, int y)
{
    if(n==0) return false;

    bool w1=true;
    bool w2=true;
    bool w3=true;

    w1= coinTower(n-1, x, y);
    if(n-x >=0) w2= coinTower(n-x, x, y);
    if(n-y >=0) w3= coinTower(n-y, x, y);

    if( w1==false || w2==false || w3==false) return true;
    return false;
}

bool DP_coinTower(int n, int x, int y)
{
    bool* arr= new bool[n+1];
    arr[0]= false;

    for (int i = 1; i < n+1; i++)
    {
        bool w1=true;
        bool w2=true;
        bool w3=true;

        w1= arr[i-1];
        if(i-x >=0) w2= arr[i-x];
        if(i-y >=0) w3= arr[i-y];

        arr[i]= (!(w1 && w2 && w3));
    }
    return arr[n];
}

int main(){


    int n, x, y;
    cin>>n>>x>>y;

    // if(coinTower(n,x,y))
    // {
    //     cout<< "Beerus wins!!" <<endl;
    // }
    // else
    // {
    //     cout<< "Whis wins!!" <<endl;
    // }

    // if(DP_coinTower(n,x,y))
    // {
    //     cout<< "Beerus wins!!" <<endl;
    // }
    // else
    // {
    //     cout<< "Whis wins!!" <<endl;
    // }


    cout<< coinTower(n,x,y) <<endl;
    cout<< DP_coinTower(n,x,y) <<endl;

    return 0;
}

