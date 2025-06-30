// BACKTRACKING IS AN "APPROACH"/ "IDEA" ,  WHICH IS IMPLEMENTED USING "RECURSION"
// PUT YOURSELF AT STARTING POINT
// EXPLORING ALL THE PATHS FROM THE STARTING POINT
// INSERT UR ELEMENT AT ONLY POSSIBLE INDICES AND AFTER THAT MOVE ON TO THE SMALLER SUB-PROBLEM
// ONCE YOU EXPLORE ALL PATHS FROM A GIVEN POINT, BACKTRACK TO THE PREVIOUS POINT

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool solve(bool** arr, int n, vector<int> &vi, vector<vector<string> >& ans, int row)
{
    if(row==n)
    {
        vector<string> vs;
        for(int i=0; i<n; i++)
        {
            string s= "";
            
            for(int j=0; j<n; j++)
            {
                if(j != vi[i]) s+="." ;
                
                else s+='Q';
            }
            vs.push_back(s);
        }
        ans.push_back(vs);
        return true;
    }
    
    
    for(int i=0; i<n; i++)
    {
        if(arr[row][i] == 1) continue;

        vi[row]=i;
        arr[row][i]= 1;
            
        int r= row; int c= i;
        
        while(r<n) {arr[r][c]=1; r++;}
        
        r= row; c++; r++;
        
        while(r<n && c<n)
        {
            arr[r][c]=1;
            r++; c++;
        }
        r= row; c= i; r++; c--;
        
        while(r<n && c >= 0)
        {
            arr[r][c]=1;
            r++; c--;
        }
        
        
        bool b= solve(arr, n, vi, ans, row+1);
        
        
        
        
            
        r= row;  c= i;
        
        while(r<n) {arr[r][c]=0; r++;}
        
        r= row; c++; r++;
        
        while(r<n && c<n)
        {
            arr[r][c]=0;
            r++; c++;
        }
        
        r= row; c= i; r++; c--;
        
        while(r<n && c >= 0)
        {
            arr[r][c]=0;
            r++; c--;
        }
    }
    
    return false;
}










vector<vector<string> > solveNQueens(int n) {
    
    vector<vector<string> > ans;
    
    bool** arr = new bool*[n];
    for(int i=0; i<n; i++)
    {
        arr[i]= new bool[n];
        for(int j=0; j<n; j++)
        {
            arr[i][j]= 0;
        }
    }
    vector<int> vi(n,0);
    
    solve(arr,n, vi, ans, 0);
    
    return ans;
}


int main(){

    vector<vector<string> > s;
    
    s= solveNQueens(5);
    
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout<< s[i][j] <<endl;
        }
        cout <<endl;
        cout <<endl;
        cout <<endl;
    }
    

    return 0;
}


