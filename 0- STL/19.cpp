#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
 
class tri
{
    public:
    int r,c,t;
    tri(int r, int c,int t)
    {
        this->r=r;
        this->c=c;
        this->t=t;
    }
};

int main(){

    // tri somu(2,1, 13);

    // int t= somu.t;
    // cout<< t <<endl;
    

    string s= "somu";

    reverse(s.begin()+2, s.begin()+4);
    cout<< s <<endl;

    return 0;
}

