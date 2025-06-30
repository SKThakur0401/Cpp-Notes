#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


// To check if a given number is prime or not,

// We will do "Sieve of Eratosthenes", in an array we will store all the prime numbers upto 10^6... when we move are on 2, we will mark all it's multiples, then when we move to 3 we will mark all it's multiples, then we move to 4, which is already marked, which means all it's elements will also be marked obviously :), so we move to 5 and mark all it's succeeding elements, now since '5' is not marked, it means it is prime!( same is the case with every number, if it is not marked means it is prime, so we will mark all it's multiples :)    NOTE: U CAN NOTICE THAT WHILE MARKING MULTIPLES OF A NUMBER "N", ALL IT'S MULTIPLES BEFORE  "N*N" WILL ALREADY BE MARKED!, BECAUSE THE NUMBERS WHICH HAVE PERFORMED MARKING BEFORE "N", HAVE ALREADY MARKED NUMBERS RANGING FROM (N*2) TO (N * (N-1)) .... BECAUSE NUMBERS RANGING FROM "2" TO "N-1" HAVE PERFORMED MARKING PROCESS WHERE THEY HAVE MARKED NOS. (2* N) , (3*N) ... (N-1 * N)  :)

// SO WHILE MARKING... WE CAN SIGNIFICANTLY OPTIMISE OUR CODE WITH THE HELP OF THIS OBSERVATION, FOR EACH NO. "N" , WE START MARKING FROM "N*N" .... "N*(N+1)".... "N*(N+2)" AND SO ON..


vector<int> ReturnPrimesLessThanN(int n)
{
    vector<int> ans;

    vector<int> vi(n+1,0);

    for(int i=2; i<=n; i++)
    {
        if(vi[i]==0)
        {
            for (int j = i*i; j < n+1; j+=i)
            {
                vi[j] = 1;
            }
            
        }
    }

    for (int i = 2; i < n+1; i++)
    {
        if(vi[i]==0) ans.push_back(i);
    }
    return ans;
}

int solveSmall(vector<int> primeList, int a)
{
    int low = 0;
    int high=primeList.size()-1;
    
    while(low <= high)
    {
        if(low == high) return primeList[low];
        int mid= (low+high)>>1;
        
        if(low == mid)
        {
            if(primeList[high] > a) return primeList[low];
            else if(primeList[high]==a) return a;
            else return primeList[high];
        }

        if(primeList[mid] == a) return a;

        if(primeList[mid]< a) low=mid;
        
        else if(primeList[mid]> a) high= mid;
    }
    return primeList[low];
}


int solveBig(vector<int> primeList, int a)
{
    int low = 0;
    int high=primeList.size()-1;
    
    while(low <= high)
    {
        if(low == high) return primeList[low];
        int mid= (low+high)>>1;
        
        if(low == mid)
        {
            // if(primeList[high] > a) return primeList[low];
            // else if(primeList[high]==a) return a;
            // else return primeList[high];
            
            if(primeList[low] < a) return primeList[high];
            else if(primeList[low]==a) return a;
            else return primeList[low];
        }

        if(primeList[mid] == a) return a;

        if(primeList[mid]< a) low=mid;
        
        else if(primeList[mid]> a) high= mid;
    }
    return primeList[high];
}

int main(){

    int n=175;

    vector<int> ans= ReturnPrimesLessThanN(n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] <<" ";
    }
    cout <<endl;
    cout <<endl;
    
    // cout<< solveSmall(ans, 20) <<endl;
    int flag=1;
    for(int i=20; i<150; i+=1)
    {
        cout<< i <<" : "<< solveBig(ans, i) <<endl;
        if(i > solveBig(ans,i)) {flag=0; break;}
    }

    if(flag) cout<< "All testcase pass!" <<endl;
    else cout<< "Testcase failed!" <<endl;
    
    return 0;
}

