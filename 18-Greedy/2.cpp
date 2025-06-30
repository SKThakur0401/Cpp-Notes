// IN AN ARRAY, MINIMISE THE DIFFERENCE BETWEEN THE "LARGEST" AND "SMALLEST" NUMBER, BY "ADDING OR SUBTRACTING" 'K' FROM EACH ELEMENT OF THE ARRAY, NOTE: U MUST ADD OR SUBTRACT K FROM EACH ELEMENT.

// SOLUTION VIDEO : GO TO GREEDY PLAYLIST OF CODING NINJA, GO TO ASSIGNMENT FOLDER... AND FIRST VIDEO IN THERE " DISCUSSION PROBLEM " IS THIS Q'S SOLUTION.....

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int solve(int arr[], int n, int ans, int k)
{
    int small= arr[0]+k;
    int big= arr[n-1]-k;

    if(small> big) swap(big,small);

    for (int i = 1; i < n-1; i++)
    {
        int add= arr[i]+k;
        int sub= arr[i]-k;
        if(add <= big || sub >= small) continue;

        if(add- big > small - sub)
        {
            small= sub;
        }

        else
        {
            big= add;
        }
    }
    return min(ans, big-small);
}

int main(){

    int n; cin>>n;
    int k; cin>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    

    sort(arr,arr+n);
    int ans= arr[n-1]- arr[0];
    cout<<solve(arr, n, ans,k)<<endl;

    return 0;
}

