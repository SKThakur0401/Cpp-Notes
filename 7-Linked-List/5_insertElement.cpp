#include<iostream>


using namespace std;
// EITHER WRITE THIS "CLASS NODE" CODE... OR SIMPLY CALL  "  #include "Node.cpp"   "
// where, "Node.cpp" is my previously created file which contains the same code as the class below
 
class node
{
    public:
    int data;
    node* next;
    public:
    node(int da){this->data= da;}
};

node* takeInput()
{
    int data;
    cin>>data;
    node* head= NULL;
    node* tail= NULL;
    while(data != -1)
    {
        node *newNode = new node(data);
        if(head == NULL){head = newNode; tail= newNode;}
        else
        {
            tail->next=newNode;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}

void print(node * head)
{
    node* temp= head;
    while(temp != NULL)
    {
    cout<< temp->data <<" ";
    temp=temp->next;
    }
}

int index(int in, node* head)       //RETURNS ELEMENT AT THE INDEX U ASK FOR
{
    node* temp = head;
    for (int i = 0; i < in; i++)
    {
        temp=temp->next;
    }
    return temp->data;
}


void insert(int index,int element, node* head)  // INSERTS 'ELEMENT' AT THE 'INDEX' U ASK FOR... SHIFTING THE REST OF THE "LL" RIGHTWARDS
{
    node* temp = head;
    for (int i = 0; i < index-1; i++)
    {
        temp=temp->next;
    }
    // node* inprev =temp->next;            //THIS WAY IS TOTALLY CORRECT :) ...ITS JUST THAT WE R MAKING 
                                            // AN EXTRA VARIABLE "inprev" here...which costs some space :) ... we r saving on that in the code below( although its negligible space complexity difference    :)
    // node* newNode = new node(element);
    // temp->next =newNode;
    // newNode->next= inprev;

    node* newNode = new node(element);
    newNode->next = temp->next;
    temp->next = newNode;
}
// however, this code for "insertion" is imperfect... if u try to insert something at "0th" index..it will store it at "1st" index...(solve in ur mind and u will know the reason)

int main(){

    node * head= takeInput();
    insert(3,69,head);
         
    cout<< index(3,head) <<endl;
    print(head);

    return 0;
}
