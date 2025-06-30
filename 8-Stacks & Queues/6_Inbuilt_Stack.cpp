// HERE, WE ARE GOING TO USE THE "INBUILT" CLASS FOR "STACK"  ... IT IS VERY SIMILAR TO THE STACK WE MADE .... HERE WE ARE GOING TO STUDY ABOUT THE DIFFERENCES AND SIMILARITES BETWEEN OUR "STACK" AND THIS INBUILT "STACK" CLASS

// CALLING INBUILT STACK IS EASY... "#include<stack>"
// THE INBUILT STACK USES TEMPLATE DATA-TYPE... SO U HAVE TO EXPLICITLY MENTION WHICH DATA TYPE U WANT THE STACK TO BE OF...

#include<iostream>
#include<stack>
using namespace std;


int main(){

    stack<int> p1;             // U CAN CHANGE AND RUN THE CODE FOR "int" "double" etc..
    p1.push(100);
    p1.push(101);
    p1.push(102);
    p1.push(103);
    p1.push(104);

    cout<< p1.top() <<endl;     // SO THE INBUILT STACK'S  "TOP" IS SAME AS OUR STACK'S

    p1.pop();                   // THIS IS DIFFERENT!!!     THE BUILT IN "pop" is of 
    p1.pop();                   // "void" data type... and does not return anything
                                // remember to 'NOT' use "cout" with the inbuilt "pop" function.... it will give error!!
    
    cout<< p1.top() <<endl;

    cout<< p1.empty() <<endl;   // THIS IS SAME AS OURS.... ONLY DIFFERENCE IS IT'S NAME 
                                // "empty()" and our's name was "isEmpty()"

    cout<< p1.size() <<endl;    // SAME AS OURS....


    return 0;
}