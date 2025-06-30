// HERE WE R GOING TO MAKE OUR FUNCTION "reverse" ... just like we made various functions in "LINKED-LISTS like takeInput, print,len etc.." ... this function will reverse the stack... and we will use one "extra stack s2" to make this job possible... NOTE: WE HAVE OUR OWN STACK "s" and an auxillary stack "s2" at our disposal... we won't use any third stack to get the job done...(although using a third stack would make it easier....but will cost more space...)

#include<iostream>
#include<stack> 
using namespace std;

stack<int> reverse(stack<int> s, stack<int> s2)
{
    if(s.size()==1)
    {
        return s;
    }

    int x= s.top();
    s.pop();
    s = reverse(s,s2);
    int n= s.size();
    for (int i = 0; i < n; i++)
    {
        s2.push(s.top());
        s.pop();
    }
    s.push(x);
    for (int i = 0; i < n; i++)
    {
        s.push(s2.top());
        s2.pop();
    }

    return s;
}

int main(){

    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    stack <int> s2;

    s = reverse(s,s2);          // THIS CODE IS REVERSING THE STACK!!!.. IF U COMMENT OUT THIS LINE...THE 
                                // FOLLOWING "WHILE LOOP" WILL PRINT IN OPPOSITE ORDER...
                                // SO WE SUCCESSFULLY REVERSED OUR STACK USING ONLY ONE EXTRA STACK!!

    while(s.size() != 0)
    {
        cout<< s.top() <<endl;
        s.pop();
    }

    return 0;
}