#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;


void print_DFS(int** arr, int n, int sv, int * visited)
{
    cout<< sv <<" ";
    visited[sv]= 1;
    
    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i]==1 && visited[i]==0)
        {
            print_DFS(arr,n, i, visited);
        }
    }
    
}


void print_BFS(int** arr, int n, int sv, int * visited2)
{
    visited2[sv]= 1;
    queue<int> pendingVertices;
    pendingVertices.push(sv);


    while(!pendingVertices.empty())
    {
        int front= pendingVertices.front();

        pendingVertices.pop();
        cout<< front <<" ";

        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]==1 && visited2[i]==0)
            {
                pendingVertices.push(i);
                visited2[i]=1;
            }
        }
        
    }
}

bool hasPath_DFS(int** arr, int n, int v1, int v2, int* visited3)
{
    if(arr[v1][v2]==1) return true;
    visited3[v1]= 1;
    for (int i = 0; i < n; i++)
    {
        if(arr[v1][i]==1 && visited3[i] ==0)
        {
            bool b = hasPath_DFS(arr, n, i, v2, visited3);
            if(b) return b;
        }
    }
    return false;
}

bool hasPath_BFS(int** arr, int n, int v1, int v2, int* visited4)
{
    if(arr[v1][v2]==1) return true;
    visited4[v1]= 1;
    queue<int> pendingVertices;
    pendingVertices.push(v1);

    while (!pendingVertices.empty())
    {
        int front= pendingVertices.front();
        if(front== v2) return true;
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]==1 && visited4[i]==0)
            {
                pendingVertices.push(i);
                visited4[i]=1;
            }
        }
    }
    return false;
}

vector<int> getPath_DFS(int** arr, int n, int v1, int v2, int* visited5, vector<int> ans)
{
    ans.push_back(v1);
    visited5[v1]=1;
    if(v1==v2) return ans;

    for (int i = 0; i < n; i++)
    {
        if(arr[v1][i]==1 && visited5[i]==0)
        {
            vector<int> vi= getPath_DFS(arr, n, i, v2, visited5, ans);

            if(!vi.empty()) return vi;
        }
    }
    vector<int> fk;
    return fk;
}


vector<int> getPath_BFS(int** arr, int n, int v1, int v2, int* visited6)
{
    unordered_map<int,int> chain;
    visited6[v1]= 1;
    queue<int> pendingVertices;
    pendingVertices.push(v1);

    while (!pendingVertices.empty())
    {
        int front = pendingVertices.front();
        pendingVertices.pop();

        if(front== v2)  break;

        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]==1 && visited6[i]==0)
            {
                pendingVertices.push(i);
                visited6[i]=1;

                chain[i]= front;
            }
        }
    }

    int x= v2;
    vector<int> ans;
    ans.push_back(v2);
    while(x != v1)
    {
        ans.push_back(chain[x]);
        x= chain[x];
    }

    return ans;
    
}
 

int main(){

    int n,e;
    cin>>n>>e;
    int** arr= new int*[n];

    for (int i = 0; i < n; i++)
    {
        arr[i]= new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=0;
        }
        
    }

    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        arr[f][s]=1;
        arr[s][f]=1;
    }

    int* visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=0;
    }
    
    int* visited2= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited2[i]=0;
    }

    int* visited3= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited3[i]=0;
    }

    int* visited4= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited4[i]=0;
    }

    int* visited5= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited5[i]=0;
    }

    int* visited6= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited6[i]=0;
    }

    cout <<endl;
    print_DFS(arr, n, 3, visited);
    cout <<endl;
    print_BFS(arr, n, 3, visited2);

    cout <<endl;
    cout<<"hasPath_DFS : "<<hasPath_DFS(arr, n, 1, 2, visited3)<<endl;
    cout<<"hasPath_BFS : "<<hasPath_BFS(arr, n, 1, 2, visited4)<<endl;
    
    vector<int> ans;
    ans=  getPath_DFS(arr, n, 1, 7, visited5, ans);

    for(int i: ans)
    {
        cout<< i<<" ";
    }
    cout <<endl;



    // vector<int> ans;
    // ans=  getPath_DFS(arr, n, 1, 7, visited5, ans);

    // for(int i: ans){    cout<< i<<" ";  }


    vector<int> ans2;
    ans2= getPath_BFS(arr, n, 1, 7, visited6);

    for(int i: ans2){    cout<< i<<" ";      }

    cout <<endl;

    return 0;
}


// CONNECTED GRAPH :

// 8 8
// 3 1
// 3 4
// 1 2
// 1 0
// 4 5
// 4 6
// 5 7
// 6 7



// DISCONNECTED GRAPH :

// 7 5
// 0 1
// 0 2
// 1 2
// 3 5
// 4 6