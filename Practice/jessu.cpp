#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#define ll long long int
using namespace std;

// vector<int> solve(vector<int>& num){
//     vector<int> ans(num.size(), -1);
//     stack<int> st;

//     for(int i= num.size()-1; i >=0; i--){

//         while(!st.empty() && st.top() <= num[i]){
//             st.pop();
//         }

//         ans[i] = (st.empty())? -1 : st.top();
//         st.push(num[i]);
//     }
//     return ans;
// }


int main(){

    // stack<int> st;
    // vector<int> num;
    // num.push_back(3);       // 3  7  1  8  3
    // num.push_back(7);
    // num.push_back(1);
    // num.push_back(8);
    // num.push_back(3);

    // vector<int> ans = solve(num);

    unordered_map<int, int> um;
    um[6] = 36;
    um[7] = 49;
    um[8] = 36;
    um[9] = 36;

    unordered_map<int, int>:: iterator it = um.begin();

    while(it != um.end()){
        cout<< (*it).first<< " - "<< (*it).second <<endl;
        it++;
    }
    return 0;
}

