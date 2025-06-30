// CHECK OUT "CN-13" FIRST


#include<iostream>
using namespace std;

void swap(int a, int b){  //ITS A USELESS FUNCTION,,, WON'T DO ANYTHING
    int temp;
    temp =a;
    a=b;
    b=temp;
}
 
void swapPtr1(int *a,int *b){       //SO THIS FUNCTION TAKES BOTH POINTERS AS PARAMETERS :)
    int x,y;
    x=*a;
    y=*b;
    *a=y;
    *b=x;
} 



void swapPtr2(int *a, int *b){       //SAME AS "swapPtr1" ....with 1 extra variable rather than 2 ;)
    int temp;
    temp= *a;
    *a=*b;              //THIS MEANS "value at address of a = value at address of b"...THEREFORE VALUE OF "b" WILL BE STORED AT ADDRESS OF "a"

    *b=temp;            //AND TEMP IS HOLDING VALUE OF "a",,, AND VALUE AT ADDRESS OF "b" =  "temp" ....so b will be equal to a and a will be equal to b...due to change in values at their original addresses
}



void swapByReferenceValue(int &x , int &y){         //THIS IS CALLED "call by reference variable"........"int &x"  is pointing to the required variable and therefore this code is working :)
    int temp=x;
    x=y;
    y=temp;
}




int main(){
    int a,b;
    int apple= 9;
    cout<<&apple<<endl;
    cout<<"Enter value of a : ";
    cin>> a;
    cout<<"Enter value of b : ";
    cin>> b;
    swap(a,b);
    cout<<"Value of a is : "<<a<<endl;
    cout<<"Value of b is : "<<b<<endl;
    swapByReferenceValue(a,b);
    cout<<"Value of a is : "<<a<<endl;
    cout<<"Value of b is : "<<b<<endl;



    int p=1,q=99,r;                 //USING A FUNCTION,,, SIMILAR TO "swap" within main.....and guess what.... it works !!!
    r=p;
    p=q;
    q=r;
    cout<<"Value of p is :"<<p<<endl;           //VALUES ARE REPLACED!!
    cout<<"Value of q is :"<<q<<endl;
    cout<<"testing : "<<(int)p<<endl;


    return 0;
}