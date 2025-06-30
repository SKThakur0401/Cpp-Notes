//SWITCH STATEMENT

#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"Enter ur age : ";
    cin>>x;
    switch(x){
        case 4:         // THE VALUE NEXT TO "case" is the expected value of "x" for which this case will activate
        cout<<"U are too young for this!!!"<<endl;
        break;         //WE PUT BREAK HERE BCOZ IT'S A SWITCH..... IT WILL ASSUME ALL THE 'FOLLOWING' CASES AS TRUE IF WE DON'T PUT A BREAK, BREAK STOPS THE LOOP THEN AND THERE
        case 18:
        cout<<"U are of the right age :)"<<endl;
        case 150:
        cout<<"U are too old for this :("<<endl;
        default:      //EXECUTES FOR ANY VALUE OF "x".... but if the break has been pressed... then it can't work just like any other case :)
        cout<<"fk life bitches!!!"<<endl;
    }
    return 0;
}