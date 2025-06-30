// Sample Input 1:
// 4
// 10 10 10 10

// Sample Output 1:
// 1 1 1 1

// Sample Input 2:
// 8
// 60 70 80 100 90 75 80 120

// Sample Output 2:
// 1 2 3 4 1 1 2 8

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void solve(int arr[], int ans[], int n)
{
    stack<int> st;
    st.push(0); ans[0]=1;

    for (int i = 1; i < n; i++)
    {
        while(!st.empty()  &&  arr[i]> arr[st.top()])
        {
            st.pop();
        }
        ans[i] = (st.empty())? i+1 : i-st.top();

        st.push(i);
    }
    
}

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int ans[n];
    solve(arr, ans, n);

    for (int i = 0; i < n; i++)
    {
        cout<< ans[i] <<" ";
    }
    cout <<endl;
    
    

    return 0;
}

