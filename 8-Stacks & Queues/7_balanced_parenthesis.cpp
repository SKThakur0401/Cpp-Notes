// A CODE TO CHECK WHETHER THE PARENTHESIS ARE BALANCED OR NOT.... IN OTHER WORDS.. TO CHECK WHETHER THE BRACKETS ARE STARTING AND CLOSING IN A LOGICAL MANNER

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s)      // This function works perfectly fine..just see this function... not "int main()" or something
{
    stack<char> st;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(' ||  s[i] == '{' ||  s[i] == '[')
        {
            st.push(s[i]);
        }
        
        else{
            if(st.empty()) return false;

            char f= st.top();

        else if((s[i] == ')' && f== '(') || (s[i] == '}' && f== '{') || (s[i] == ']' && f== '['))
            {
                st.pop();
            }
            else return false;
        }
    }
    return st.empty();
    
}


int main(){
    string s;
    cin>>s;
    int i=0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i]== '{' || s[i]== '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i]== '}' || s[i]== ']')
        {
            if(st.empty()) return false;
    if( (st.top()== '(' && s[i]==')')||(st.top()== '{' && s[i]== '}')||(st.top()=='[' && s[i]==']') )
            {
                st.pop();
            }
            else{cout<<"Not Balanced"<<endl; break;}
        }
    }
    if(st.empty())
    {
        cout<< "Balanced Parenthesis!!" <<endl;
    }
    else
    {
        cout<< "Unbalanced!!" <<endl;
    }
    

    return 0;
}