#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool isPrime(int n)
{
    if(n==1) return false;
    for(int i=2; i<n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int minPenalty(vector<int> arr)
{
    vector<int> nonPrimes;
    vector<int> primes;

    for(auto i:arr)
    {
        if(isPrime(i)) primes.push_back(i);
        else nonPrimes.push_back(i);
    }

    if(abs((int)primes.size()- (int)nonPrimes.size()) <= 1) return 0;

    if(primes.size() > nonPrimes.size())
    {
        int d = primes.size()- nonPrimes.size()-1;
        sort(primes.begin(), primes.end());

        int ans=0;
        for(int i=0; i<d; i++)
        {
            ans+=primes[i];
        }
        return ans;
    }

    if(nonPrimes.size() > primes.size())
    {
        int d = nonPrimes.size()- primes.size()-1;
        sort(nonPrimes.begin(), nonPrimes.end());

        int ans=0;
        for(int i=0; i<d; i++)
        {
            ans+=nonPrimes[i];
        }
        return ans;
    }
    return 0;
}

int main(){


    vector<int> arr;

    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(10);

    cout<< "The answer is : ";
    cout<< minPenalty(arr) <<endl;

    return 0;
}

