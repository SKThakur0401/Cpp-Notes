#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void solve(int n, int k, int* arr, vector<int> vi, vector<vector<int> > &ans)
{
    if(k==0) {ans.push_back(vi); return;}
    if(n==0) return;

    solve(n-1, k, arr+1, vi, ans);

    if(arr[0] <= k)
    {        
        vi.push_back(arr[0]);
        solve(n-1, k- arr[0], arr+1, vi, ans);
    }

}

int main(){

    int n,k; cin>>n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cin>>k;

    vector<int> vi;

    vector<vector<int> > ans;
    solve(n, k, arr, vi, ans);
    
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<< ans[i][j] <<" ";
        }
        cout <<endl;
    }

    return 0;
}

