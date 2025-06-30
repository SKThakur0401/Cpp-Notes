#include<iostream>
#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;




class Solution {
public:
    int longestAwesome(string s) {
        
        int ans=0;
        int mask=0;

        unordered_map<int, vector<int> > um;



        for(int i=0; i<s.size(); i++)
        {
            int index= s[i]- '0';
            mask= mask^(1<<index);

            if(mask==0) {ans= i+1; um[mask].push_back(i);}

            else if(um.count(mask))
            {
                if(int(um[mask].size()) %2)
                {
                    ans=max(ans, i+1);
                }

                else
                {
                    ans= max(ans, i-um[mask][0]+1);
                }

            }
            

            for(int j=0; j<10; j++)
            {
                int premask= mask^(1<<j);


                if(premask==0) ans= i+1;

                else if(um.count(premask))
                {
                    if(int(um[premask].size()) %2)
                    {
                        ans=max(ans, i+1);
                    }

                    else
                    {
                        ans= max(ans, i-um[mask][0]+1);
                    }
                }
            }


            // if(um.count(mask)) 
            um[mask].push_back(i);
            // else um[mask]= {i};
        }


        int fuck= s.size();
        if(ans > fuck) return s.size();
        return ans;
    }
};



int main()
{   
    cout<< "Enter : ";
    string s;
    cin>>s;
    
    Solution ss;
    
    int ans= ss.longestAwesome(s);
    
    cout<<endl;
    cout<<ans<<endl;
    
    
    return 0;
}
