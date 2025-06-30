#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

stack<int> reverse(stack<int> s, stack<int> xtra)
{
    if(s.size()==1) return s;

    int x = s.top();
    s.pop();
    s = reverse(s,xtra);

    while(!s.empty())
    {
        xtra.push(s.top()); s.pop();
    }
    s.push(x);
    while(!xtra.empty())
    {
        s.push(xtra.top()); xtra.pop();
    }
    return s;
}


int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    stack<int> xtra;
    s= reverse(s, xtra);

    while (!s.empty())
    {
        cout<< s.top() <<endl; s.pop();
    }
    

    return 0;
}

