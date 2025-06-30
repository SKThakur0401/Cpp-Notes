#include<iostream>
using namespace std;

//BY USING INLINE "KEYWORD" BEFORE FUNCTION TYPE/NAME....WE ARE SUGGEST THE COMPILER THAT substitution of function body at the point of call is preferable over the usual function call mechanism.

inline int sum(int a, int b){           //AN INLINE FUNCTION IS TO BE USED WHEN A "LESS COMPLEX" FUNCTION IS BEING USED MULTIPLE TIMES IN THE CODE (like in our case, a simple sum operator is called several times)...IT REPLACES THE "sum function" in the main with the actual "code" written is "sum function"...therefore optimizing the compiling process(bcoz compiler will not have to jump from main to sum,,, in every time the function is called)   HOWEVER ITS NOT USED FOR COMPLEX FUNCTIONS BCOZ IF BULKY CODE IS REPLACED...IT PUTS A LOT OF LOAD ON THE "main"
    static int c=0;     //NOTE: ITS NOT RECOMMENDED TO USE "STATIC METHOD" IN AN ' INLINE - FUNCTION '   
    c+=1;               //ALTHOUGH, IN OUR CODE IT WORKED JUST FINE...

    return a+b+c;
} 


int main(){
    int x,y;
    cout<<"Enter two nums : ";
    cin>>x>>y;
    cout<<"Sum of nums is : "<<sum(x,y)<<endl;
    cout<<"Sum of nums is : "<<sum(x,y)<<endl;
    cout<<"Sum of nums is : "<<sum(x,y)<<endl;
    cout<<"Sum of nums is : "<<sum(x,y)<<endl;
    cout<<"Sum of nums is : "<<sum(x,y)<<endl;
    cout<<"Sum of nums is : "<<sum(x,y)<<endl;
    
    return 0;
}



