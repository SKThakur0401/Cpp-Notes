#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> intersect(int ar1[], int ar2[], int n, int m)
{
    unordered_map<int, int> ourmap;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ourmap[ar1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if(ourmap.count(ar2[i]) >0)
        {
            ourmap[ar2[i]]--;
            if(ourmap[ar2[i]] >=0) ans.push_back(ar2[i]);
        }
    }
    
    return ans;

}

int main(){

    int t; cin>>t;

    for (int i = 0; i < t; i++)
    {
        int n; cin>>n;
        int ar1[n];
        for (int j = 0; j < n; j++)
        {
            cin>>ar1[j];
        }

        int m; cin>>m;
        int ar2[m];
        for (int j = 0; j < m; j++)
        {
            cin>>ar2[j];
        }

        vector<int> v= intersect(ar1,ar2,n,m);
        cout <<endl;
        for (int j = 0; j < v.size(); j++)
        {
            cout<< v[j] <<" ";
        }
        cout <<endl;
    }
    

    return 0;
}
