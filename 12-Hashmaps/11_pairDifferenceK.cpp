#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int pairDiff(int arr[],int n,int k)
{
    if(k==0)
    {
        unordered_map<int,int> om;

        double c=0;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if(om.count(arr[i])==0)
            {
                om[arr[i]]=1;
            }
            else 
            {
                om[arr[i]]+=1; 
            }
        }

        for (int i = 0; i < n; i++)
        {
            c+= (1.0*(om[arr[i]]-1))/2;         // actually it should have been of the form
                                                // c+= (arr[i]*(arr[i]-1)))/2 .... ie xC2...
                                                // but since the value equal to arr[i] will come   "om[arr[i]]"" times... so we simply did 
                                                // "c+= (om[arr[i]])/2" bcoz this operation will be performed "om[arr[i]]" times... we did "*1.0" to handle floats
        }
        return c;
    }
    unordered_map<int,int> om;
    int c=0;
    for (int i = 0; i < n; i++)
    {
        if(om.count(arr[i])==0)
        {
            om[arr[i]]=1;
        }
        else {om[arr[i]]+=1;}
    }
    
    for (int i = 0; i < n; i++)
    {
        if(om.count(k+arr[i]))
        {
            c+=om[k+arr[i]];
        }
    }
    return c;
}

int main()
{

    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k; cin>>k;

    int c= pairDiff(arr,n,k);
    cout<< c <<endl;




    return 0;
}

