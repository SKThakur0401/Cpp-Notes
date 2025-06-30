// Linked list is a "user defined data-type" created using OOPS...it helps us to store data as a sequence of nodes where each node is connected to the next node, forming a chain like structue for storage of data.



#include<iostream>
#include<cmath>
using namespace std;


class node
{
    public:
    int data;
    node *next;
    node(int data): data(data){}

    // void print(node* head)       //I tried to make print function using recursion..but it doesn't work
    // {
    //     cout<< head->data <<endl;
    //     if(head->next != NULL){print(node* (head->next));}
    // }

    void print(node* head)      //NOTE: it is just making a copy of "head" from main function...if u make changes in this "head" ... it will not affect the value of "head" in the main function.... just remember they are like     "print.head"   and   "main.head" they are not the same
    {
        node* temp = head;      // Here, we could have simply used "head" .... and not created a temporary variable (temp) .... however it is not that bad a practice...bcoz in many cases u will need to use this "temp" to traverse in the "LL" bcoz u don't want to lose ur actual head bcoz if the head points to the next element... u can never go back to the previous element :(        unless u have stored it in some other variable.... but if u r storing it in some other variable... technically that should be the "head" :)

        while(temp != NULL)
        {
            cout<< temp->data << "  ";
            temp = temp->next;
        }
        cout <<endl;
    }


};

// GENERAL IMPORTANT NOTE:      "->" THIS OPERATOR SHOULD NOT BE USED WITH NULL!!! , IT WILL GIVE "SEGMENTATION FAULT ERROR"  ... IF U WRITE "temp->next"   u ought to be sure that "temp" is not a null value!!!
// therefore, at many places/while loops we give this criteria... "while(temp != NULL)"  or  "while(temp->next != NULL)"  depending on the situation or whatever is inside the loop to avoid "segmentation fault error" :)


int main(){
    // STATICALLY
    node n1(121);
    node n2(242);
    node n3(363);
    n1.next = &n2;
    n2.next = &n3;
    node * head = &n1;      //THIS IS THE "HEAD" ...IT STORES THE ADDRESS OF "n1" or the first node
 
    n1.print(head);
    n1.print(head);

    // DYNAMICALLY
    // node * N1 = new node(11);
    // node * N2 = new node(22);
    // N1->next= N2;
    // node *HEAD = N1;

    return 0;
}