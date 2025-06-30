#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class edge{
    public:
    int si;
    int ei; int weight;

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


int main(){


    int n,e;
    cin>>n>>e;
    vector<edge> input;
    vector<edge> output;


    for (int i = 0; i < e; i++)
    {
        int f,s, w;
        cin>>f>>s>>w;
        edge e(f,s,w);
        input.push_back(e);
    }

    sort(input.begin(), input.end(), comparator);
    
    int* parentIndex= new int[n];
    for (int i = 0; i < n; i++)
    {
        parentIndex[i]= i;
    }
    
    int count= 0;
    int i=0;
    while(count < n-1)
    {
        int si= input[i].si;
        int ei= input[i].ei;
        int weight= input[i].weight;
        
        int grandSi= si;
        int grandEi= ei;

        while(parentIndex[grandSi] != grandSi) grandSi= parentIndex[grandSi];
        while(parentIndex[grandEi] != grandEi) grandEi= parentIndex[grandEi];

        if(grandSi == grandEi) {i++; continue;}

        parentIndex[ei]= si;
        edge e(si, ei , weight);
        output.push_back(e);
        count++;
        i++;
    }

    cout <<endl;
    cout <<endl;

    for (int i = 0; i < n-1; i++)
    {
        cout<< output[i].si<<" " << output[i].ei<<" " << output[i].weight<<endl;
    }
    
    

    return 0;
}

