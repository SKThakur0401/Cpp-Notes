// HERE WE ARE GOING TO KNOW THE NAMES OF VARIOUS FUNCTIONS IN THE "INBUILT QUEUE"
// IT'S VERY SIMILAR TO INBUILT STACK... IT CAN TAKE ANY DATA-TYPE COZ OF TEMPLATES

// queue <int> q;

// "q.enqueue()" --->  "q.push()"
// "q.dequeue()" --->  "q.pop()"        // pop is of "void" data-type... so it doesn't return anything..                                          just pops out the first element...

// "q.front()"  --->  "q.front()"       // same as our "front" function :)
// "q.getSize"  --->  "q.size()"        // except for name...same as our function

// "q.empty()"  // same as our function :)


// NOTE: THE INBUILT "QUEUE" USES FUNCTION NAMES LIKE "PUSH,POP,SIZE,EMPTY" WHICH ARE EXACTLY SAME IN CASE OF STACKS....  THE ONLY DIFFERENCE IS...IN STACKS WE HAD "TOP" FUNCTION TO PRINT THE TOP ELEMENT....HERE WE HAVE "FRONT" FUNCTION TO PRINT THE ELEMENT IN FRONT :)

#include<iostream>
#include<queue>
using namespace std;


int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();                // ALWAYS REMEMBER!!! NEVER TRY TO "cout" the inbuilt "pop" function...its of 
                            // void data-type.. and will give error!
    q.pop();

    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    cout<< q.front() <<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout<< q.size() <<endl;
    cout<< q.empty() <<endl;
    

    return 0;
}