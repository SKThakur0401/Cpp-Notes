#include<iostream>
#include<unordered_map>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class edge{
    public:

    int weight;
    int si;
    int ei;
    edge(){}

    edge(int s, int e, int w)
    {
        weight= w;
        si= s;
        ei= e;
    }
};


bool comparator(edge a, edge b)
{
    return a.weight < b.weight;
}

void printEdge(edge *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i].si<<" "<<arr[i].ei<<" "<<arr[i].weight <<endl;
    }
    
}

int main(){

    edge* arr = new edge[5];

    for (int i = 0; i < 5; i++)
    {
        int s,e,w;
        cin>>s>>e>>w;
        edge somu(s,e,w);
        arr[i]= somu;
    }
    
    cout <<endl;
    cout <<endl;

    sort(arr , arr+5, comparator);


    printEdge(arr, 5);
    

    return 0;
}

