// Problem Statement: Return subsets sum to K
// Problem Level: HARD
// Problem Description:
// Given an array A of size n and an integer K, return all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important.
// Input format :
// Line 1 : Integer n, Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K

// Constraints :
// 1 <= n <= 20

// Sample Input :
// 9
// 5 12 3 17 1 18 15 3 17
// 6

// Sample Output :
// 3 3
// 5 1

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






// #include<iostream>
// #include<cmath>
// using namespace std;

// void finder(int n, int arr[], int k , string output ,int i=0)
// {
//     if(k== 0){cout<<output<<endl;}
//     else if(n == 0){return;}
// else if(k>0)
// {
//     finder(n-1,arr+1,k , output, i+1);
//     output= output +" " +to_string(arr[0]);
//     finder(n-1,arr+1,k- arr[0] , output, i+1);}
// }


// int main(){
    
//     int n;
//     cout<<"Enter size of array : ";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter array elements : ";


//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }

//     cout<< "Enter Sum K : ";
//     int k;
//     cin>>k;
//     string output ="";
//     finder(n, arr, k, output);

//     return 0;
// }



// // #include<bits/stdc++.h>
// // using namespace std;

// // int main()
// // {
// //     string s;
// //     cin>>s;
//     int cnt=1;
//     sort(s.begin(),s.end());
//     for(int i=0;i<s.size()-1; i++)
//     {
//         if(s[i]!=s[i+1]) cnt++;
//     }
//     if(cnt%2==0) cout<<"girl"<<endl;
//     else cout<<"boy"<<endl;
//     return 0;
// }