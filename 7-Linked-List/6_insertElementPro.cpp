#include<iostream>
#include "Node.cpp"
using namespace std;
 
node* takeInput()
{
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;
    while(data != -1)
    {
        node* newNode = new node(data);
        if(head == NULL)
        {
            head= newNode;
            tail= newNode;
        }

        else
        {
            tail->next = newNode;
            tail= tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(node * head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout <<endl;
}

node* insert(int index, int element, node* head)        //this time we have return type as "node*" bcoz 
                                                // we are going to return head...since we r going to change the value of head to handle the "0th" index case.
                                                // now since we r returning head...we can make changes to the "head" in main function by making it equal to the output of this insert function
{
    if(index==0)
    {
        node* newNode = new node(element);
        newNode->next = head;
        head= newNode;
        return head;
    }

    else
    {
        node* temp = head;
        int i=0;
        while (i< index-1       &&      temp !=NULL)    // temp != NULL criteria is there to avoid case
        {                                               // where user enters an index..like "100" or 
                                // something that's not present in our "LL" in that case the previous file would have given "error" ... so we r basically doing error handling....it will now ignore the element if u enter some stupid index
            temp= temp->next;
            i++;
        }
        if(temp != NULL)
        {
        node* newNode = new node(element);
        newNode->next = temp->next;
        temp->next = newNode;
        }
        return head;            //In this case we did not make any changes in the head :)
    }
    
}




int main(){

    node * head = takeInput();
    print(head);

    head =insert(0,69,head);
    print(head);                // SO, WE SUCCESSFULLY INSERTED "69" ON THE "0TH" POSITION!!!

    head =insert(88,88,head);
    print(head);                // WE SUCCESSFULLY BY-PASSED "SEGMENTATION ERROR"!!! AND DIDN'T BOTHER TO 
                                // INSERT AN ELEMENT WITH SOME STUPID INDEX
    return 0;
}