// QUESTION:  U HAVE BEEN GIVEN A STRING OF BRACKETS.... '{'  AND '}'  ...YOU HAVE TO TELL... HOW MANY MINIMUM NUMBER OF BRACKETS WE NEED TO REVERSE TO MAKE THIS STRING OF BRACKETS "BALANCED" OR LOGICALLY SOUND...


// Sample Input 1:
// {{{

// Sample Output 1:
// -1

// Sample Input 2:
// {{{{}}

// Sample Output 2:
// 1

#include<iostream>
#include<stack>
using namespace std;

int minBrackets_requiringReversal(string s)
{
    if(s.size() %2 ==1){return -1;}
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]== '{')
        {
            st.push(s[i]);
        }

        if (s[i]== '}')
        {
            if(st.empty()){st.push(s[i]);}

            else if(st.top() == '{'){st.pop();}
            else {st.push(s[i]);}
        }
    }
    if(st.empty()){return 0;}
    int count=0;
    while(!st.empty())
    {
        char c1= st.top() ; st.pop();
        char c2= st.top() ; st.pop();

        if(c1==c2){count++;}
        if(c1!=c2){count+=2;}
    }
    return count;
}

int main(){

    string s;
    cin>>s;
    cout<< minBrackets_requiringReversal(s) <<endl;

    return 0;
}