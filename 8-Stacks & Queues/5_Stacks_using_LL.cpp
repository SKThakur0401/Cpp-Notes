// TRY TO WRITE THIS COMPLETELY ON YOUR OWN...(NOT THAT EASY A CODE)
// HERE, WE ARE GOING TO MAKE A STACK USING LINKED-LIST...WE ARE GOING TO MAKE A "GENERAL STACK" WHICH CAN STORE ALL KINDS OF DATA-TYPES... AND SO, WE ARE GOING TO DO IT USING "TEMPLATES" :)

// NOTE: IF WE ARE USING TEMPLATES.... WE NEED TO DEFINE TEMPLATE BEFORE MAKING EACH CLASS....LIKE I HAVE DONE BEFORE MAKING "node" and "stack" classes...

// SINCE WE HAVE MADE OUR "node" class using "template" ... we need to everywhere make sure to write that we are using a template data type.... and for that we have to write "node<T>" everywhere instead of "node"

// e.g.1   "node* newNode= new node(element)"   ---->  "node<T>* newNode= new node<T>(element)"
// e.g.2   "node* next"   -----> "node<T>* next"

#include<iostream>
using namespace std;

template <typename T>
class node
{
    public:
    T data;
    node<T>* next;
    node(T data)
    {
        this->data=data;
        next= NULL;
    }
};

template <typename T>
class stack
{
    node<T>* head;
    int size;
    
    public:
    stack()
    {
        size=0;
        head=NULL;
    }
    void push(T element)
    {
        node<T>* newNode= new node<T>(element);       // NOTE: THIS CODE WILL ALSO HANDLE THE CASE OF 
        newNode->next= head;                          // ENTERING THE FIRST ELEMENT IN THE STACK,
        head=newNode;                                 // WHERE THE HEAD IS EQUAL TO "NULL"
        size++;
    }

    T top(){return head->data;}

    T pop()
    {
        if(head== NULL){cout<< "Stack Empty!!!" <<endl;return 0;}

        node<T>* a= head;
        head=head->next;
        T ans= a->data;
        delete [] a;
        size--;
        return ans;
    }
    int getSize(){return size;}

    bool isEmpty(){return size==0;}
};

int main(){

    stack <char> p1;
    p1.push(69);
    p1.push(70);
    p1.push(71);
    p1.push(72);
    cout<< p1.top() <<endl;
    cout<< p1.pop() <<endl;
    cout<< p1.pop() <<endl;
    cout<< p1.pop() <<endl;
    cout<< p1.pop() <<endl;
    cout<< p1.pop() <<endl;
    cout<< p1.pop() <<endl;
    cout<< p1.getSize() <<endl;
    cout<< p1.isEmpty() <<endl;
    
    return 0;
}