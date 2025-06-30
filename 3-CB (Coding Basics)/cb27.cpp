#include<iostream>
#include<vector>
#include<cmath>
using namespace std;



int main(){

    vector<vector<int> > ans;
    
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(3);
    ans.push_back(vi);
    
    vector<int> vi2; 
    vi2.push_back(15);
    vi2.push_back(18);
    ans.push_back(vi2);  

    vector<int> vi3;
    vi3.push_back(2);
    vi3.push_back(6);
    ans.push_back(vi3); 

    vector<int> vi4;
    vi4.push_back(8);
    vi4.push_back(10);
    ans.push_back(vi4);

    // , {15,18}, {2,6}, {8,10} };

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i][0]<<" "<< ans[i][1]<<endl;
    }
    cout <<endl;
    cout <<endl;

    cout<< ans.size() <<endl;


    return 0;
}