#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class edge
{
    public:
    int f; int s; int weight;

    edge(int f, int s, int weight)
    {
        this->f= f;
        this->s= s;
        this->weight= weight;
    }
    edge(){}
};

bool comparator(edge a, edge b)
{
    return a.weight < b.weight ;
}


int main(){

    edge arr[5];

    for (int i = 0; i < 5; i++)
    {
        int f,s,weight;
        cin>>f>>s>>weight;
        edge ans(f,s,weight);
        arr[i]= ans;
    }

    sort(arr, arr+5, comparator);

    cout <<endl;
    cout <<endl;

    for (int i = 0; i < 5; i++)
    {
        cout<< arr[i].f<<" "<< arr[i].s<<" "<< arr[i].weight<<endl;
    }

    return 0;
}

