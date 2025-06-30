// GREEDY IS A "TECHNIQUE"
// IT IS NOT APPLICABLE IN ALL SCENARIOS "lekin jaha kaam karti hai waha bahut badhia kaam karti hai"

// TC/SC BACHANE MAY HELP KARTI HAI... JIN SCENARIOS MAY "GREEDY" NAHI USE KAR SAKTE, WAHA HUM NORMAL "DP" KARTE HAI





// QUESTION:
// Weighted Job Scheduling
// Send Feedback
// You are given N jobs where every job is represented as:
// 1.Start Time
// 2.Finish Time
// 3.Profit Associated
// Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
// Input
// The first line of input contains one integer denoting N.
// Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
// Output
// Output one integer, the maximum profit that can be achieved.
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di, p ≤ 10^6
// Sample Input
// 4
// 3 10 20
// 1 2 50
// 6 19 100
// 2 100 200
// Sample Output
// 250




// SOLUTION : THIS IS A VERY IMPORTANT/GOOD QUESTION OF " GREEDY+ DP ", HERE WE WILL USE "GREEDY" TO "BOOST" OUR TIME COMPLEXITY BEFORE APPLYING "DP" ON IT... WE WILL USE "GREEDY" AS A TOOL ON THIS QUESTION OF "DP" TO IMPROVE OUR TIME COMPLEXITY :) ... TRY YOURSELF, IF NOT ABLE TO DO, SEE SOLUTION OUR CODING NINJA VIDEO
#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class trio
{
    public:
    int st; int et; int profit;
    
    trio(int s, int e, int p)
    {
        this->st=s;
        this->et=e;
        this->profit=p;
    }
};

bool compare(trio x, trio y)
{
    return x.et < y.et;
}

int solve(vector<trio> arr, int n, vector<int>& memo)
{
    int ans=arr[n-1].profit;
    if(n==1) return memo[n]= ans;
    if(memo[n] != -1) return memo[n];
    int maxi= 0; int maxj=0;
    for(int i= n-2; i>=0; i--)
    {
        if(arr[i].et <= arr[n-1].st)
        {
            maxi= max(maxi, solve(arr, i+1, memo));

            break;      // WE PUT A BREAK TO IMPROVE OUR TIME COMPLEXITY!!, NOTE: AT "MEMO[i]" we are storing the maximum profit that could be generated, starting from "0 to i", now profit generated at memo[i] might not even have the "i_th" job in it!.... SO!, EVEN IF WE BREAK, WE KNOW "solve(arr,i+1, memo" will have the best profit till that "i_th" index stored in it, so there is no point in checking for lower values of "i" since it would either be equal or less than the profit at this "i_th" index :)
        }
    }

    return memo[n] = max(maxi+ ans, solve(arr,n-1, memo));
}

int main(){

    int n; cin>>n;

    vector<trio> arr;

    for (int i = 0; i < n; i++)
    {
        int s,e,p; cin>>s>>e>>p;
        trio t(s,e,p);
        arr.push_back(t);
    }
    
    sort(arr.begin(), arr.end(), compare);

    vector<int> memo(n+1,-1);
    
    int ans = solve(arr,n, memo);
    cout<< "The answer is : "<< ans <<endl;

    return 0;
}

