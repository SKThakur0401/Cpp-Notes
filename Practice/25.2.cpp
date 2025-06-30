#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class edge
{
    public:
    int si, ei, wt;

    edge(int si, int ei, int wt)
    {
        this->si= si;
        this->ei= ei;
        this->wt= wt;
    }
};

bool comparator(edge a, edge b)
{
    return a.wt < b.wt;
}


int main(){

    int n,e; cin>>n>>e;
    vector<edge> input;

    for (int i = 0; i < e; i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edge e(f,s,w);

        input.push_back(e);
    }
    
    sort(input.begin(), input.end(), comparator);

    vector<edge> output;

    vector<int> parentIndex(n);
    for (int i = 0; i < n; i++)
    {
        parentIndex[i]=i;
    }
    

    for (int i = 0; i < e; i++)
    {
        edge x= input[i];

        int grandParent_si= x.si;
        int grandParent_ei= x.ei;

        while(grandParent_si != parentIndex[grandParent_si]) grandParent_si= parentIndex[grandParent_si];
        while(grandParent_ei != parentIndex[grandParent_ei]) grandParent_ei= parentIndex[grandParent_ei];

        if(grandParent_si == grandParent_ei) continue;
        parentIndex[grandParent_si]= grandParent_ei;
        output.push_back(input[i]);
    }
    

    for (int i = 0; i < output.size(); i++)
    {
        cout<< output[i].si<<"  " <<output[i].ei << "  "<< output[i].wt  <<endl;
    }
    

    return 0;
}

