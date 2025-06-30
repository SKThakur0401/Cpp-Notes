#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class edge
{
    public:
    int weight;
    int si;
    int ei;

    edge(){}

    edge(int si, int ei, int weight)
    {
        this->si= si;
        this->ei= ei;
        this->weight= weight;
    }
};

bool comparator(edge a, edge b)
{
    return a.weight < b.weight;
}

void Answerer(edge* arr, int n, int e)
{
    // sort(arr, arr+ e , compare);
    int* parent= new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i]=i;
    }
    edge* ans= new edge[n-1];

    int x=0;

    for (int i = 0; i < e; i++)
    {
        int s= arr[i].si;
        int eir= arr[i].ei;

        int grandsi= s;
        int grandei= eir;

        while(grandsi != parent[grandsi])
        {
            grandsi= parent[grandsi];
        }

        while(grandei != parent[grandei])
        {
            grandei= parent[grandei];
        }

        if(grandsi== grandei) continue;

        parent[grandsi]= grandei;

        ans[x]= arr[i];
        x++;
    }
    
    // return ans;
    for (int i = 0; i < n-1; i++)
    {
        cout<< ans[i].si<<" "<< ans[i].ei<<" "<< ans[i].weight <<endl;
    }
}

int main(){

    int n; int e;
    edge* arr= new edge[e];
    for (int i = 0; i < e; i++)
    {
        int si, ei, weight;
        cin>>si>>ei>>weight;
        edge skt(si,ei, weight);
        arr[i]= skt;
    }
    sort(arr, arr+e , comparator);

    // edge* ans= new edge[n-1];
    Answerer(arr, n, e);

    // for (int i = 0; i < n-1; i++)
    // {
    //     cout<< ans[i].si<<" "<< ans[i].ei<<" "<< ans[i].weight <<endl;
    // }
    

    return 0;
}

// 6 11
// 0 1 1
// 0 2 5
// 2 3 10
// 0 3 4
// 1 3 3
// 1 2 6
// 3 4 7
// 2 4 8
// 4 5 2
// 2 5 9
// 3 5 6