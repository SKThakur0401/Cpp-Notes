// ----RECURSION----

#include<iostream>
using namespace std;

int f(int x){   //FACTORIAL FUNCTION USING RECURSION
    if(x==0){
        return 1;
    }
    else{return x* f(x-1) ;}
} 

int fibo(int n){        //FIBONACCI SERIES "nth term" FUNCTION
    if(n==0 || n==1){
        return 1;
    }
    else{return fibo(n-1)+ fibo(n-2) ;}
}

int main(){
    cout<<f(3)<<endl;


    for(int i=0;i<10;i++){
        cout<<fibo(i)<<endl;
    }

    return 0;
}


