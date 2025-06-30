//                           |---SOME USES OF TERNARY OPERATOR---|


//HELPS US SAVE TIME WHILE WRITING CODE... ALTHOUGH IT'S NOT NECESSARY

#include<iostream>
#include<cmath>
using namespace std;

inline int max(int a, int b){
    return (a>b)?a:b;
}

int f(int x){                   //BASIC FACTORIAL PROGRAM USING RECURSION
    return  (x==0)? 1 : x * f(x-1);         // TERNARY OPERATOR SAVES ALOT OF TIME WHEN COMPARED TO "IF-ELSE" :)
}



int main(){
    int p=10,q=99;
    cout<< max(p,q) <<endl;

    int c = (p>=q)? p : q;       //The bigger of p and q will be stored in "c" so c == max(p,q)  :)

    cout<< "Factorial of 11 is : "<<f(11) <<endl;


    (p>q)? cout<< "p is greater than q" <<endl: cout<< "q is greater than p" <<endl;

    return 0;
}
