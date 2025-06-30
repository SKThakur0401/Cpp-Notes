#include <iostream>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	
// 	IF N IS ODD AND K IS ODD THEN "K-1" IS ANSWER


	int t; cin>>t;
	while(t--)
	{
	    long long n,k; cin>>n>>k;
	    
	   // if(k%2 == 1)
	   // {
	   //     if(n%2 == 0) cout<< "EVEN"<<endl;
    //         if(n%2 == 1) cout<< "ODD"<<endl;

	   // }
	   
// 	    vector<long long> vi(n);
// 	    for(long long i=0; i<n; i++)
// 	    {
// 	        vi[i]=i+1;
// 	    }
// 	    k--;
// 	    long long x= n-1;
// 	    while(x--)
// 	    {
// 	        while(vi[k]== -69)
// 	        {
// 	            k= (k+1)%n;
// 	        }
	        
// 	        vi[k]= -69;
// 	    }
	    
// 	    for(long long i: vi)
// 	    {
// 	        if(i != -69)
// 	        {
// 	            if(i%2 == 0) {cout<<"EVEN"<<endl; break;}
// 	            else {cout<< "ODD"<<endl; break;}
// 	        }
// 	    }
// 	}

        if(k==1)
        {
            if(n&1) cout<<"ODD"<<endl;
            else cout<< "EVEN"<<endl;
        }
        
        if(k==2) cout<<"ODD"<<endl;
        
        else cout<<"EVEN"<<endl;


	return 0;
	}
}


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){


    

    return 0;
}

