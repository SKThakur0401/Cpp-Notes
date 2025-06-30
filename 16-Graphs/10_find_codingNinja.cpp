 // Watch vdo to understand question(if does not remember..)

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;


bool isCN(char** arr, int i, int j, int n, int m, bool** visited, string cn)
{
    visited[i][j]= true;
    if(cn.empty()) return true;

    if(i+1< n && arr[i+1][j] == cn[0] && !visited[i+1][j] )
    {
        bool b = isCN(arr, i+1, j, n, m, visited, cn.substr(1));
        if(b) return true;
    }

    if(j+1< m && arr[i][j+1] == cn[0] && !visited[i][j+1] )
    {
        bool b = isCN(arr, i, j+1, n, m, visited, cn.substr(1));
        if(b) return true;
    }

    if(i+1< n &&  j+1< m && arr[i+1][j+1] == cn[0] && !visited[i+1][j+1] )
    {
        bool b = isCN(arr, i+1, j+1, n, m, visited, cn.substr(1));
        if(b) return true;
    }

    if(j-1>= 0 && arr[i][j-1] == cn[0] && !visited[i][j-1] )
    {
        bool b = isCN(arr, i, j-1, n, m, visited, cn.substr(1));
        if(b) return true;
    }

    if(i-1>= n && arr[i-1][j] == cn[0] && !visited[i-1][j] )
    {
        bool b = isCN(arr, i-1, j, n, m, visited, cn.substr(1));
        if(b) return true;
    }



    if(i-1 >=0 &&  j-1 >=0 && arr[i-1][j-1] == cn[0] && !visited[i-1][j-1] )
    {
        bool b = isCN(arr, i-1, j-1, n, m, visited, cn.substr(1));
        if(b) return true;
    }

    if(i-1 >=0 &&  j+1 <m && arr[i-1][j+1] == cn[0] && !visited[i-1][j+1] )
    {
        bool b = isCN(arr, i-1, j+1, n, m, visited, cn.substr(1));
        if(b) return true;
    }

    if(i+1 < n &&  j-1 >=0 && arr[i+1][j-1] == cn[0] && !visited[i+1][j-1] )
    {
        bool b = isCN(arr, i+1, j-1, n, m, visited, cn.substr(1));
        if(b) return true;
    }

    return false;
}


vector<pair<int,int> > finder(char** arr, int n, int m, string cn)
{
    vector<pair<int,int> > cpairs;
    for (int ir = 0; ir < n; ir++)
    {
        for (int jr = 0; jr < m; jr++)
        {
            if(arr[ir][jr]== cn[0])
            {
                pair<int,int> pi(ir,jr);
                cpairs.push_back(pi);
            }
        }
    }
    return cpairs;
}


bool isCodNin(char** arr, vector<pair<int,int> > cpairs, int n, int m, string cn)
{
    for (int x = 0; x < cpairs.size(); x++)
    {
        bool **visited= new bool*[n];
        for (int i = 0; i < n; i++)
        {
            visited[i]= new bool[m];
            for (int j = 0; j < m; j++)
            {
                visited[i][j]= false;
            }
        }


        int i= cpairs[x].first;
        int j= cpairs[x].second;

        bool b= isCN(arr, i, j, n, m, visited, cn.substr(1));

        if(b) return true;
    }
    return false;
}



int main(){

    int n; int m; cin>>n>>m;
    char** arr= new char*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
        string s; cin>>s;
        
        for (int j = 0; j < m; j++)
        {
            arr[i][j]= s[j];
        }
    }

    string cn = "CODINGNINJA";

    vector<pair<int,int> > cpairs;
    cpairs = finder(arr, n, m, cn);


    cout<< isCodNin(arr, cpairs, n, m, cn) <<endl;
    
    return 0;
}

// 3 6
// XXNAXC
// OIJNOD
// DXNGIX   