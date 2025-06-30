// ----LOOPS----

#include<iostream>
using namespace std;
int main(){
    for(int i=0 ; i<10 ; ++i){     // JUST LIKE IN PYTHON....(STARTING VALUE ; ENDING VALUE ; STEP<here step is not by default 1>).....HERE IT DOESN'T MATTER IF YOU DO "i++" or "++i" ....it's just the step=1.....it's the line executed after last line of loop.
        cout<<"The value of i is : "<<i<<endl;
    }
    for(int j=0; j<20;j+=3){       //HERE STEP =3
        cout<<"The value of j is : "<<j<<endl;
    }
    

    int x=5;
    while(x<9){
        cout<<"Value of \'x\' is : "<<x<<endl;
        x++;
    }
    int y=10;

    do{
        cout<<"Value of y is : "<<y<<endl;
    }while(y>100);       //HERE THE CONDITION IS "y>100" AND THE VALUE OF "y" is 10... BUT STILL THE LOOP WILL RUN ONE TIME BCOZ IT'S "DO WHILE".....IT ALWAYS RUN FOR THE FIRST TIME
}
