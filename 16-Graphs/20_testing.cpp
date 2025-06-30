#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    int v,e;
    cin>>v>>e;
    vector<int> vix[v];

    for (int i = 0; i < e; i++)
    {
        int f,s; cin>>f>>s;

        vix[f].push_back(s);
        // vix[s].push_back(f);
    }

    for (int i = 0; i < v; i++)
    {
        cout<< i <<" : ";
        for (int j = 0; j < vix[i].size() ; j++)
        {
            cout<<vix[i][j]<<" ";
        }
        cout <<endl;
    }
    


    return 0;
}

// 5 7
// 0 1
// 1 2
// 0 2
// 1 3
// 3 2
// 3 4
// 4 2
