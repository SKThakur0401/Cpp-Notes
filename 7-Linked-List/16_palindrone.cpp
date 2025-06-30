// TO CHECK WHETHER A LINKED LIST IS PALINDRONE OR NOT

// WE CREATED A FUNCTION CALLED "reverse" in last file.... which can reverse a linked list.

// METHOD 1> MAKE AN ARRAY...CORRESPONDING TO THE LINKED LIST AND CHECK IF ITS PALINDRONE OR NOT   (CON: SPACE COMPLEXITY OF ORDER "O(n)")
 
// METHOD 2> MAKE A DITTO COPY OF THE LINKED LIST AND APPLY "reverse" FUNCTION ON IT... AND NOW CHECK IF EACH AND EVERY ELEMENT OF BOTH THE ACTUAL AND THE COPY WHICH WAS REVERSED ARE SAME OR NOT... (CON: SPACE COMPLEXITY OF ORDER "O(n)")

// METHOD 3> FIND "LENGTH" OF "LL" AND THEN COMPARE the "i_th" element with the "len-i-1_th" element if they are same in all cases.. then its palindrone.... (CON: EXPENSIVE TIME COMPLEXITY : O(n^2)    )

// METHOD 4>  WHICH WE R GOING TO CODE HERE.... TAKE SECOND HALF OF THE LINKED LIST..AND SEPARATE IT...THEN REVESE THE SECOND PART .... NOW, IF FIRST AND SECOND PART ARE IDENTICAL..THEN "LL" IS A PALINDRONE ELSE NOT         TIME COMLEXITY = "O(n)"     Space complexity = "O(1)"

#include<iostream>
#include "Node.cpp"
using namespace std;


node* takeInput()
{
    int data; cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1)
    {
        node* newNode = new node(data);
        if(head== NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}

void print (node* head)
{
    node* temp= head;
    while(temp != NULL)
    {
        cout<< temp->data <<"  ";
        temp= temp->next;
    }
    cout <<endl;
}

node* reverse(node* head)       //THIS CODE WHEN USED...WILL REVERSE THE LINKED-LIST ITSELF
{
    node* previous =NULL;
    node* current =head;
    node* nex;
    while(current != NULL)
    {
        nex= current->next;
        current->next = previous;
        previous= current;
        current= nex;
    }
    head= previous;
    return head;
}


int len(node* head)
{
    node* tail = head;
    int len=1;
    while (tail->next != NULL)
    {
        tail= tail->next;
        len++;
    }
    return len;
}


bool checkPal(node* head)
{
    node* temp =head;
    int l = len(head);
    int half = l/2;
    for (int i = 0; i < half-1; i++)
    {
        temp=temp->next;
    }
    node* head2 =temp->next;
    temp->next= NULL;

    head2 = reverse(head2);
    node* t1= head;
    node* t2= head2;
    while(t1 != NULL  && t2 != NULL)
    {
        if(t1->data != t2->data){return false;}
        t1=t1->next;
        t2=t2->next;
    }
    return true;
}


int main(){

    node* head= takeInput();
    if(checkPal(head)){cout<< "Yes!!! a palindrone :)" <<endl;}
    else
    {
        cout<< "No!! not a palindrone :(" <<endl;
    }
    
    return 0;
}