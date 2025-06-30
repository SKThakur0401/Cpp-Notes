#include<iostream>
using namespace std;

int pro(int a, int b){
    static int p=0;    //THIS LINE IS EXECUTED ONLY THE FIRST TIME THE FUNCTION IS CALLED....AFTER THAT,,, IF THIS FUNCTION IS CALLED,this line will be ignored and  "p=p+1" will be EXECUTED,, INCREASING THE VALUE OF "p" EACH TIME THE FUNCTION IS CALLED...(NO MATTER FOR WHAT ARGUMENTS "a , b")
    //NOTE:  INITIATE THE VALUE OF "p" in the same line...(like I initiated "0")....otherwise after every function call it will initiate the value of "p"
    p=p+1;
    return a*b +p;
}
 


int main(){
    int x,y;
    cout<<"Enter nums : ";
    cin>>x>>y;
    cout<<"Special product is : "<<pro(x,y)<<endl;          //p=1
    cout<<"Special product is : "<<pro(x,y)<<endl;          //p=2
    cout<<"Special product is : "<<pro(x,y)<<endl;
    cout<<"Special product is : "<<pro(x,y)<<endl;          //p=4
    cout<<"Special product is : "<<pro(x+1,y+1)<<endl;      //p=5
    cout<<"Special product is : "<<pro(x+1,y+1)<<endl;      //p=6
    cout<<"Special product is : "<<pro(x+1,y+1)<<endl;      //p=7
    cout<<"Special product is : "<<pro(x+1,y+1)<<endl;      //AND SO ON.... VALUES OF "p" will keep on increasing each time the function is called, no matter what the arguments are
    cout<<"Special product is : "<<pro(x+1,y+1)<<endl;
    cout<<"Special product is : "<<pro(x+1,y+1)<<endl;
    cout<<"Special product is : "<<pro(x+1,y+1)<<endl;
    cout<<"Special product is : "<<pro(x+1,y+1)<<endl;

}